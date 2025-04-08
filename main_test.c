#include "./arena.h"
#include "./list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  char *name;
} Man;

void testing_list() {
  Arena a;
  arena_init(&a, 1024 * 5);
  Man jon = {.id = 0, .name = "Jon Doe"};
  Man maria = {.id = 1, .name = "Maria"};

  printf("%zu\n", sizeof(Man));
  printf("%zu\n", sizeof jon);

  List list = new_list(&a, sizeof(Man));
  if (!list.items) {
    fprintf(stderr, "out of memory\n");
    abort();
  }

  printf("list pointer %p\n", list.items);

  list_add_items(list, sizeof(Man), &jon, &maria, NULL);
  printf("len %d\n", list.len);

  Man *first = (Man *)get_list_item(&list, 0, sizeof(Man));
  Man *second = (Man *)get_list_item(&list, 1, sizeof(Man));

  printf("from first %p\n", first);
  printf("from second %p\n", second);

  printf("id=%d, name=%s\n", first->id, first->name);
  printf("id=%d, name=%s\n", second->id, second->name);

  arena_free(&a);
}

int main() { testing_list(); }
