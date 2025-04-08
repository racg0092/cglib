#include "../core.h"
#include "../str.h"
#include <stdio.h>

void test_string_concat() {
  Str name = str_new("Richard", NULL);
  assert(name.len == 7, "expected len to be 7");

  str_concat_from_const(&name, " Chapman");
  assert(name.len == 15, "expected len to be 15");

  assert(str_equals(name, "Richard Chapman"),
         "Expected strings to be the same");

  Str lname = str_new(" Gomez", NULL);
  str_concat(&name, &lname);
  assert(name.len == 21, "expected len to be 21");

  assert(str_equals(name, "Richard Chapman Gomez"),
         "Expected strings to be the same");

  printf("%s: all tests passed\n", __FILE__);
}

int main() {
  Allocator *a = get_default_alloc(NULL);

  test_string_concat();

  a->free(NULL);
}
