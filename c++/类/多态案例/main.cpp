#include <iostream>
using namespace std;
/*
  实现 咖啡 和 奶茶 的制作
  制作步骤
  1. 获取餐具
  2. 添加食材
  3. 制作饮品
  4. 饮品出炉
*/

// 多态版本
/*
  多态的好处体现于：
  开闭原则：对扩展进行开放，对修改进行关闭
  多态好处：代码结构清晰、提高可读性、可高扩展性
  （对比普通版代码，要去一个函数里面修改逻辑和扩展,
  多态只需要继承抽象类，实现虚函数即可）
*/
class AbstractDrink{
  public:
    virtual void getTableware() {}
    virtual void incII() {}
    virtual void makeStart() {}
    virtual void makeEnd() {}
    void make() {
      this->getTableware();
      this->incII();
      this->makeStart();
      this->makeEnd();
    }
    virtual ~AbstractDrink(){}
};

class Coffee: public AbstractDrink{
  public:
    void getTableware() override final{
      cout << "获取咖啡杯" << endl;
    }
    void incII() override final{
      cout << "倒入磨好的咖啡粉" << endl;
    }
    void makeStart() override final{
      cout << "开水冲泡咖啡" << endl;
    }
    void makeEnd() override final{
      cout << "咖啡泡好了" << endl;
    }
};

class Tea: public AbstractDrink{
  public:
    void getTableware() override final{
      cout << "获取茶具" << endl;
    }
    void incII() override final{
      cout << "添加红茶叶" << endl;
    }
    void makeStart() override final{
      cout << "开水冲泡" << endl;
    }
    void makeEnd() override final{
      cout << "爷爷泡的茶好了" << endl;
    }
};
void buyDrink(AbstractDrink* drink){
  drink->make();
  delete drink;
}

void test01(){
  // 我要喝咖啡
  buyDrink(new Coffee);
  // 我要喝茶
  buyDrink(new Tea);
}

int main()
{
  test01();
  return 0;
}
