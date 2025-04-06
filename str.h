

#ifndef STR_H
#define STR_H

#include <arena.h>
#include <stdbool.h>

typedef struct {
  uint8_t len;
  char *str;
  uint32_t capacity;
} Str;

Str new_str(const char *str, Arena *arena);

void print_str(Str *string);
void to_upper(Str *string);

bool str_equals(Str string, const char *str);

#endif
