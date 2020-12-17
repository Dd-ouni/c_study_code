#include <iostream>
using namespace std;

void test01() {

  
  int& (*pRetQuote)() = []()->int&{
    int* retVal = new int{10};
    cout << retVal << endl;
    return *retVal;
    // 为什么要返回一个堆的空间呢
    // int& cc = *retVal; 
    // 相当于一个应用的创建过程 retVal是在堆里面
  };

  int& qRet = pRetQuote();

  cout << qRet << " " << &qRet << endl;

  // 引用堆的释放
  delete &qRet;

  cout << "====" << endl; 
  /*
    0x4f6da0
    10 0x4f6da0
    ====
    结果 &qRet == retVal
  */

}

int main()
{
  test01();
  return 0;
}
