

#ifndef CORE_H

#include <stdio.h>
#include <stdlib.h>

#define assertf(expr, msg, ...)                                                \
  if (!(expr)) {                                                               \
    printf("\n1: ");                                                           \
    printf(msg "\n", __VA_ARGS__);                                             \
    printf("2: Expression: %s\n3 File: %s\n4 Line %d\n\n", #expr, __FILE__,    \
           __LINE__);                                                          \
    abort();                                                                   \
  }

#define assert(expr, msg)                                                      \
  if (!(expr)) {                                                               \
    printf("\n1: ");                                                           \
    printf(msg "\n");                                                          \
    printf("2: Expression: %s\n3 File: %s\n4 Line %d\n\n", #expr, __FILE__,    \
           __LINE__);                                                          \
    abort();                                                                   \
  }

#define concat_inner(x, y) x##y
#define concat(x, y) concat_inner(x, y)

#define defer(func, ctx)                                                       \
  __attribute__((cleanup(run_defer), unused))                                  \
  Defer concat(_defer_, __LINE__) = {func, ctx};

typedef struct {
  void (*func)(); // function to exec
  void *ctx;      // context
} Defer;

void run_defer(Defer *d);

#endif // !CORE_H
