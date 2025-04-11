

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
Str str_new(const char *str, Allocator *a);

void str_print(Str *string);

/*void str_to_upper(Str *string);*/

// Compares [string] to [str] returns true if equal
bool str_equals(Str string, const char *str);

// Appends new [char *] to [string]
void str_concat_from_const(Str *string, const char *str);

// Appends [str] to [string]
void str_concat(Str *string, Str *str);

// Compares c strings [str] to [str1]
bool str_equals_raw(const char *str, const char *str1);

#endif
