#include "allocator.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint8_t len;
  char *str;
  uint32_t capacity;
} Str;

Str str_new(const char *str, Allocator *a) {
  if (!a)
    a = get_default_alloc(NULL);

  // initialized empty string
  if (!str) {
    Str string = {.len = 0, .capacity = 24};
    string.str = (char *)a->alloc(sizeof(uint8_t) * string.capacity);
    if (!string.str)
      abort();
    return string;
  }

  uint8_t len = 0;
  for (;;) {
    if (str[len] == '\0')
      break;
    len++;
  }

  Str string = {.len = len, .capacity = 24};

  string.str = (char *)a->alloc(sizeof(uint8_t) * string.capacity);
  if (!string.str) {
    abort();
  }

  memcpy(string.str, str, len + 1);

  return string;
}

// Print string to screen
void str_print(Str *string) {
  for (int i = 0; i < string->len; i++) {
    printf("%c", string->str[i]);
  }
  printf("\n");
}

// Appends [str] to [string]
void str_concat(Str *string, Str *str) {
  if (string->len >= string->capacity) {
    fprintf(stderr, "string capacity has been reached\n");
    return;
  }

  if (str->len > (string->capacity - string->len)) {
    fprintf(stderr, "appending string is bigger than the capacity\n");
    return;
  }

  memcpy(string->str + string->len, str->str, str->len);
  string->len += str->len;
}

// Appends new [char *] to string
void str_concat_from_const(Str *string, const char *str) {
  if (string->len >= string->capacity) {
    fprintf(stderr, "string capacity has been reached\n");
    return;
  }

  int strlen = 0;
  while (str[strlen] != '\0') {
    strlen++;
  }

  if (strlen > (string->capacity - string->len)) {
    fprintf(stderr, "appending string is bigger than the capacity\n");
    return;
  }
  memcpy(string->str + string->len, str, strlen);
  string->len += strlen;
}

// Tursn a [Str] into upper case
// TODO: the difference between upper case and lower case is always 32
void str_to_upper(Str *string) {}

// Compares [str] to [str1]
bool str_equals_raw(const char *str, const char *str1) {
  bool eq = true;

  int i = 0;

  while (!str && !str1) {
    if (str[i] != str1[i]) {
      eq = false;
      break;
    }
  }

  return eq;
}

bool str_equals(Str *string, const char *str) {
  bool eq = true;
  for (int i = 0; i < string->len; i++) {
    if (string->str[i] != str[i]) {
      printf("%c != %c", string->str[i], str[i]);
      eq = false;
      break;
    }
  }
  return eq;
}
