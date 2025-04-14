#include "../core.h"
#include "../os.h"
#include "../str.h"
#include "tests.h"
#include <stdio.h>

void dd(void *ctx) { printf("DEFER 1\n"); }
void dd1(void *ctx) { printf("DEFER 2\n"); }

int main() {

  defer(dd, NULL);
  defer(dd1, NULL);

  printf("I PRINT BEFORE DEFER");

  assert(str_equals_raw(OS, "linux"), "expected OS to be linux");

  assert(str_equals_raw(ARCH, "arm"), "expected ARCH to be arm");

  test_completed(__FILE__);
}
