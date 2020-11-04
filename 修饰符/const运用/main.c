#include<stdio.h>
#include<string.h>
// const 的运用

void test01(){
  // 修饰变量： 不能修改。却能间接修改
  const int num = 10;
  // num = 20;
  // 1. error: assignment of read-only variable 'num' 只读
  // 2. error: variable 'num' set but not used  不能设置
  printf("const num = %d \n", num);

  // int* pInt = NULL;
  // pInt = &num;
  // assignment discards 'const' qualifier from pointer target type
  // 严格模式下也是不能间接修改的
  // *pInt = 2000;
  // printf("const num = %d \n", num);
}


void test02() {
  // 修饰指针
  int num = 100;
  const int* pInt = &num;
  // *pInt = 2000;
  //  assignment of read-only location '*pInt'
  // 修饰符在指针左边的时候 指针指向空间无法修改
  pInt = NULL;
  printf("pInt = %p \n", pInt);  // pInt = 00000000

  int* const pInt2 = &num;
  *pInt2 = 200;
  printf("num = %d \n", num); // 200
  // pInt2 = NULL;
  // assignment of read-only variable 'pInt2'
  // 修饰符在指针右边的时候 指针的地址无法修改
}

typedef struct {
  char name[12];
  int age;
} Human;

void printfHuman(Human* pHuman) {
  strcpy(pHuman->name, "bobo");
  pHuman->age = 20;
  printf("My name is %s, age is %d \n", pHuman->name, pHuman->age);
  // 本来只是为了打印它的，却无意修改类
}
void printfHuman2(const Human* const pHuman) {
  // strcpy(pHuman->name, "bobo");
  // passing argument 1 of 'strcpy' discards 'const' qualifier from pointer target type
  // pHuman->age = 20;
  printf("My name is %s, age is %d \n", pHuman->name, pHuman->age);
}

void test03() {
  // 修饰指针之指针传递 防止修改
  // 参数传递分为 值传递 和 指针传递
  // 值传递对消耗比较大，指针传递比较优化但是会不小心修改到指针的空间的内容
  Human lucy = { "lucy", 12 };
  printfHuman2(&lucy);
  printf("My name is %s, age is %d \n", lucy.name, lucy.age);
}

int main()
{
  test03();
  return 0;
}
