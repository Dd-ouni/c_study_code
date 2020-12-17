#include <iostream>
using namespace std;


void test01() {
  // 1. 数组引用
  int arr[5] = { 1, 2, 3, 4, 5 };
  int (&qArr)[5] = arr;

  // for (size_t i = 0; i < sizeof(qArr) / sizeof(qArr[0]); i++)
  // {
  //   cout << qArr[i] << endl;
  // }

  // 2. 先定义数组类型在定义
  typedef int(INT_ARR)[5];
  INT_ARR& qArr2 = arr;

  // for (size_t i = 0; i < sizeof(qArr2) / sizeof(qArr2[0]); i++)
  // {
  //   cout << qArr2[i] << endl;
  // }


  // 3. 直接定义别名引用类型
  typedef int(&Q_INT_ARR)[5];
  Q_INT_ARR qArr3 = arr;

  // for (size_t i = 0; i < sizeof(qArr3) / sizeof(qArr3[0]); i++)
  // {
  //   cout << qArr3[i] << endl;
  // }


 // 4.数组引用长度问题
//  int arr2[] = {1,2,3};
//  int (&qArr4)[] = arr2;
 // error: invalid initialization of reference of type 'int (&)[]' from expression of type 'int [3]'
 // 引用数组一定要有长度, 并且长度要对应
//  int (&qArr4)[sizeof(arr2) / sizeof(arr[0])] = arr2;
 


  // 5. 数组引用传递参数的好处
  int arr3[5]{1,2,3,4,5};
  [](int (&arr)[5])->int{
    cout << sizeof(arr) << endl;
    return 0;
  }(arr3);
  // 20 以往数组传递是不能sizeof的
  // 总结
  /*
    1.后面2种用得比较少
    2.数组引用长度一定要确认对应
  */
}

int main(void)
{
  test01();
  return 0;
}
