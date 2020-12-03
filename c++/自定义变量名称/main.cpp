#include <iostream>
using namespace std;
typedef long long LL;
void test01()
{
    // c++ 通过using 这种写法比较符合 变量定义写法
    // 并且提示比较友好
    using INT_TYPE = int;
    INT_TYPE i = 20;
    cout << i << endl;
    LL ll = 3000;
    cout << ll << endl;
    int a{10};
    cout << a << endl;
}

int main()
{
    test01();
    return 0;
}
