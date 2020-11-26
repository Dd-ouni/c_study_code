#include <iostream>
using namespace std;

// 运算符重载
// 对自定义类型的 运算符进行重载

class Pos{
  // 利用友元，让重载运算符能访问私有变量
  friend Pos operator-(Pos& a, Pos& b);
  friend ostream& operator<<(ostream& cout, Pos& pos);
  private:
    int m_x;
    int m_y;

  public:
    Pos(int x, int y):m_x(x), m_y(y){};
    Pos():m_x(0),m_y(0){};
    int getX(){ return m_x; };
    int getY(){ return m_y; };
    Pos operator+(Pos&);
};

// 两个pos 对象相加得出新 pos对象
// 类成员函数 运算符重载
Pos Pos::operator+(Pos& pos) {
  Pos retPos;
  retPos.m_x = this->m_x + pos.m_x;
  retPos.m_y = this->m_y + pos.m_y;
  return retPos;
}

// 两个pos 对象相减得出新 pos对象
// 全局运算符重载
Pos operator-(Pos& a, Pos& b) {
  Pos retPos;
  retPos.m_x = a.m_x - b.m_x;
  retPos.m_y = a.m_y - b.m_y;
  return retPos;
}

// 重载左移运算符cout 自定义打印 Pos
ostream& operator<<(ostream& cout, Pos& pos) {
  cout << " x:" << pos.m_x << " y:" << pos.m_y; 
  return cout;
}

void test01() {
  Pos a(20, 30);
  Pos b(30, 20);
  Pos addPos = a + b;
  Pos subPos = a - b;
  cout << "addPos" << addPos << " subPos" << subPos << endl;
}

int main(void)
{
  test01();

  return 0;
}
