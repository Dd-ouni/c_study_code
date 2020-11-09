#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

int main(void)
{
  LinkNode *p_link = init_link();
  insert_link(p_link, 10, 1000);
  insert_link(p_link, 11, 1000);
  delete_link(p_link, 5);
  printf("p_link = %p \n", (void *)p_link);
  print_link(p_link);
  printf("p_link = %p \n", (void *)p_link);
  destroy_list(p_link);
  printf("p_link = %p \n", (void *)p_link);
  print_link(p_link);
  return 0;
}
