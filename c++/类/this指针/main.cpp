#include <iostream>
using namespace std;
// this指针 指向 调用成员函数的对象

class Human{
  public:
    int age;
    Human(int age){
      // 1.this指针的作用之：区分参数与成员
      // 当参数名与成员变量名重叠的时候
      // 使用匿名变量对象指针this
      this->age = age;

      // 假设
      //age = age;
      // 那么 该对象的age并没有被赋值
    }

    // 2. this指针的作用之：链式编程
    // 思考 cout << "hello " << "world" << endl;
    // 如何实现，通过改变修饰符行为 cout << val == cout(val)
    // 那么其实 std::cout("hello ").cout("world ").cout(endl)

    Human& incCurAge(Human& h) {
      this->age += h.age;
      return *this;
    }

    // 3. 链式编程的疑惑
    // 1. 返回值类型为什么是 Human& 不是 Human
    // 解答 return Human 是值传递，值传递什么特性、
    // 编译器会重新赋值一份，类的赋值就是拷贝构造

    // 2. return *this； 为什么需要解引用
    // this是指针，引用传递必须是对象本身，通过*取到对象本身

    // 3. this->age == Human* h->age
    // 解释this 是对象指针，其实就是和声明类指针一样个道理
    
};


void test01() {
  Human lucy(10);
  cout << lucy.age << endl;
  Human bobo(20);
  lucy.incCurAge(bobo).incCurAge(bobo);
  // 50
  cout << lucy.age << endl;
}

int main()
{
  test01();
  return 0;
}
