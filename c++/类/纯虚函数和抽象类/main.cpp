#include <iostream>
using namespace std;
/*
    纯虚函数与抽象类
    1.设置为纯虚函数类即成为抽象类
    2.抽象类的作用就是不能实例化
    3.继承抽象类的子类不重写虚函数也为抽象类

    抽象的意义，就是只提供继承重写，所以不能实例化

    纯虚析构
    1.因为父类也有东西要释放，所以纯虚析构必须声明后实现
    2.纯虚析构也会导致父类成为抽象类
*/

class Base{
    public:
        // 纯虚函数
        virtual void show() = 0;

        // 纯虚析构声明
        virtual ~Base() = 0;
};
// 纯虚析构定义(必须实现)
Base::~Base() {
    cout << "Base 纯虚析构" << endl;
}

class Son: public Base{
    public:
        void show() {
            cout << "son show" << endl;
        }

        ~Son() {
            cout << "Son 析构" << endl;
        }
};

void test01(){
    // Base b;
    // cannot declare variable 'b' to be of abstract type

    [](Base* obj) {
        obj->show();
        delete obj;
    }(new Son);
}

int main()
{
    test01();
    return 0;
}
