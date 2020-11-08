#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体浅拷贝问题

typedef struct{
  char name[64];
  int age;
} Human;

void test01() {
  Human lucy = { "lucy", 18 };
  Human bobo = { "bobo", 27 };

  // 直接拷贝，也叫浅拷贝
  lucy = bobo;

  printf("lucy.name = %s, lucy.age = %d \n", lucy.name, lucy.age);
  printf("bobo.name = %s, bobo.age = %d \n", bobo.name, bobo.age);
}

typedef struct 
{
  char* name;
  int age;
} Human2;

void test02() {
  Human2 lucy;
  lucy.name = malloc(12 * sizeof(char));
  strcpy(lucy.name, "lucy");
  lucy.age = 18;

  Human2 bobo;
  bobo.name = malloc(24 * sizeof(char));
  strcpy(bobo.name, "bobo");
  bobo.age = 27;

  // 浅拷贝，只是拷贝属性的值， 这里的浅拷贝只会拷贝到bobo.name 的地址
  lucy = bobo;

  printf("lucy.name = %s, lucy.age = %d \n", lucy.name, lucy.age);
  printf("bobo.name = %s, bobo.age = %d \n", bobo.name, bobo.age);

  // 那么这时候使用释放堆空间，重复释放就会报错
  if(lucy.name != NULL){
    printf("lucy.name %d \n", (int) &lucy.name);
    free(lucy.name);
    lucy.name = NULL;
  }

  if(bobo.name != NULL){
    printf("bobo.name %d \n", (int) &bobo.name);
    free(bobo.name);
    bobo.name = NULL;
  }
}
// 然而并没有问题，曰了狗了 
// 解答： 结构体是值传递，但结构体里面有一个元素是指针访问的，理解这句话吗

int main()
{
  test02();
  return 0;
}
