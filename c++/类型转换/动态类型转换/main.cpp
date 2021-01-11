#include <iostream>
using namespace std;

// 动态类型转换
/*
    非常严格的类型转换
    1.内置类型转换不支持
    2.向下转换不支持
    3.向上转换和多态支持
*/

class Base{};
class Son:public Base{};
class Other{};

void test01(){
  // 内置类型转换 错误
  // char ch{'a'};
  // double db = dynamic_cast<double>(ch);  
  // dynamic_cast 中的类型必须是指向完整类类型或 void * 的指针或引用

  // 非继承关系类型转换 错误
  // Other* ptrO{new Other};
  // Base* ptrB{dynamic_cast<Base*>(ptrO)}
  // 运行时 dynamic_cast 的操作数必须包含多态类类型

  // 向上转换 支持
  Base* ptrB{dynamic_cast<Base*>(new Son)};

  // 向下转换 不支持
  // Son* ptrS{dynamic_cast<Son*>(new Base)};
}

int main()
{
  test01();
  return 0;
}
