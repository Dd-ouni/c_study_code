#include <iostream>
using namespace std;


class Main{
  public:
    // 开放获取单例接口，防止 赋值修改单例
    static Main* getInstance() {
      return MAIN;
    }
  private:
    // 防止实例化和拷贝
    Main() {
      cout << "Main 构造函数" << endl;
    }
    Main(const Main&) {}
    // 防止 赋值修改单例
    static Main* MAIN;
};

// 同学们都会奇怪，私有的静态变量是不可以访问的
// 在全局却可以
Main* Main::MAIN = new Main;


void test01() {
  Main* m1 = Main::getInstance();
  Main* m2 = Main::getInstance();
  if(m1 == m2) {
    cout << "m1 == m2" << endl;
  }else{
    cout << "m1 != m2" << endl;
  }
}

int main(void)
{
  // 一道面试题，main先初始化还是静态先初始化
  cout << "main 函数" << endl;
  test01();
  /* code */
  return 0;
}
