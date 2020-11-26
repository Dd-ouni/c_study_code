#include <iostream>
using namespace std;

// 重构函数运算符 实现对象函数
class Test{
  public:
    int operator()(int a, int b) {
      return a + b;
    }
};

void test01() {
  Test t;
  cout << t(10, 20) << endl;
  cout << Test()(20, 20) << endl;
}

int main()
{

  test01();
  return 0;
}
