#include <iostream>
using namespace std;


// 质数，只能被 1或者自身整除的数
// 质数的作用？比如互联网通讯
// a 和 b 通讯， 没有加密的通信，可以有c截取修改a 和 b的通讯
// 为了让通讯更加安全，通过算法对 a 和 b 的消息进行加密（非对称加密）
// 非对称加密有2把钥匙，1把钥匙用来加密，1把钥匙用来解密
// 就算c截取到消息也无济于事
// 非对称加密就是通过 质数实现，具体百度

// 打印1 - 1000内的质数
// 版本1：
// 1 、 2、 3排除不为质数



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
