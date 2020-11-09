#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数指针
int add(int val) {
  return val + val;
}

int mul(int val) {
  return val * val;
}

int sub(int val) {
  return val - val;
}

// 函数指针变量
void test01() {
  int (*pAddVar)(int);
  // 声明函数指针 == 变量 ==， （必须掌握）
  // int add(int val) => int (*函数指针名)(int)
  pAddVar = add;
  // 赋值
  printf("%d \n", pAddVar(10));
  // 调用方法1
  printf("%d \n", (*pAddVar)(20));
  // 调用方法2
}

// 函数类型声明
void test02() {
  typedef int (addType)(int);
  // 定义出 == 函数类型 ==
  addType* pAdd = add;
  // 声明函数类型指针变量

  printf("%d \n", pAdd(20));
  // 调用方法1
  printf("%d \n", (*pAdd)(40));
  // 调用方法2 
}

// 函数指针类型声明
void test03() {
  typedef int (*pAddType)(int);
  // 定义出 == 函数指针类型 ==
  pAddType pAdd = add;
  printf("%d \n", pAdd(30));
  // 调用方法1
  printf("%d \n", (*pAdd)(50));
  // 调用方法2 
}

// 函数数组指针变量
void test04() {
  int (*p_func_array[3])(int) = { add, mul, sub };
  // 这里的重点是在 (*函数指针变量名[])

  size_t len = sizeof(p_func_array) / sizeof(*(p_func_array + 0));
  for (size_t i = 0; i < len; i++)
  {
    printf("%d \n", p_func_array[i](20));
    printf("%d \n", (*p_func_array[i])(40));
  }
}

// 函数数值指针类似
void test05() {
  typedef int(*P_FUNC_ARR_TYPE[])(int);

  P_FUNC_ARR_TYPE pFuncArr = { add, mul, sub };
  size_t len = sizeof(pFuncArr) / sizeof(*(pFuncArr + 0));
  // printf("%d \n", len);
  for (size_t i = 0; i < len; i++)
  {
    printf("%d \n", pFuncArr[i](50));
    printf("%d \n", (*pFuncArr[i])(100));
  }
}

int main(void)
{
  test05();
  return 0;
}
