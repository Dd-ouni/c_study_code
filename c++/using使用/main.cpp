#include <iostream>
using namespace std;
// using 声明 与 using 编译

// 1. using 声明
namespace GAME1{
  int value = 1;
}
void test01() {


  using GAME1::value;
  // 这就是 using声明，在这个作用域里，直接使用value

  // int value = 2;
  // error: redeclaration
  // 当 using声明的作用域里面 有就近原则出现时，即会产生错误
  // 多次声明，所以使用 using声明的时候不要 声明同样的变量名
  cout << value << endl;
}

void test02() {
  using namespace GAME1;
  // 这就是 using编译，打开GAME1空间
  // 在这作用域里都免声明直接使用空间成员

  int value = 2;
  // 当 using编译的作用域里面 有就近原则出现时 取就近声明
  // 即打印结果为 2，所以using声明与using编译还是有区别的
  cout << value << endl;
}


int main(void)
{
  test02();
  return 0;
}
