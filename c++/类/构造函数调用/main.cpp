#include <iostream>
using namespace std;
class Human{
  public:
    Human() {
      cout << "默认构造函数" << endl;
    }
    Human(int age) {
      cout << "有参构造函数" << endl;
    }
    Human(const Human& human) {
      cout << "拷贝构造函数" << endl;
      this->m_age = human.m_age;
    }
    ~Human(){
      cout << "析构函数" << endl;
    }
  protected:
    int m_age;
};


void test01() {
  // 3. 显示法
  Human human = Human();        // 显示法默认构造函数
  Human human2 = Human(10);     // 显示法有参数构造
  Human human2 = Human(human2); // 显示法拷贝构造
}

int main()
{
  test01();
  /* code */
  return 0;
}
