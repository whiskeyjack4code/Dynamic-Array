#ifndef dynarray_h

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int capacity;
  int element_count;
  uint32_t* ints;
} IntegerList;


void init_list(IntegerList* array);
void* reallocate(void* memory, size_t old_size, size_t requested_bytes);
void add_items(IntegerList* array, uint32_t element);
void free_memory(IntegerList* array);
void empty_list(IntegerList* array);
void print_list(IntegerList* array);

#endif // !dynarray_h

