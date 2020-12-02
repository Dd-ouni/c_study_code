#include <iostream>
using namespace std;

class Base{
  public:
    Base(int age):m_age(age) {
      cout << "base 构造函数" << endl;
    }
    ~Base() {
      cout << "base 析构函数" << endl;
    }
    int m_age;
};

class Son: public Base{
  public:
    Son(int age = 10):Base(age) {
      cout << "son 构造函数" << endl;
    }
    ~Son() {
      cout << "son 析构函数" << endl;
    }
};

void test01() {
  Son s(1000);
  cout << s.m_age << endl;
  Son s;
  cout << s.m_age << endl;
  // 子类继承父类 实例化有参父类构造
  // 子类继承父类，是不继承 构造、析构、拷贝、运算符重载
}

int main()
{
  test01();
  return 0;
}
