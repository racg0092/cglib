

#ifndef STR_H
#define STR_H

#include "allocator.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint8_t len;
  char *str;
  uint32_t capacity;
} Str;

// Creates a new string if null is passed then it creates an empty string
Str new_str(const char *str, Allocator *a);

void print_str(Str *string);
void to_upper(Str *string);

bool str_equals(Str string, const char *str);

#endif
