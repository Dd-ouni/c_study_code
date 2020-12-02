#include <iostream>
using namespace std;

class Base{
  public:
    void show() {
      cout << "Base Show" << endl;
    }
};


class Son:public Base{
  public: 
    void show() {
      cout << "Son Show" << endl;
    }
};

void test01(){
  // 继承中非静态成员的处理
  Son s;
  s.show();
  // 结果是 Son Show，就近原则
  // 那么如何打印父类的方法呢
  s.Base::show();
  // 通过属性可以访问父类，在通过作用域::访问其非静态成员方法
};

int main(void)
{
  test01();
  return 0;
}
