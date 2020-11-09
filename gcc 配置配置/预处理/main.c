#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
// 条件编译示例之版本控制
#if DEBUG
  void printfInfo() {
    printf("DEBUG MODE \n");
  }
#else
  void printfInfo() {
    printf("NOT DEBUG MODE \n");
  }
# endif

// 特殊宏之错误信息定位打印

void test01(int* num) {
  if(num == NULL) {
    printf("error file = %s, line = %d \n", __FILE__, __LINE__);
  }
}


int main(void)
{
  printfInfo();
  test01(NULL);
  return 0;
}
