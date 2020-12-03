#include <iostream>
using namespace std;

// 逻辑异或的作用

// 0000 1001 ^ 0010 1000 = 0010 0001
// 逻辑异或 的作用就是针对数据的 二进制位进行位运算
// 0与1得到1 否则 0
// 逻辑异或主要是用来加密的，2个值进行异或会得到一个新值
// 这个新值就和那2个值形成三角关系
/*
    a ^ b = ab;
    ab ^ a = b;
    ab ^ b = a;
    那么这种三角关系就可以用来检查值是否被修改
*/

using UNINT = unsigned int;

void test01()
{
    UNINT have_do{2000};
    UNINT use_do{60000};
    UNINT rel_do{have_do ^ use_do};

    cout << "修改已有钻石" << endl;
    cin >> have_do;
    cout << "修改已有钻石是" << have_do << " 保存的记录却是" << (rel_do ^ use_do);
}

int main()
{
    test01();
    return 0;
}
