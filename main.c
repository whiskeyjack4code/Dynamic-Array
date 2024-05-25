#include <stdio.h>
#include "dynarray.h"

int main(){

  IntegerList list;
  init_list(&list);
  print_list(&list);
  add_items(&list, 10);
  add_items(&list, 20);
  add_items(&list, 30);

  print_list(&list);
  empty_list(&list);
  print_list(&list);

  free_memory(&list);


  return 0;
}
