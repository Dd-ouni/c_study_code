#include <iostream>
using namespace std;
// 常函数， 修饰this指针的指针不能修改

class Human{
  public:
   Human() {}
   void ediInfo() const {
     // this = NULL; // 这是不能被修改的
     // this的本质是  Human* const this 指针地址不能被修改
     // 常函数就是让指针的值不能修改，那么该如何添加 const？
     // void edInfo() const == const Human* const this

     // this->m_age = 12;
     // 不能修改左值

     this->m_height = 12;
     // 这样子是允许的 因为 mutable修饰符
   }

   int m_age;
   // mutable修饰的成员变量，即使在成员常函数里也可以被修改值
   mutable int m_height;
};

int main(void)
{
  
  return 0;
}
