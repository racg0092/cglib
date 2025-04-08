

#ifndef LIST_H
#define LIST_H

#include "./arena.h"

#define list_add_item(l, i) add_to_list(&l, &i, sizeof i)

typedef struct {
  void *items;

  int len;
  int cap;
} List;

List new_list(Arena *arena, size_t tsize);

void *get_list_item(List *l, int index);

static void add_to_list(List *l, void *data, size_t s);

#endif // !LIST_H
