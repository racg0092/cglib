#include <arena.h>
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

Str new_str(const char *str, Arena *arena) {
  if (!arena)
    abort();

  // initialized empty string
  if (!str) {
    Str string = {.len = 0, .capacity = 24};
    string.str = (char *)arena_alloc(arena, 24, sizeof(uint8_t));
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

  Str string = {.len = len};

  string.str = (char *)arena_alloc(arena, len + 1, sizeof(uint8_t));
  if (!string.str) {
    abort();
  }

  memcpy(string.str, str, len + 1);

  return string;
}

// Print string to screen
void print_str(Str *string) {
  for (int i = 0; i < string->len; i++) {
    printf("%c", string->str[i]);
  }
  printf("\n");
}

// Tursn a [Str] into upper case
// TODO: the difference between upper case and lower case is always 32
void to_upper(Str *string) {}

bool str_equals(Str string, const char *str) {
  bool eq = true;
  for (int i = 0; i < string.len; i++) {
    if (string.str[i] != str[i]) {
      eq = false;
      break;
    }
  }
  return eq;
}
