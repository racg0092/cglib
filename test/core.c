#include "../core.h"
#include "../os.h"
#include "../str.h"
#include "tests.h"
#include <stdio.h>

int main() {

  assert(str_equals_raw(OS, "linux"), "expected OS to be linux");

  assert(str_equals_raw(ARCH, "arm"), "expected ARCH to be arm");

  test_completed(__FILE__);
}
