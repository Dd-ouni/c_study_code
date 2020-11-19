#include <iostream>
using namespace std;

class Human{
  public: 
    Human(){ cout << "无参构造" << endl; };
    Human(char* name){ cout << "有参构造" << endl; };
    Human(const Human& human){ cout << "拷贝构造" << endl; };
    ~Human(){ cout << "析构" << endl; };
};

// 1. new 在堆空间开辟空间
// delete 释放堆空间

void test01() {
  Human* h = new Human;
  // 无参构造
  Human* h1 = new Human((char*)"lucy");
  // 有偿构造
  Human* h2 = new Human(*h);
  // 拷贝构造
  // 这里要注意的，经常会写成 new Human(h);
  // 这样子是错的，我这里是需要一个引用

  delete h;
  delete h1;
  delete h2;
}

// 2. 不要给void* 赋值 堆空间
void test02() {
  void* h = new Human;
  delete h;
  // warning: deleting 'void*' is undefined
  // 这样子是无法释放的

  void* h2 = new Human;
  delete (Human*)h2;
  // 当然这样子是可以释放的
}

// 3. new 数组和基础类型
void test03() {
  char* name = new char;
  name = (char*)"1234";
  cout << name << endl;

  int* num = new int;
  *num = 12;
  cout << *num << endl;

  Human* h = new Human;

  int* num2 = new int[5];

  // 栈区类数组
  Human h_arr[2] = { Human(), Human() };

  // 
  Human* h_arr2 = new Human[5];

  delete [] name;
  // 经过char* 可以释放[]，不会无限循环
  // 下面两个是无限循环
  delete num;
  delete h;
  delete [] num2;
  delete [] h_arr2;
  // delete [] 原理是  [5] obj, obj, obj, obj, obj
  // 当表达式识别到[]的时候会在[5] 然后循环释放
  // delete 可以不带[] 释放数组，但是只会释放第一个
}


int main(void)
{
  test03();
  return 0;
}
