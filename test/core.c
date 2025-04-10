#include "../core.h"
#include <stdio.h>

int main() {

  assert(1 == 2, "expected ", NULL);

  printf("%s: ALL TEST PASSED\n", __FILE__);
}
