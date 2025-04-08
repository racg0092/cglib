#include "./arena.h"
#include "./list.c"
#include <stdio.h>

typedef struct {
  int id;
  char *name;
} Man;

int main() {
  Arena a;
  arena_init(&a, 1024 * 5);
  Man jon = {.id = 0, .name = "Jon Doe"};

  printf("%zu\n", sizeof(Man));
  printf("%zu\n", sizeof jon);

  List list = new_list(&a, sizeof(Man));

  list_add_item(list, jon);

  Man *first = (Man *)get_list_item(&list, 0);

  printf("id=%d, name=%s\n", first->id, first->name);

  arena_free(&a);
}
