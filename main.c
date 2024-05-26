#include <stdint.h>
#include <stdio.h>
#include "dynarray.h"

int main(){
  
  ByteList list;
  init_list(&list);
 
  int int_value = 10;
  add_items(&list, &int_value, sizeof(int_value));
  int_value = 20;
  add_items(&list, &int_value, sizeof(int_value));
  int_value = 83;
  add_items(&list, &int_value, sizeof(int_value));

  print_list_as_int(&list);

  empty_list(&list);

  float float_value = 255.0f;
  add_items(&list, &float_value, sizeof(float_value));
  float_value = 5.440f;
  add_items(&list, &float_value, sizeof(float_value));
  float_value = 40.23f;
  add_items(&list, &float_value, sizeof(float_value));

  print_list_as_float(&list);

  empty_list(&list);

  free_memory(&list);

  return 0;
}
