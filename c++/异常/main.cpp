#include <iostream>
#include <string>
using namespace std;

/*
  C++异常处理
  1. C语言捕获异常的缺陷
  答：C语言捕获异常是靠返回值,如果 return -1,
  那么 10 / -10 也是异常吗？

  2. C++捕获异常关键字 
  答：try catch throw ... 是捕获没声明的其他异常
  try{ throw MyException(); } 
  catch(MyException e){ e.printErr() } 
  catch(...){ // 其他异常 }

  3. 支持自定义异常捕获

  4. 如果不想处理异常，可以继续抛出throw

  5. 如果异常没有被处理 程序调用terminate函数，终止程序
*/

class MyException{
  public:
    void printErr(){
      cout << "MyException" << endl;
    }
};

int myDiv(int a, int b) {
  // 0 不能被作为除数

  if(b == 0) {
    throw string("字符串异常");
  }

  return a / b;
}


void test01() {
  try
  {
    cout << myDiv(10, 0) << endl;
  }
  catch(MyException e) {
    e.printErr();
  }
  catch(int)
  {
    cout << "int 类型异常" << endl;  
  }
  
}

int main()
{

  try
  {
    test01();
  }
  catch(...)
  {
    cout << "其他类型异常" << endl;
  }
  
  return 0;
}
