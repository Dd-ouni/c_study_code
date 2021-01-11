#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


/*
  系统异常的使用
  1.系统异常的实现：多态实现
  2.系统异常的用法：在于捕获而不是抛出异常
  注解：因为我们也不知道抛出什么，一般由系统抛出我们捕获
  3.必须导入头文件 stdexcept
  4.接收(基类)引用 catch(exception& e)
  5.抛出(派生类)实例 throw out_of_range
  注解：一般都是由系统抛出
*/

void doWork() {

  try
  {
    []()->void{
      throw out_of_range("溢出异常" + to_string(__LINE__));
    }();
  }
  catch(exception& e)
  {
    cout << e.what() << endl;
  }
}


int main()
{
  doWork();
  return 0;
}
