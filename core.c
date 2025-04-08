
#define assert(expr, msg)                                                      \
  if (!(expr)) {                                                               \
    printf("\n1 ");                                                            \
    printf(msg "\n");                                                          \
    printf("2 Expression: %s\n3 File: %s\n4 Line %d\n\n", #expr, __FILE__,     \
           __LINE__);                                                          \
    abort();                                                                   \
  }
