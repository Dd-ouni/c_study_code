#include <iostream>
using namespace std;

class Human{
  public:
    static int H_TOTAL;
    int num;
    static int GET_TOTAL(){
      // this->num;
      // error
      return H_TOTAL;
    }
};

int Human::H_TOTAL = 0;

// 1.静态成员函数不能访问非静态成员变量
// 2.非静态成员函数能访问静态成员变量
// 3.静态成员函数使用
void test01() {
  // 对象使用
    Human h;
    cout << h.GET_TOTAL() << endl;
  // 类使用
    cout << Human::GET_TOTAL() << endl;
}

int main(void) {
  cout << "hello world" << endl;
  test01();
  return 0;
}