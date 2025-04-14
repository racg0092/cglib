#include "./arena.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef void *(*alloc)(size_t size);
typedef void (*free_alloc)(void *ptr);

static int ARENA_INIT_SIZE = 1024 * 5;

typedef struct {
  size_t offset;
  alloc alloc;
  free_alloc free;
} Allocator;

// TODO: and realloc to grow arena

static Arena arena = {};
static Arena *_arena = &arena;
static Allocator default_temp = {};

size_t get_arena_offset() { return _arena->offset; }

// Sets the arena size for the default allocator
static void *default_alloc(size_t size) {
  if (_arena->size == 0) {
    arena_init(_arena, ARENA_INIT_SIZE);
  }
  return arena_alloc(_arena, size, size);
}

static void default_free(void *ptr) {
  if (ptr) {
    free(ptr);
    return;
  }

  // TODO: maybe the allocator is not using an arena need to handle this better
  if (!_arena) {
    fprintf(stderr, "error default arena was never initiated");
    abort();
  }
  arena_free(_arena);
}

static void temp_alloc_free(void *ptr) {
  if (ptr) {
    free(ptr);
    return;
  }

  // TODO: maybe the allocator is not using an arena need to handle this better
  if (!_arena) {
    fprintf(stderr, "error default arena was never initiated");
    abort();
  }

  arena_reset_to(_arena, default_temp.offset);
}

Allocator *temp_alloc(void) {
  // NOTE: global variable not too sure about the side effects of this and what
  // errors it could cause
  default_temp.offset = _arena->offset;
  default_temp.alloc = default_alloc;
  default_temp.free = temp_alloc_free;
  return &default_temp;
}

static Allocator _d_alloc = {
    .alloc = default_alloc,
    .free = default_free,
};
static Allocator *_alloc = &_d_alloc;

// Sets the size of the default arena if you need to change it defaults to 5Kb
void set_arena_size(size_t size) { ARENA_INIT_SIZE = size; }

// Gets a pointer to the default allocator a [fallback] allocator can be passed
// if needed
Allocator *get_default_alloc(void *fallback) {
  return fallback ? (Allocator *)fallback : _alloc;
}

// Sets the default allocator
void set_default_alloc(Allocator *a) {
  if (a && a->alloc && a->free) {
    _alloc = a;
  }
}
