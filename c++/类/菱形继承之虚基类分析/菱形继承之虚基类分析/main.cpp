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
    // ��һ������ ����ʹ��
    // w.Wolf::x = 1000;
    // w.Person::x = 2000;
    // cout << "Wolf::x��" << w.Wolf::x << " Person::x��" << w.Person::x << endl;
    // �����ǿ���ʹ�ã����������ظ���,������Ҫ����ʵ��һ��X

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
    // 2000 1000 ������ᷢ�� Person�� Wolf ǰ��
    // �Ե�һ�¼̳�˳�����Կ� 1000 2000
    // ��̳��Ⱥ�ȡ���ڳ�Ա������ջ������˳��
    // �����۲죬�������μ̳б����ռ���ʵ��С8�ֽ�
    // ȴ�ڵ���ջ��������208�Ŀռ�

    w.x = 2000;
    // cout << w.Wolf::x << " " << w.Person::x << endl;
    // ʹ�������Ľ�� 2000 2000
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