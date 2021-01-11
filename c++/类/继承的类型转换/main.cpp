#include <iostream>
using namespace std;

class Animal{
public:
  int x{5};
};


class Cat : public Animal{
public:
  int y{10};
};


void test01(){
  // 向上类型转换

  Animal* ac = new Cat;

  cout << ac->x << endl;

  // 向下类型转换 
  Cat* ca = (Cat*) new Animal;
  cout << ca->y << endl;

}

int main()
{
  test01();
  return 0;
}
