#ifndef dynarray_h

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int capacity;
  int element_count;
  unsigned char* byte;
} ByteList;


void init_list(ByteList* array);
void* reallocate(void* memory, size_t old_size, size_t requested_bytes);
void add_items(ByteList* array, void* element, size_t len);
void free_memory(ByteList* array);
void empty_list(ByteList* array);
void print_list_as_int(ByteList* array);
void print_list_as_float(ByteList* array);

#endif // !dynarray_h

