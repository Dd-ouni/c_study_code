#include <iostream>
using namespace std;

/*
  异常的多态使用
  一个虚基类可以传入多种子类
  本节是异常结合多态的使用
*/


class MyException{
  public:
    virtual void printfError() = 0;
};

class NullPtrException: public MyException{
  public:
    void printfError() {
      cout << "空指针异常" << endl;
    }
};

class OutOfRangeException: public MyException{
  public:
    void printfError() {
      cout << "溢出异常" << endl;
    }  
};

void doWork(){
  // throw OutOfRangeException();
  throw NullPtrException();
}

void test01() {
  try
  {
    doWork();
  }
  catch(MyException& e)
  {
      e.printfError();
  }
}

int main()
{
  test01();
  return 0;
}
