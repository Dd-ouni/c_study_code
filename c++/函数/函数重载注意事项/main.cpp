#include <iostream>
using namespace std;

// 1. 编译器对重载的选择
void fun1(int& a) {  // int& a = a;
  cout << "int& a" << endl; 
}
void fun1(const int& a) { // const int& a = 10;
  cout << "const int& a" << endl; 
}
// void fun1(int a){}
// 如果出现 引用加传值的重载就不行了
// 结论有重载有引用就不要用传值重载
void test01() { 
  fun1(10);
  // const int& a

  int a = 10;
  fun1(a);
  // int& a

  /*
      注释： fun1(10); 和 void fun1(int& a)
      结果： const int& a
      编译在有选择的时候会选择最优的。没选择将就
  */
}

// 2.使用默认参数就不要使用重载
void fun2(int a) {}
void fun2(int a, int b = 10){}

void test02() {
  // fun2(10);
  // error: call of overloaded 'fun2(int)' is ambiguous
  // 二一性
}

int main(void)
{
  test02();
  return 0;
}
