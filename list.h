

#ifndef LIST_H
#define LIST_H

#include "./arena.h"
#include "allocator.h"

// Adds i item to the list l
#define list_add_item(l, i) add_to_list(&l, &i, sizeof i)
#define list_add_items(l, s, ...)                                              \
  add_items_to_list(&l, (void *[]){__VA_ARGS__}, s)

typedef struct {
  void *items;

  int len;
  int cap;
} List;

// Creates a new list
List new_list(size_t tsize, Allocator *a);

// Gets a list item l based on the index
void *get_list_item(List *l, int index, size_t size);

// Add a list itam to l
void add_to_list(List *l, void *data, size_t s);

// Add mulitple items [data] to the list [l]
void add_items_to_list(List *l, void *data[], size_t s);

#endif // !LIST_H
