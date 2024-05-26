#include "dynarray.h"
#include <stdint.h>
#include <string.h>

void init_list(ByteList* array){
  array->element_count = 0;
  array->capacity = 0;
  array->byte = NULL;
}

void* reallocate(void* memory, size_t old_size, size_t requested_bytes){
  if(requested_bytes == 0) {
    free(memory);
    return NULL;
  }

  void* mem = realloc(memory, requested_bytes);
  return mem;
}

void add_items(ByteList* array, void* element, size_t element_len) {
  
  if(array->capacity < array->element_count + element_len) {
    size_t old_size = array->capacity;
    array->capacity = ((old_size) < 8 ? 8 : (old_size * 2));
    array->byte = (unsigned char *) reallocate(array->byte, old_size, array->capacity);
  }
  
  memcpy(array->byte + array->element_count, element, element_len);
  array->element_count += element_len;
}

void free_memory(ByteList* array){
  if(array->byte == NULL){
    return;
  }
  reallocate(array->byte, array->capacity, 0);
  init_list(array);
}

void print_list_as_int(ByteList* array){
  printf("[");
  for(int i = 0; i < array->element_count; i += sizeof(uint32_t)){
    uint32_t value;

    memcpy(&value, &array->byte[i], sizeof(uint32_t));

    if(i + sizeof(uint32_t) >= array->element_count){
      printf("%u", value);
    } else {
      printf("%u,", value);
    }
  }
  printf("]\n");
}

void print_list_as_float(ByteList* array){
  printf("[");
  for(int i = 0; i < array->element_count; i += sizeof(float)){
    float value;

    memcpy(&value, &array->byte[i], sizeof(float));

    if(i + sizeof(uint32_t) >= array->element_count){
      printf("%.2f", value);
    } else {
      printf("%.2f,", value);
    }
  }
  printf("]\n");
}

void empty_list(ByteList* array){
  if(array->element_count == 0){
    printf("List already empty!");
  } else {
    free_memory(array);
  }
}
