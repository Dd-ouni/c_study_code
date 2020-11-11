#include <cstdio>
// c++ 局部const

void test01() {

  // 1. 尝试修改 局部下 静态的 变量

  const int value2 = 1000;
  // value2 = 3000;
  // 直接修改不通过
  int* pInt = (int*) &value2;
  *pInt = 3000;
  printf("const int value2 = %d \n", value2);
  // 没有强检测情况下通过编译，运行通过，修改值得失败 还是 1000
  // 总结 C++下局部const 依旧为伪静态变量，不是在静态区
  // 但是为什么修改失败呢
  // C++ 下对 const 取地址空间的时候
  /*
    会对const 变量生成一个模板
    int temp = value2;
    int* pInt = &temp; 
    这里取的是temp的地址， 你修改的也是temp的值
    打印的时候还是value是局部const 有一个键值对的表
    key      value
    value2   1000
    取值是通过 temp 找到键值对里的 value2
  */

  // 总结C++ 下可以拿局部const 当做 静态变量使用


  // 2. C++ 静态变量可以声明动态数组
  int arr[value2] = { 0 };


  int arrNum = 3;
  // int arr2[arrNum] = { 0 };
  // 当然这是不允许的非静态变量
 
}

int main(void)
{

  test01();
  /* code */
  return 0;
}