#include <iostream>
using namespace std;


// 1. 引用的定义必须是有效的变量
void test01() {
  //int& qA = 10;
  // 常量当然的不行的
  /*
    error: invalid initialization of non-const 
    reference of type 'int&' from an rvalue of type 'int'
  */
  // 正确定义
  int a = 10;
  int& qA = a;

  // 种种迹象类似于 指针
   // int* pA = &10;
  // error: lvalue required as unary '&' operand
}

int& retQa() {
  int a = 10;
  return a;
}

// 2. 不要引用函数类的栈变量
void test02() {
  // int& qA = []()->int&{
  //   int a = 10;
  //   return a;
  // }();  
  int& qA = retQa();
  cout << "a ：" << qA << endl;
  cout << "a ：" << qA << endl;
  cout << "a ：" << qA << endl;
  /*  lambdanim 结果
    a 锛?0
    a 锛?1
    a 锛?1
    普通函数 结果 一样
  */
}

// 3. 引用函数返回静态变量的新用法
void test03() {
  int& (*pRetQaFun)() = []()->int&{
    static int a = 10;
    return a;
  };
  int& qA = pRetQaFun();

  cout << qA << endl;
  cout << qA << endl;
  cout << qA << endl;
  // 10 10 10
  // 没错给 a的别名引用 赋值
  pRetQaFun() = 1000;
  cout << qA << endl;
  // 1000
}

int main(void)
{
  test03();
  return 0;
}
