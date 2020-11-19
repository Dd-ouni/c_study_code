#include <iostream>
using namespace std;

class MyString{
  public:
    MyString(char*);
    explicit MyString(int);
};

MyString::MyString(char* str) {
  cout << "有参构造函数char*" << endl;
}

MyString::MyString(int len) {
  cout << "有参构造函数int" << endl;
}


// explicit 修饰符
// 用来修饰构造函数，被修饰的构造函数不能使用隐式声明定义
void test01() {
  MyString str1 = "12345";
  MyString str2(20);
  
  MyString str3 = 10; // 数值型有参构造
  // 这里是无法定义
  
}

int main(void)
{
  test01();
  return 0;
}
