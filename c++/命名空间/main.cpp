#include <iostream>
#include "game1.h"
#include "game2.h"

// 1.命名空间解决冲突问题
void test01() {
  // attack(); 
  /* 
    game1.h
    void attack() { // game1 attack }
    game2.h
    void attack() { // game2 attack }
    
    error: redefinition of 重复定义错
  */

 // 修改后
 using GAME2::attack;
 GAME1::attack();
 attack();

 /*
    namespace GAME1{
      void attack() {
        cout << "game1 attack" << endl;
      }
    }
    namespace GAME2{
      void attack() {
        cout << "game2 attack" << endl;
      }
    }
 */
}

// 2. 命名空间存放内容
namespace A{
  int value = 'a';
  char ch = 'a';
  typedef struct{
    char name[12];
    int age;
  }Human;
  class HumanCls{};
  void printfA() {
    using A::Human;
    Human lucy = { "lucy", 18 }; 
    std::cout << A::value << " - " << A::ch <<  " - " << lucy.name << std::endl;
  }
}

void test02() {
  using namespace A;
  printfA();
  // 97 - a - lucy
}

// 3. 命名空间只能在全局作用域定义
// void test03{
//   namespace B{}
// }

// 4. 嵌套 -》命名空间
namespace B{
  int m_b = 100;
  namespace C{
    int m_c = 1000;
  }
}

void test04() {
  std::cout << B::m_b << " - " << B::C::m_c << std::endl;
  // 100 - 1000
}

// 5. 命名空间可以添加新成员， 就是重复定义一个命名空间不是覆盖，是合并

namespace B{
  int m_bb = 200;
}

void test05() {
  using B::m_b;
  using B::m_bb;
  std::cout << m_b + m_bb << std::endl;
  // 300
}

// 6. 匿名 -》命名空间
namespace {
  int m_cc = 1100; // 匿名添加 static
  int m_dd = 1200;
}
void test06(){
  using namespace std;
  cout << m_cc << ::m_dd << endl; 
  // 匿名命名空间 其实就是全局变量
  // 11001200
}

// 7. 别名 -》 命名空间
namespace D {
  int m_d = 2000;
}

void test07(){
  namespace d = D;
  std::cout << d::m_d << std::endl;
}

int main(void)
{
  test07();
  return 0;
}
