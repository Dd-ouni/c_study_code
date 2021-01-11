#include <iostream>
using namespace std;
/*
  异常变量的生命周期

  throw 变量        
  catch (类型 形参) 
  这里的变量有声明周期

*/


class MyException{
  public:
    MyException(){
      cout << "MyException 构造函数" << endl;
    }
    MyException(const MyException&){
      cout << "MyException 拷贝构造" << endl;
    }
    ~MyException() {
      cout << "MyException 析构函数" << endl;
    }
};



void test01() {
  try
  {
    []()->void{
      throw new MyException();
    }();
  }
  /*
    1. 值传递的生命周期
    throw MyException();
    catch(MyException e)

    MyException 构造函数
    MyException 拷贝构造
    自定义异常捕获
    MyException 析构函数
    MyException 析构函数
    这里的匿名函数，遇到值传递会触发拷贝构造函数
    这样子的拷贝并不是我们想要的,并且消耗大
  */
  /*
    2. 引用传递的生命周期
    throw MyException();
    catch(MyException& e)  

    MyException 构造函数
    自定义异常捕获
    MyException 析构函数
    这个是最优消耗最少的,传递引用
  */
  /*
    3. 指针传递的生命周期
    throw new MyException();
    catch(MyException* e)
    delete e;

    MyException 构造函数
    自定义异常捕获
    MyException 析构函数
    这种也是合理的
  */
  catch(MyException* e)
  {
    cout << "自定义异常捕获" << endl;
    delete e;
  }
  
}

int main()
{
  test01();
  return 0;
}
