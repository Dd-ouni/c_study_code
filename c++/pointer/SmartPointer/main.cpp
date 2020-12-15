#include <iostream>
#include <memory>
using namespace std;

void test01()
{
  // 唯一智能指针
  /*
    1.防止重复引用导致的重复释放
  */

  unique_ptr<int> upInt{new int{1000}};
  cout << upInt.get() << " " << *upInt << endl;
  //清除唯一指针
  // upInt.reset();

  // upIntNull.get() 为空的即0的 不能取值即 *upIntNull
  unique_ptr<int> upIntNull;
  upIntNull = nullptr;
  cout << upIntNull.get() << endl;
  // upIntNull.reset();

  // 唯一智能指针替换
  upInt.swap(upIntNull);
  cout << upIntNull.get() << " " << *upIntNull << endl;

  unique_ptr<int[]> pIntArr{new int[5]{1, 2, 3, 4, 5}};
  // 声明数组指针
  cout << pIntArr.get() << endl;
}

int main()
{
  system("cls");
  test01();
  return 0;
}
