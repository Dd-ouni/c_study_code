#include <iostream>
#include <string>
using namespace std;

// 比较运算符重载
// 通常运用于自定义类型对比
class Human{
  public:
    Human(string name, int age){
      this->m_name = name;
      this->m_age = age; 
    }
    bool operator==(Human& human) {
      return this->m_name == human.m_name && this->m_age == human.m_age;
    }
  private:
    string m_name;
    int m_age;
};

void test01() {
  Human h1("lucy", 12);
  Human h2("lucy", 12);
  if(h1 == h2) {
    cout << " h1 == h2 " << endl;
  }else{
    cout << " h1 != h2 " << endl;
  } 
}

int main(void)
{
  test01();
  return 0;
}
