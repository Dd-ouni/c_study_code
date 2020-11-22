#include <iostream>
using namespace std;


// 常对象
// 1.只能调用常函数
// 2.不允许修改成员变量
class Human{
  public:
    Human() {}
    void showInfo() const {
      cout << "常函数" << endl; 
    }
    void edInfo() {
      this->m_age = 12;
      cout << "普通函数" << endl;
    }
    int m_age;
    mutable int m_height;
};

void test01() {
  const Human lucy;
 
  //  不允许修改普通成员变量
  // lucy.m_age = 12;

  lucy.m_height = 20;
  // 允许修改mutable 成员变量

  // 不允许调用普通函数
  // lucy.edInfo();
  // 为了不然普通函数内随便修改成员变量

  // 允许调用常函数
  lucy.showInfo();
}

int main()
{
  test01();
  return 0;
}
