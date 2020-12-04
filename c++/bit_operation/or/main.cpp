#include <iostream>
#include <bitset>
using namespace std;

// 或位运算 |
/*
    二组二进制， 位对比，1方为1的是否即为1
    通常用来对一组开关做开启的
    0000 0000 | 0001 0000 = 0001 0000 
*/

void test01()
{
    using UNINT = unsigned int;
    UNINT sw{0b00000000000000000000000000000000};
    cout << bitset<32>(sw) << endl;
    cout << "请输入开启32个灯里面的第几个" << endl;

    UNINT openIndex = 0;
    cin >> openIndex;

    UNINT opBit = 0x1;
    sw |= (opBit <<= (openIndex - 1));
    // 结合位移运算符 实现打开第几个开关
    cout << bitset<32>(sw) << endl;
}

int main()
{
    system("clear");
    test01();
    return 0;
}
