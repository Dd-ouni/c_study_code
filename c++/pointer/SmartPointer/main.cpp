#include <iostream>
#include <memory>
using namespace std;

void test01() {
  // 唯一智能指针
  /*
    1.防止重复引用导致的重复释放
  */
 
  unique_ptr<int> upInt{ new int{1000} };
  cout << upInt.get() << " " << *upInt << endl;
  //清除唯一指针
  upInt.reset();

  // upIntNull.get() 为空的即0的 不能取值即 *upIntNull
  unique_ptr<int> upIntNull;
  upIntNull = nullptr;
  cout << upIntNull.get() << endl;
  upIntNull.reset();

  
  cout << "=====" << endl;
}

int main()
{
  system("cls");
  test01();
  return 0;
}
