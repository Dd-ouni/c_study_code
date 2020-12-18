#include <iostream>
using namespace std;

template <typename IncTmpType>
IncTmpType inc(IncTmpType a, IncTmpType b) {
        cout << typeid(a).name() << endl;
    return a + b;
}

// 函数模板例外，用来处理指针
template <>
int* inc(int* a, int* b) {
        cout << typeid(a).name() << endl;
    return *a > *b? a : b;
}

int inc(int a, int b){
    cout << "int 类型" << endl;
    return a + b;
}

void test01() {
    // 1. 自动检测类型使用   
    int a{109}, b{150}; 
    cout << inc(a, b) << endl;

    // 2.必须是同类型
    // cout << inc(200.0f, 300) << endl;
    cout << inc(200.0f, (float)300) << endl;

    // 3.函数重载优先级高于函数模板
    // 1.的打印是 int 类型

}
int main()
{
    test01();
    return 0;
}
