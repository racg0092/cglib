#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint8_t *base; // Start of the memory block
  size_t size;   // Total size of the arena
  size_t offset; // Current offset for allocation

  uint8_t cangrow;
} Arena;

// Initializes the memory arena
void arena_init(Arena *arena, size_t size) {
  // cast the void* return typq of malloc
  // to uint8_t for bitwise operation (for pointer arithmatic)
  arena->base = (uint8_t *)malloc(size);
  if (!arena->base) {
    fprintf(stderr, "memory allocation failed\n");
    exit(1);
  }
  arena->size = size;
  arena->offset = 0; // set the save location to position 0
}

// Initializes the given pointer to the nearest alignment boundary
static size_t align_forward(size_t offset, size_t alignment) {
  size_t reminder = offset % alignment;
  if (reminder == 0)
    return offset;
  return offset + (alignment - reminder);
}

// Allocates memore in the arena
void *arena_alloc(Arena *arena, size_t size, size_t alignment) {
  size_t aligned_offset = align_forward(arena->offset, alignment);

  if (aligned_offset + size > arena->size) {
    // TODO: grow if configuration set to true
    return NULL; // out of memory
  }

  void *ptr = arena->base + aligned_offset;
  arena->offset = aligned_offset + size;

  return ptr;
}

void arena_reset(Arena *arena) { arena->offset = 0; }

// Sets the offset of the arena to the specific offset passed in
void arena_reset_to(Arena *a, size_t offset) { a->offset = offset; }

void arena_free(Arena *arena) {
  // zero randomizer to overwrite data
  memset(arena->base, 0xA5, arena->size);
  free(arena->base);

  arena->base = NULL;
  arena->size = 0;
  arena->offset = 0;
}
