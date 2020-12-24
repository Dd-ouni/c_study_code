#include <iostream>
using namespace std;
// 成员方法静态多态
// 成员方法动态多态
using callFunc = void (*)();


class F{
    public:
        void show();
};


class S: public F{
    public:
        void show();
};

void F::show() {
    cout << "F show" << endl;
}
void S::show() {
    cout << "S show" << endl;
}

// 静态成员方法多态
// 原理就是编译器生成的函数模板
// 函数重载
template<typename T>
void show(T& obj){
    obj.show();
}
 

int main()
{
    callFunc test01 = [](){
        F fa;
        S sa;
        show(fa);
        show(sa);
    };

    cout << "test01 addr " << test01 << endl;

    callFunc test02 = [](){
        S sa;
        F fa;
        sa.show();
        fa.show();
    };

    test02();
    
    return 0;
}
