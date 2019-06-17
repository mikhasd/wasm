#include "std.h"

struct List {
  i32 elements_size;
  i32 size;
  i32* elements;
};

typedef struct List* List;

List list_new(i32);

void list_free(List);

bool list_is_empty(List);

bool list_contains(List ,i32);

void list_add(List, i32);

i32 list_get(List, i32);