#include <iostream>
using namespace std;


// 空指针调用成员函数
class Human{
  public:
    Human(int age):m_age(age){}
    void showInfo(){
      cout << "class is Huamn" << endl;
    }
    void showAge() {
      cout << this << endl;
      if(this == NULL){
        return;
      } 
      // 教程里是使用这个判断过滤 空对象，但是依旧有地址
      // 这里测试无效依旧会打印m_age 默认初始为0
      cout << this->m_age << endl;
    }
    int m_age;
};

void test01(){
  Human lucy = NULL;
  lucy.showInfo();
  // 这个能调用
  lucy.showAge();
  // 这个调用结果 0,教程是会崩溃不允许
  // 崩溃是因为没有实例对象导致的
}

int main()
{
  test01();
  return 0;
}
