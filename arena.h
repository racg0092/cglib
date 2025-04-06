#ifndef ARENA_H
#define ARENA_H

#include <inttypes.h>
#include <stddef.h>

typedef struct {
  uint8_t *base; // Start of the memory block
  size_t size;   // Total size of the arena
  size_t offset; // Current offset for allocation
} Arena;

// Initializes arena
void arena_init(Arena *arena, size_t size);

// Allocates to the arena
void *arena_alloc(Arena *arena, size_t size, size_t allignment);

// Reset the arean to offset to the beginning
void arena_reset(Arena *arena);

// Frees all memory in the arena
void arena_free(Arena *arena);

#endif
