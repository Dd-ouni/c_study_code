#include <iostream>
#include <cstring>
using namespace std;

// 重载复制运算符
// 解决浅拷贝问题 清除堆段错误问题

class MyStr
{
    ostream &operator<<(ostream &cout, MyStr &str);

public:
    MyStr(char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(name, this->name);
    }

private:
    char *name;
};

ostream &operator<<(ostream &cout, MyStr &str)
{
    cout << str return cout;
}

void test01()
{
    // 实现运算符拷贝结果
    int a = 10;
    int b = 20;
    int c = a = b;
    cout << "a " << a << " b " << b << " c " << c << endl;
    // a 20 b 20 c 20
}

int main()
{
    test01();
    return 0;
}
