#include "dynarray.h"

void init_list(IntegerList* array){
  array->element_count = 0;
  array->capacity = 0;
  array->ints = NULL;
}

void* reallocate(void* memory, size_t old_size, size_t requested_bytes){
  if(requested_bytes == 0) {
    free(memory);
    return NULL;
  }

  void* mem = realloc(memory, requested_bytes);
  return mem;
}

void add_items(IntegerList* array, uint32_t element) {
  
  if(array->capacity < array->element_count + 1) {
    int old_size = array->capacity;
    array->capacity = ((old_size) < 8 ? 8 : (old_size * 2));
    array->ints = (uint32_t *) reallocate(array->ints, sizeof(uint32_t) * old_size, sizeof(uint32_t) * array->capacity);
  }

  array->ints[array->element_count] = element;
  array->element_count++;
}

void free_memory(IntegerList* array){
  if(array->ints == NULL){
    return;
  }
  reallocate(array->ints, array->capacity, 0);
  init_list(array);
}

void print_list(IntegerList* array){
  printf("[");
  for(int i = 0; i < array->element_count; i++){
    if(i == array->element_count - 1){
      printf("%d", array->ints[i]);
    } else {
      printf("%d,", array->ints[i]);
    }
  }
  printf("]\n");
}

void empty_list(IntegerList* array){
  if(array->element_count == 0){
    printf("List already empty!");
  } else {
    free_memory(array);
  }
}
