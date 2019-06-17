#include "std.h"

struct Set {
  i32 elements_size;
  i32 size;
  i32* elements;
};

typedef struct Set* Set;

Set set_new(i32 size);

bool set_is_empty(Set);

bool set_contains(Set , i32);

void set_add(Set , i32);