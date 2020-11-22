#include <iostream>
#include <string>
using namespace std;

// 友元
// 允许访问类的私有成员
// 通过声明可以是 全局函数、成员函数、类
// 也叫 友元全局函数、友元成员函数、 友元类
class Human;

class HumanMother {
  public:
    void showHumanBedroom2(Human& h);
};

class Human{
  // 声明 全局函数 humanFather 可以访问 Human 私有
  // 通过 friend 修饰
  friend void humanFather(Human&);
  // 声明 类 HumanFather 可以访问 Huamn 私有 
  friend class HumanFather;

  // 声明 成员函数  HumanMother::showHumanBedroom2 可以访问 Huamn 私有
  friend void HumanMother::showHumanBedroom2(Human&);
  // 友元成员函数特么奇葩，Human必须的声明在最前面，然后就是定义HumanMother
  // 在然后定义 Human  在然后在定义 showHumanBedroom2 日了狗了
  public:
    Human(string name) {
      this->name = name;
      this->bedroom = name + " bedroom";
      this->parlor = name + " parlor";
    }
    string name;
    string parlor;
    void showParlor() {
      cout << this->parlor << endl;
    }

  private:
    string bedroom;
    void showBedroom(){
      cout << this->bedroom << endl;
    }

};

// 友元类 定义
class HumanFather{
  public:
    HumanFather& getHumanBedroom(Human& h){
      cout << "HumanFather get" << h.bedroom << endl;
      return *this;
    }

    HumanFather& showHumanBedroom(Human& h) {
      cout << "HumanFather show";
      h.showBedroom();
      return *this;
    }
};

// 友元全局函数 定义
void humanFather(Human& human){
  human.showBedroom();
}

// 友元 成员函数
void HumanMother::showHumanBedroom2(Human& h){
  cout << "HumanMother show";
  h.showBedroom();
}

void test01() {
  Human lucy("lucy");
  // 访问客厅
  lucy.showParlor();

  // 访问卧室
  // lucy.showBedroom();
  // showBedroom 是私有的test01 可以访问？不可以的

  // 友元全局函数 
  humanFather(lucy);
  // huamnFather 被声明为友元全局

  // 友元类
  HumanFather().getHumanBedroom(lucy).showHumanBedroom(lucy);
  // 全部方法都可以调用


  // 友元成员函数
  HumanMother().showHumanBedroom2(lucy);

}

int main()
{
  test01();
  return 0;
}
