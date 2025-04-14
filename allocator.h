

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

typedef void *(*alloc)(size_t size);
typedef void (*free_alloc)(void *ptr);

typedef struct {
  size_t offset;
  alloc alloc;     // pointer to function [*alloc]
  free_alloc free; // takes a pointer if needed to deallocate
} Allocator;

// Sets the size of the default arena if you need to change it defaults to 5Kb
void set_arena_size(size_t size);

// TODO: decide if we are going to remove the function from the global scope
//  Returns global arena offset
size_t get_arena_offset();

// Gets a pointer to the default allocator a [fallback] allocator can be
// passed if needed
Allocator *get_default_alloc(void *fallback);

// Sets the default allocator
void set_default_alloc(Allocator *a);

Allocator *temp_alloc(void);
#endif
