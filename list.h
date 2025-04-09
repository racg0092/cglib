

#ifndef LIST_H
#define LIST_H

#include "./arena.h"
#include "allocator.h"

// Adds i item to the list l
#define list_add_item(l, i) list_add_to(&l, &i, sizeof i)
#define list_add_items(l, s, ...)                                              \
  list_add_multiple(&l, (void *[]){__VA_ARGS__}, s)

typedef struct {
  void *items;

  int len;
  int cap;
} List;

// Creates a new list
List list_new(size_t tsize, Allocator *a);

// Gets a list item l based on the index
void *list_get_item(List *l, int index, size_t size);

// Add a list itam to l
void list_add_to(List *l, void *data, size_t s);

// Add mulitple items [data] to the list [l]
void list_add_multiple(List *l, void *data[], size_t s);

#endif // !LIST_H
