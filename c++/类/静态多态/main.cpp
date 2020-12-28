#include <iostream>
using namespace std;
/*
  静态多态，就是编译的时候决定调用地址
  也叫静态联编，比如函数重载，函数模板
*/

class Animal{
  public:
   void show() {
     cout << "动物show" << endl;
   }
};

class Person:public Animal{
  public:
   void show() {
     cout << "人show" << endl;
   }
};

// void show(Animal& obj) {
//   obj.show();
// }
// 编译的时候就决定地址是指向Animal类
// 多态是要实现自动指向
// 函数重载或者函数模板就是编译器实现静态多态
template<typename T>
void show(T& obj){
  obj.show();
}

void test01() {
  Person p;
  show(p);
  // 结果是动物show，使用模板函数后是 人show
  Animal a;
  show(a);
  // 结果是动物show
  // 函数重载也能实现静态多态
   
}

int main()
{
  test01();
  return 0;
}
