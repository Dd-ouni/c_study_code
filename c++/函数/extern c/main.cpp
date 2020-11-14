#include <iostream>
using namespace std;
// C++下使用C 语言
#include "test.h"
/*  解决方法1
    1.注释 #include "test.h"
    2.通过 extern "C" 函数声明;
    来告诉编译以后面的方式不用用C++的方式来链接
*/
// extern "C" void show();

void test01(){
  show();
  // show();
  // 识别不到函数 undefined reference to `show()'
  // C++ 无法识别原因是 函数重载
}

int main(void)
{
  test01();
  
  return 0;
}
