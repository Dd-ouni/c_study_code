#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/*
  扩展系统异常
  前言:其实就是练习多态和对库的了解
  1. exception是多态的基类，找到它的
  定义，重写虚函数即可
    virtual ~exception() noexcept
    {
        __std_exception_destroy(&_Data);
    }

    _NODISCARD virtual char const* what() const
    {
        return _Data._What ? _Data._What : "Unknown exception";
    }
  主要重写以上两个虚函数
*/

class my_out_of_range: public exception{
  public:
    my_out_of_range(string err) {
      this->my_err = err;
    }
    ~my_out_of_range() noexcept
    {
        cout << "my_out_of_range 析构" << endl;
    }
    char const* what() const noexcept override
    {
    /*
      error: looser throw specifier for 
      'virtual const char* my_out_of_range::what() const'
      期间发生了这个异常，搜了一下C++11 添加 noexcept override
    */
        return this->my_err.c_str();
    }
  private:
    string my_err;
};

void doWork() {

  try
  {
    throw my_out_of_range("范围溢出异常");
  }
  catch(exception& e)
  {
    cout << e.what() << endl;
  }
}

int main()
{
  doWork();
  return 0;
}
