#include<stdio.h>
#include<stdlib.h>


typedef unsigned char* char_pointer;
typedef unsigned int* int_pointer;

void showCharP(char_pointer p_char, size_t len) {
  for (size_t i = 0; i < len; i++)
  {
    printf(" %.2x", p_char[i]);
  }
  printf("\n");
}

void showIntP(int_pointer p_int, size_t len){
  showCharP((char_pointer) p_int, sizeof(int) * len);
}

int main()
{
  unsigned int c = 888;
  showCharP((char_pointer) (&c), sizeof(int));
  showIntP(&c, 1);
  return 0;
}
