#include <stdio.h>
// c 语言const

const int value = 10;
// 全局变量下的const 是在静态区无法修改

void test01() {
  // 1. 尝试修改 全局下 静态区的 变量

  // int* pInt = &value;
  // warning: initialization discards 'const' qualifier from pointer target type
  // *pInt = 2000;
  // printf("const int value = %d \n", value);
  // 没有强检测情况下通过编译，运行崩溃
  // 总结 C语言下在全局区的静态修饰变量才是静态变量

  // 2. 尝试修改 局部下 静态的 变量

  const int value2 = 1000;
  // value2 = 3000;
  // 直接修改不通过
  int* pInt = &value2;
  *pInt = 3000;
  printf("const int value2 = %d \n", value2);
  // 没有强检测情况下通过编译，运行通过，并且修改值得
  // 总结 C语言下局部const 为 伪静态变量，不是在静态区

}

int main(void)
{

  test01();
  /* code */
  return 0;
}
