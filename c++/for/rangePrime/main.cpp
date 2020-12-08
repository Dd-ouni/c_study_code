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

void test01()
{
    for (size_t num = 3; num <= 1000;)
    {
    pass:
        for (size_t i = 2, max = num - 1; i < max; i++)
        {
            if ((num % i) == 0)
                goto pass;
        }
        cout << num << endl;
        ++num;
    }
}

int main()
{
    test01();
    return 0;
}
