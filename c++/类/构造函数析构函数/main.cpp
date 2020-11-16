#include <iostream>
#include <cstring>
using namespace std;
class Human{
public:
  void show();
  Human(const char*, int);
  ~Human();
protected:
  char name[12];
  int age;
};

void Human::show() {
  cout << "my name is :" << this->name << ". age is :" << this->age << endl;
}

Human::Human(const char* name, int age = 1){
  strcpy(this->name, name);
  this->age = age;
}

Human::~Human() {
  cout << this->name << " ~Human" << endl;
}

void test01() {
  Human lucy("lucy", 12);
  lucy.show();
}

int main(void)
{
  test01();
  return 0;
}
