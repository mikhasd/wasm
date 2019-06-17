#include "std.h"
#include "list.h"

List list_new(i32 size){
  size = size < 10 ? 10 : size;
  List list = malloc(sizeof(struct List));
  list->elements_size = size;
  list->elements = malloc(sizeof(i32) * size);
  list->size = 0;
  return list;
};

void list_free(List this){
  free(this->elements);
  free(this);
}

bool list_is_empty(List this){
  return this->size == 0;
}

void list_increase_capacity(List this){
  i32 new_size = this->size * 1.5;
  i32* new_elements = malloc(sizeof(i32) * new_size);
  for(i32 i = 0; i < this->size; i++){
    new_elements[i] = this->elements[i];
  }
  this->elements_size = new_size;  
  free(this->elements);
  this->elements = new_elements;
}

bool list_contains(List this, i32 element){
  for(i32 i = 0; i < this->size; i++){
    if(this->elements[i] == element){
      return true;
    }
  }
  return false;
}

void list_add(List this, i32 element){
  if(this->elements_size == this->size){
    list_increase_capacity(this);
  }
  this->elements[this->size++] = element;
}

i32 list_get(List this, i32 index){
  return this->elements[index];
}