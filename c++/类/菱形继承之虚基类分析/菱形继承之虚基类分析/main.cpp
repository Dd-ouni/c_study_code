#include <iostream>
using namespace std;

class Animal {
public:
	int x;
};

class Person : virtual public Animal {
};
class Wolf : virtual public Animal {
};
class Werewolf : public Wolf, public Person {
};

int test01() {

    Werewolf w;
    // w.x = 1000;
    // 二一性问题 不能使用
    // w.Wolf::x = 1000;
    // w.Person::x = 2000;
    // cout << "Wolf::x：" << w.Wolf::x << " Person::x：" << w.Person::x << endl;
    // 这样是可以使用，但是属性重复了,我们想要的其实是一个X

	/*
class Werewolf  size(8):
        +---
 0      | +--- (base class Person)
 0      | | +--- (base class Animal)
 0      | | | x
        | | +---
        | +---
 4      | +--- (base class Wolf)
 4      | | +--- (base class Animal)
 4      | | | x
        | | +---
        | +---
        +---
	*/

    // int* ptrW = (int*)&w;
    // cout << ptrW[0] << " " << ptrW[1] << endl;
    // 2000 1000 这里你会发现 Person在 Wolf 前面
    // 对调一下继承顺序试试看 1000 2000
    // 多继承先后取决于成员变量在栈的声明顺序
    // 反汇编观察，这种菱形继承变量空间其实很小8字节
    // 却在调用栈顶开辟了208的空间

    w.x = 2000;
    // cout << w.Wolf::x << " " << w.Person::x << endl;
    // 使用虚基类的结果 2000 2000
    /*
class Werewolf  size(12):
        +---
 0      | +--- (base class Wolf)
 0      | | {vbptr}
        | +---
 4      | +--- (base class Person)
 4      | | {vbptr}
        | +---
        +---
        +--- (virtual base Animal)
 8      | x
        +---

Werewolf::$vbtable@Wolf@:
 0      | 0
 1      | 8 (Werewolfd(Wolf+0)Animal)

Werewolf::$vbtable@Person@:
 0      | 0
 1      | 4 (Werewolfd(Person+0)Animal)
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
          Animal       8       0       4 0
    */
    return w.x;
        
    //return w.Wolf::x + w.Person::x;
}

int main() {
    int x = test01();
    cout << x << endl;
	return 0;
}