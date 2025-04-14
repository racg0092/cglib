#include "../allocator.h"
#include "../core.h"
#include "../str.h"
#include <stddef.h>
#include <stdio.h>

int main() {
  Allocator *alloc = get_default_alloc(NULL);

  size_t initial_offset = get_arena_offset();

  Allocator *tempalloc = temp_alloc();

  Str s = str_new("Richard Chapman Gomez", tempalloc);

  str_print(&s);

  assertf(24 == get_arena_offset(), "expected %d got %zu", 24,
          get_arena_offset());

  tempalloc->free(NULL);

  assertf(get_arena_offset() == initial_offset,
          "expected offset to be %zu but got %zu", initial_offset,
          get_arena_offset());

  alloc->free(NULL);
}
