

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

typedef void *(*alloc)(size_t size);
typedef void (*free_alloc)(void *ptr);

typedef struct {
  alloc alloc;     // pointer to function [*alloc]
  free_alloc free; // takes a pointer if needed to deallocate
} Allocator;

// Sets the size of the default arena if you need to change it defaults to 5Kb
void set_arena_size(size_t size);

// Gets a pointer to the default allocator a [fallback] allocator can be passed
// if needed
Allocator *get_default_alloc(void *fallback);

// Sets the default allocator
void set_default_alloc(Allocator *a);
#endif
