#include <iostream>
#include <array>

using namespace std;

void test01()
{
    array<int, 10> cc{1000};

    cout << cc.size() << endl;

    for (int i : cc)
    {
        cout << i << endl;
    }
    cout << cc[11] << endl;
    cout << "===============" << endl;
    cout << cc.at(10) << endl;

    // array 的封装对比 原生 []

    //1. 获取长度有对象成员方法.size() 提供
    //2. 获取位置元素提供对象方.at(index) 法进行保护
}

int main()
{
    system("clear");
    test01();
    return 0;
}
