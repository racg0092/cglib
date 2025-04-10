

#ifndef CORE_H

#include <stdio.h>
#include <stdlib.h>

#define assert(expr, msg, ...)                                                 \
  if (!(expr)) {                                                               \
    printf("\n1 ");                                                            \
    printf(msg "\n", __VA_ARGS__);                                             \
    printf("2 Expression: %s\n3 File: %s\n4 Line %d\n\n", #expr, __FILE__,     \
           __LINE__);                                                          \
    abort();                                                                   \
  }

#endif // !CORE_H
