#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
  char name[12];
  int age;
} Human;


void printfInt(void* data) {
  int* d = data;
  printf("%d \n", *d);
}

void printfDou(void* data) {
  double* d = data;
  printf("%f \n", *d);
}

void printfHuman(void* data){
  Human* d = data;
  printf("name is %s, age is %d \n", d->name, d->age);
}

void myPrintf(void* data, void(* pCallback)(void*)) {
  // 函数指针作为形参，类似于定义函数指针变量
  pCallback(data);
}

void test01() {
  int num = 1000;
  myPrintf(&num, printfInt);

  double d = 3.14157;
  myPrintf(&d, printfDou);

  Human lucy = { "lucy", 18 };
  myPrintf(&lucy, printfHuman);
}

int main(void)
{
  test01();
  return 0;
}
