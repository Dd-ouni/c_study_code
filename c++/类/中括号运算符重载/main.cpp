#include <iostream>
using namespace std;

// 中括号运算符重载，用于数组索引访问
class MyArray{
  public:
    MyArray(int i) {
      this->arr = new int[i];
    }
    ~MyArray(){
      delete []this->arr;
    }
    // 这里需要返回数组索引自身元素索引，猜可以进行赋值
    int& operator[](int i){
      return this->arr[i];
    }
  private:
    int* arr;
};



void test01() {
  MyArray iarr(10);
  iarr[3] = 10;
  cout << iarr[3] << endl;
  iarr[3] = 1000;  
  cout << iarr[3] << endl;
}


int main(void)
{
  test01();
  return 0;
}
