#include <iostream>
using namespace std;

// c++的类型转换
/*
  静态类型转换 static_cast<目标类型>(目标变量)
  1. 支持内置类型转换
  2. 支持父子类的指针引用转换
*/

class Base{};
class Son : public Base{};
class Other{};

void test01() {
  // 内置类型转换
  char ch{'a'};
  double db = static_cast<double>(ch);
  cout << db << endl;

  // 父子类指针引用转换
  // 向上转换（子转父） 安全
  Son* ptrS = new Son;
  Base* ptrB = static_cast<Base*>(ptrS);

  // 向下转换 （父转子） 不安全
  ptrS = static_cast<Son*>(ptrB);

  // 不允许没关系转换
  // Other* ptrO = static_cast<Other*>(ptrS);
  // 类型转无效

}

int main()
{
  test01();
  return 0;
}
