#include <iostream>
using namespace std;

class F {
public:
    F() {
        cout << "F 构造函数" << endl;
        cout << this << endl;
        this->test();
    }
    virtual F& show() {
        cout << "F show" << endl;
        return *this;
    }
    void test() {
        this->show();
    }
    virtual void autoMove(int step = 2) {
        cout << "F autoMove：" << step << endl;
    }
    virtual ~F() {
        cout << "F 析构函数" << endl;
        this->test();
    }
};


class S : public F {
public:
    S() {
        cout << "S 构造函数" << endl;
        cout << this << endl;
        this->test();
        F::show();
    }
    S& show() override final {
        cout << "S show" << endl;
        return *this;
    }

    void autoMove(int step = 3) {
        cout << "S autoMove：" << step << endl;
    }

    ~S() override final {
        cout << "S 析构函数" << endl;
        this->test();
    }
};
// 使用多态的代价
/*  1. 在构造和析构
    子类的构造顺序是由父类到子类，未构造子类的时候，调用虚函数，
    是指向父类，调用了父类的show，注意只能通过指针方式才能达到虚函数的作用
    函数结束，析构对象的时候也一样，子类析构完之后，父类调用show，
    这时候是指向父类的show
*/
/*
    2. 调用虚函数的父类版本
    有时候可能需要在子类调用父类虚函数
    F::show(); 父类::虚函数()
*/
/*
    3. 默认实参在虚函数中的错误
    S sa;
    F* fa = &sa;
    fa->autoMove();
    // 结果 S autoMove：2 父类的默认值，子类的函数
*/
/*
    4. 释放含有虚函数的子类对象
    当我们在堆开辟了一个多态子对象后，
    使用完毕delete的确实父类指针
    F* pfa = new S;
    pfa->test();
    delete pfa;
    这时候当然不会调用子类析构
    (你需要使用多态虚函数避免不了使用父类指针)
    这里的解决办法是 虚函数父类的析构 virtual ~F()
    还有的话这个问题是可以通过编译选项提示的
    使用VS是不会提示的，使用Dev会提示
*/

void test01() {
    cout << "test" << endl;
    // 问题 1 and 2
    // S sa;
    // sa.test();

    // 问题3 
    S sa;
    F* fa = &sa;
    fa->autoMove();
    // S autoMove：2

    // 问题4
    /* 
    F* pfa = new S;
    pfa->test();
    delete pfa;
    */
}

int main()
{
    [] ()->void (*)() { return test01; }()();
    return 0;
}
