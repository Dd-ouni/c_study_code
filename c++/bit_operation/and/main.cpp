#include <iostream>
#include <bitset>
using namespace std;

// 位运算 &
void test01()
{
    // 与位运算
    /*
        二进制位 都为1的是否即的出1
        如果把一连串的开关放在一组二进制串上
        00010011 0表示关，1表示开
        那么 与位运算 
            1.通常用来查看某个开关是否开着
            2.关闭某个开关

    */
    using UNINT = unsigned int;
    UNINT a = 0x2874;
    a &= 0xFF00;
    // 获取高16位的值

    cout << hex << a << endl;
}
int main()
{
    system("clear");
    test01();
    return 0;
}
