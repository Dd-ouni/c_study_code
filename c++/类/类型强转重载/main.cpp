#include <iostream>
using namespace std;


class T{
private:
    int m_val;
    short m_sh;
public:
    T(int val, short sh): m_val(val),m_sh(sh){} 
    // 是不是觉得很奇怪，重置 强转类型，要做到 隐式 转换必须
    // 类的第一个成员属性是对应的强转类型 才能做到
    // T t1{10, 20}; cout << t1 << endl;
    operator int() {
        return this->m_val;
    }
    // 可以通过 explicit operator int() { 禁止隐式转换
};

void test01() {
    T t1{10, 20};
    // cout << t1.m_val << endl; declared private here
    cout << t1 << endl;
    // 结果10
}

int main()
{
    
    test01();
    return 0;
}
