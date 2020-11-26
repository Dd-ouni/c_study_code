#include <iostream>
using namespace std;


class MyInt{
  friend ostream& operator<<(ostream& cout, MyInt myInt);
  public:
    MyInt():m_val(0){};
    MyInt(int val):m_val(val){};
    // 前置++
    MyInt& operator++(){
      ++this->m_val;
      return *this;
    };
    // 后置++ 后置加加通过展位符声明
    MyInt operator++(int) {
      MyInt temp = *this;
      ++this->m_val;
      return temp;
    }

    // 为什么 前置是返回引用 后置是值传返回呢？
    // 前置++ 返回自身引用是为了实现 ++(++a)
    // 如果不返回自身 cout << ++(++a)  是会得到2，但是 本质的a 却是 1

    // 后置++ 返回的模板，因为后置++是在当前语句运行完毕(不一样)之后才修改值
    // 所以不能返回自身，而是可以拷贝的模板，模板又在对象成员函数，栈变量函数结束后销毁
  private:
    int m_val;
};

ostream& operator<<(ostream& cout, MyInt myInt){
  cout << myInt.m_val;
  return cout;
}

void test01() {
  // 实现
  int a = 0;
  cout << ++(++a) << endl; // 2
  cout << a++ << endl; // 2
  cout << a << endl; // 3

  // 前置++ 重载
  MyInt iVal;
  cout << ++(++iVal) << endl;
  // cout << iVal++ << endl;
  cout << iVal << endl;
};

int main(void) {
  test01();

  return 0;
}