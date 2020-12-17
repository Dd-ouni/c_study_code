#include <iostream>
#include <cstdio>
using namespace std;
// lambda

/*
    []()muitale->int{

    }()
*/

void test01()
{
   //1. lambda 基本使用 之自执行
   []()mutable->void{
       cout << "lambda自执行示例" << endl;
   }();
   /*
    没有函数的返回类型的时候可以省略 ->void
    []()mutable{
       cout << "ccc" << endl;
    }();
   */


    //2.函数指针和lambda 示例
    void (*pFun)();
    pFun = [](){
        cout << "函数指针加lambda示例" << endl;
    };
    pFun();


    //3.传递函数指针和lambda示例

    void (*pFunCallbak)(int (*)(int, int)) = [](int (*pCallback)(int, int)){
        int ret = pCallback(10, 20);
        cout << ret << endl;
    };

    pFunCallbak([](int a, int b)->int{
        return a + b; 
    });

}

int main(void)
{
    test01();
    return 0;
}
