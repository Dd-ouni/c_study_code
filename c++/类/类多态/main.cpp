#include <iostream>
using namespace std;

// 类多态
// 父 -> 子 向下
// 子 -> 父 向上

class Animal{
    public:
        int aa{10};
};

class Person: public Animal{
    public:
        int ba{20};
};


using callFunc = void (*)();

int main()
{
    callFunc FtoS = [](){
        cout << "f to s" << endl;
        Animal fa;
        Person* pa = (Person*)&fa;
        cout << pa->aa << endl;
        // 反正严格下是不可以强转的，用指针是可以，访问的子类成员变量乱值
        // cout << pa->ba << endl; 6487764
    };
    FtoS();
    callFunc StoF = [](){
        cout << "s to f" << endl;
        Person pa;
        Animal fa = pa;
        cout << fa.aa << endl;
        // 子 转 父 不用强转 
    };
    StoF();

    return 0;
}
