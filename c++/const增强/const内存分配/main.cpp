#include <iostream>
#include <string>
using namespace std;

// 1. const局部变量什么时候会分配内存
void test01() {
  const int cn_val = 5;
  // 这样子是不会分配的，并且&修改的temp

  int val = 10;
  const int cn_val2 = val;
  // 这样子是会分配临时内存的，并且可以&修改成功
  int* pCnVal = (int*) &cn_val2;
  *pCnVal = 20;
  cout << cn_val2 << endl;
}

// 2. 对const局部变量&地址也会分配内存，临时

// 3. 对const 自定义类型也会分配内存
struct Human
{
  string name;
  int age;
};

void test02() {
  const Human lucy = { "lucy", 18 };
  // lucy.name = "ccc";
  // lucy.age = 18;
  // 这样子是不允许的
  Human* pHuman = (Human*) &lucy;
  pHuman->name = "bobo";
  pHuman->age = 18;
  cout << lucy.name << " " << lucy.age << endl;
}

// 总结就是只有在局部const 常量 定义的时候不会分配内存。


int main(void)
{
  test02();
  return 0;
}
