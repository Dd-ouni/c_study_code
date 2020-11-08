#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
int main(void)
{
  LinkNode* p_link = init_link();
  insert_link(p_link, 20, 1000);
  delete_link(p_link, 30);
  print_link(p_link);
  return 0;
}
