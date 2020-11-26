#include <iostream>
using namespace std;

// 智能指针
// 智能指针是什么？
// 自动释放堆区
// 因为程序经常忘记释放

class Human{
  public:
    Human(int age):age(age){}
    ~Human() {
      cout << "Human destory fun" << endl;
    }
    int showAge() {
      return this->age;
    }
  private:
    int age;
};

class SmartPointer{
  public:
    SmartPointer(Human* human):human(human){
    }
    ~SmartPointer(){
      if(human != NULL){
        delete human;
        human = NULL;
      }
      cout << "SmartPointer destory fun" << endl;
    }
    Human* operator->(){
      return this->human;
    }
    Human& operator*(){
      return *this->human;
    }
  private:
    Human* human;
};

void test01() {
  // 这也是实现了自动析构，但是我们要的不仅仅如此
  SmartPointer sp(new Human(18));

  // 我们还想通过
  // sp->showAge  (*sp).showAge
  // 那么这时候就要重载运算-> 和 *
  cout << sp->showAge() << endl;
  // -> 必须是指针，所以重载->返回的是指针
  // 这里要注意的是 sp->-> 被编译器优化为 ->
  cout << (*sp).showAge() << endl;
  // . 必须是普通变量， 重载*, 要得到的是 human&对象  必须是引用
  // 如果是值传递相相当于智能指针内存储的不是原本保存的指针
}

int main(void)
{
  test01();
  return 0;
}
