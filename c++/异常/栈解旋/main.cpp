#include <iostream>
using namespace std;

/*
  栈解旋
  从 try 到 throw 抛出异常前的所有栈上的对象
  都会被自动释放。释放的顺序与析构相反，这个过程叫
  栈解旋。

  obj1构造
  obj2构造
  obj2析构
  obj1析构
  抛出异常
*/

class Obj{
public:
  int x;
  static int n;
  Obj() {
    ++n;
    cout << "obj" << n << "构造" << endl;
    this->x = n;
  }
  ~Obj() {
    cout << "obj" << this->x << "析构" << endl;
  }
};
int Obj::n = 0;

void func(){
  Obj o1;
  Obj o2;
  throw 3.14;
}

void test01() {
  try
  {
    func();
  }
  catch(...)
  {
    cout << "抛出异常" << endl;
  }
  
}

int main()
{
  test01();
  return 0;
}
