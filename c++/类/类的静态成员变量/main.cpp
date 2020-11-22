#include <iostream>
using namespace std;

// 1. 静态成员是所有对象共享一个
// 2. 静态成员初始化在编译阶段
// 3. 静态成员必须初始化，在类外（不要在构造函数内）

class Human{
  public:
    static int H_TOTAL;
  private:
  // 5. 静态成员也有权限
    static int M_H_TOTAL;
};

int Human::H_TOTAL = 0;


// 4.静态成员使用的两种方式
void test01() {
  // 1.对象访问
  Human h1;
  cout << h1.H_TOTAL << endl;
  h1.H_TOTAL = 1;

  // 2.类访问
  cout << Human::H_TOTAL << endl;
}


int main(void)
{
  test01();
  return 0;
}
