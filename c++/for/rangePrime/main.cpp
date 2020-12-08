#include <iostream>
using namespace std;


void test01() {
  // 打印1 - 1000 内的质数
  // 质数 只能被 1 和 自身整除
  // 排除 1 2
/*
  for (size_t num = 3; num <= 1000; num++)
  {
    bool isPrime = true;
    for (size_t i = 2; i < num; i++)
    {
      if(num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) cout << num << endl;
  }
*/
  // 优化1
  /*
     观察规律 
      3
      5
      7
      11
      13
      17 
      19   优化1 最少 + 2  只有 奇数有可能是质数 偶数都可以被2整除

  */
  for (size_t num = 3; num <= 1000; num+=2)
  {
    bool isPrime = true;
    for (size_t i = 2; i < num; i++)
    {
      if(num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) cout << num << endl;
  } 
}

int main()
{
  test01();
  return 0;
}
