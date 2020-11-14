#include <iostream>
using namespace std;

// 内联函数

// 1.宏函数的优点与缺陷
#define MYADD(x, y) x + y
#define MYADD2(x, y) (x + y)
void test01() {
  cout << MYADD(10, 20) << endl;
  // 优点： 用空间换取时间，这里将转换成 cout << 10 + 20 << endl;
  // 这样就不用call 函数地址，传值等

  cout << MYADD(10, 20) * 20 << endl;
  // 缺点： 结果不是我们要的600 而是 410
  // 转换成 10 + 20 * 20 
  // 要解决这个问题需要 MYADD(x, y) (x + y)
  cout << MYADD2(10, 20) * 20 << endl;
  // 600

  // 注意宏函数定义格式必要严格
  // 不通过 #define MYADD (x, y) x + y
  // 通过   #define MYADD(x, y) x + y
  // 没错就是宏函数名后面多了个空格都不行
}


// 2.内联函数
// C++ 解决宏函数的缺点并且及其优点
/*
  1. 内联函数声明与定义都必须添加 修饰符 inline
  2. class类的成员方法编译器都会尝试修饰为内联函数
  3. 内联函数一般不会自己去定义，因为就算定义了得通过编译器标准
  才能成为内联函数。3.1 函数内容必须少、3.2 不能有循环 3.3 不能取地址
*/
inline int my_add(int, int);
inline int my_add(int a, int b) { return a + b; }

int main(void)
{
  test01();
  return 0;
}
