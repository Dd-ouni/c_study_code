#include <iostream>
using namespace std;


// 1.引用的基本使用
// 数据类型 &别名 = 原名;
void test01() {
  int a = 10;
  // 定义引用 
  int &b = a;

  b = 20;

  cout << "a = " << a << " b = " << b << endl;
}

// 2.引用的注意事项
void test02() {
  int a = 10;
  // int &b; 
  // error: 'b' declared as reference but not initialized
  // 引用类型不能只声明， 必须定义
  int &b = a;

  int c = 30;
  b = c;
  b = 20;
  // 这里是引用就无效了，这里是赋值了
  cout << c << endl;
  // 30
}

// 总结 
// &在右表达式的时候是取地址
// &在左表达式的时候是定义引用类型
int main(void)
{
  test02();
  return 0;
}
