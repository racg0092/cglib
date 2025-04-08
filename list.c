#include "./arena.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_add_item(l, i) add_to_list(&l, &i, sizeof i)

typedef struct {
  void *items;

  int len;
  int cap;
} List;

// Creates a new list
List new_list(Arena *arena, size_t tsize) {
  if (!arena) {
    printf("error initializing list no allocator provided. %d", __LINE__);
    abort();
  }

  List l = {.cap = 20, .len = 0};

  l.items = arena_alloc(arena, sizeof(void *) * l.cap, tsize * l.cap);

  return l;
}

void *get_list_item(List *l, int index) {
  if (index > l->len) {
    printf("error index out of range %d", __LINE__);
    abort();
  }

  void *i = (l->items + index);

  return i;
}

static void add_to_list(List *l, void *data, size_t s) {
  if (l->len >= l->cap)
    return;

  memcpy(l->items + l->len, data, s);
  l->len++;
}
