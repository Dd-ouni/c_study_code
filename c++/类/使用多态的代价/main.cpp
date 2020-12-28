#include <iostream>
using namespace std;

class F{
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
    ~F() {
        cout << "F 析构函数" << endl;
        this->test();
    }
};


class S : public F{
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
    ~S() {
        cout << "S 析构函数" << endl;
        this->test();
    }
};
// 使用多态的代价
/*  1. 初始化过程
    子类的构造顺序是由父类到子类，未构造子类的时候，调用虚函数，
    是指向父类，注意智能通过指针方式才能达到虚函数的作用
    这里有时候可能需要在子类调用父类的show F::show();
    以上就是使用多态虚函数的代价
*/
// 2. 虚析构问题

void test01() {
    cout << "test" << endl;
    // S sa;
    // sa.test();
    F* pfa = new S;
    pfa->test();
    delete pfa;
}

int main()
{
    []()->void (*)(){ return test01; }()();
    return 0;
}
