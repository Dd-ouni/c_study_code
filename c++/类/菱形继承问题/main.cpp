#include <iostream>
using namespace std;

class GameObject{
    public:
        unsigned x{0};
        unsigned y{0};
        GameObject() {
            cout << "GameObject 构造函数" << endl;
        }
};
// class Person: public GameObject{
class Person: public virtual GameObject{
    public:
        unsigned pa{10};
        unsigned pb{20};
        Person() {
            cout << "Person 构造函数" << endl;
        }
};

// class Wolf: public GameObject{
class Wolf: public virtual GameObject{
    public:
        unsigned wa{500};
        unsigned wb{1000};
        Wolf() {
            cout << "Wolf 构造函数" << endl;
        }
};

class WolfPerson: public Person, public Wolf{
    public:
        unsigned wpa{200};
        unsigned wpb{400};
    
        WolfPerson() {
            cout << "WolfPerson 构造函数" << endl;
        }
};

/*
    1. 菱形继承
    菱形继承是（多继承）中的一种情况
    动物 -> 人类、狼 -> 狼人
    人类 和 狼 继承于 动物类，狼人 又继承于 人类 和 狼
    
    以上就是菱形继承的状况
*/
/*
    2. 菱形继承的问题之重复父类成员属性 
    人类 和 狼 继承于 动物类，狼人 又继承于 人类 和 狼
    这一系列操作之后，人 和 狼 都拥有动物类的成员变量
    狼人继承了 人 和 狼即可会拥有2份动物类的成员变量
    导致二一性问题
*/
/*
    3. 虚基类
    通过给 人 和 狼 使用虚基类修饰继承的父类解决菱形继承问题
*/


void test01() {
    unsigned size{sizeof(WolfPerson)}, size_n{sizeof(WolfPerson) / sizeof(unsigned)};
    cout << "WolfPerson size：" << size << "  \\ WolfPerson num：" << size_n << " \\ unsigned " << sizeof(unsigned) << endl;

    using PtrWolfPerson = WolfPerson*;
    WolfPerson wp;
    PtrWolfPerson pwp = &wp;
    // 这里不转换的话， pwp又不支持下标访问 pwp++ 会是+40导致打印的数据都处问题了
    unsigned* pu = (unsigned*)pwp;

    cout << "pwp：" << hex << pwp << endl;
    for (size_t i = 0; i < size_n; i++)
    {
        cout << dec << i << " v:"<< *pu << " p:" << hex; 
        cout << (pu++) <<  endl;
    }
    /*  未使用虚基类的情况下  GameObject 的成员是重叠了 0 1 - 4 5
    0 v:0 p:0x62fed4
    1 v:0 p:0x62fed8
    2 v:10 p:0x62fedc
    3 v:20 p:0x62fee0
    4 v:0 p:0x62fee4
    5 v:0 p:0x62fee8
    6 v:500 p:0x62feec
    7 v:1000 p:0x62fef0
    8 v:200 p:0x62fef4
    9 v:400 p:0x62fef8
    使用虚基类下  GameObject 的成员就只有一份了
    0 v:4219748 p:0x62fed4
    1 v:10 p:0x62fed8
    2 v:20 p:0x62fedc
    3 v:4219760 p:0x62fee0
    4 v:500 p:0x62fee4
    5 v:1000 p:0x62fee8
    6 v:200 p:0x62feec
    7 v:400 p:0x62fef0
    8 v:0 p:0x62fef4
    9 v:0 p:0x62fef8
    */
}

int main()
{
    test01();
    return 0;
}
