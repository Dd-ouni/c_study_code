#include <iostream>
using namespace std;
void test01(){
  int a = 10;
  int b = 20;
  // 值传 无法交换栈中的变量
  void (*pSwapFun)(int, int) = [](int a, int b)mutable->void{
    int temp = a;
    a = b;
    b = temp;
  };

  (*pSwapFun)(a, 10);

  cout << a << " " << b << endl;
}


void test02() {
  int a = 10;
  int b = 20;
  // 传地址方式 能交换变量，交换的是指向栈地址空间
  void (*pSwapFun)(int*, int*) = [](int* pA, int* pB)mutable->void{
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
  };

  pSwapFun(&a, &b);

  cout << a << " " << b << endl;

}


void test03() {
  int a = 10;
  int b = 20;
  
  cout << &a << endl;  // a 的地址 0x28fea4

  // 传引用方式
  void (*pSwapFun)(int&, int&) = [](int& qA, int& qB)mutable->void{
    cout << &qA << endl; // 引用qA 的地址  0x28fea4
    int temp = qA;
    *(&qA) = qB;
    qB = temp;
  };

  pSwapFun(a, b); //  ->   int& qA = a; int& qB = b; 引用的传值过程

  cout << a << " " << b << endl;

  // 总结引用是 指针的简化
}

int main(void)
{
  test03();
  return 0;
}
