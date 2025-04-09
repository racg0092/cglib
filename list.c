#include "./allocator.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *items;

  int len;
  int cap;
} List;

// Creates a new list
List list_new(size_t tsize, Allocator *_alloc) {
  if (!_alloc) {
    _alloc = get_default_alloc(NULL);
  }

  List l = {.cap = 20, .len = 0};

  l.items = _alloc->alloc(tsize * l.cap);

  return l;
}

// Get item from list
void *list_get_item(List *l, int index, size_t size) {
  // if index is bigger than len then throw error
  if (index > l->len) {
    fprintf(stderr, "error index out of range line=%d\n", __LINE__);
    abort();
  }

  void *i;

  // if index is 0 then look at the first pointer
  if (index == 0) {
    i = (l->items);
  } else {
    // if index is bigger than 0 then multiple by the size of the type to get
    // the next pointer
    // NOTE: we are dealing with void pointer so size data is not passaed along
    int pos = index * size;
    i = (l->items + pos);
  }

  return i;
}

void list_add_to(List *l, void *data, size_t size) {
  if (l->len >= l->cap) {
    // TODO: increase list space and capacity
    printf("warning: list does not have any more space, file=%s line=%d",
           __FILE__, __LINE__);
    return;
  }

  if (l->len == 0) {
    memcpy(l->items, data, size);
  } else {
    int pos = l->len * size;
    memcpy(l->items + pos, data, size);
  }

  l->len++;
}

void list_add_multiple(List *l, void *data[], size_t s) {
  int i = 0;
  for (;;) {
    void *item = data[i];
    if (!item) {
      break;
    }
    list_add_to(l, item, s);
    i++;
  }
}
