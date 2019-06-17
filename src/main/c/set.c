#include "std.h"
#include "set.h"

Set set_new(i32 size){
  size = size < 10 ? 10 : size;
  Set set = malloc(sizeof(struct Set));
  set->elements_size = size;
  set->elements = malloc(sizeof(i32) * size);
  set->size = 0;
  return set;
};

bool set_is_empty(Set this){
  return this->size == 0;
}

void set_increase_capacity(Set this){
  i32 new_size = this->size * 1.5;
  i32* new_elements = malloc(sizeof(i32) * new_size);
  for(i32 i = 0; i < this->size; i++){
    new_elements[i] = this->elements[i];
  }
  this->elements_size = new_size;  
  free(this->elements);
  this->elements = new_elements;
}

bool set_contains(Set this, i32 element){
  for(i32 i = 0; i < this->size; i++){
    if(this->elements[i] == element){
      return true;
    }
  }
  return false;
}

void set_add(Set this, i32 element){
  if(set_contains(this, element))
    return;
  if(this->elements_size == this->size){
    set_increase_capacity(this);
  }
  this->elements[this->size++] = element;
}