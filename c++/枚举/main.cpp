#include <iostream>
using namespace std;

/*
    枚举的声明
    enum class 枚举类型名 : 枚举数据类型默认int 

    1.枚举类型的数据类型必须是整数型（直接int建议）
    2.枚举类型的成员默认是+1递增的
    3.枚举类型是安全的，对比的是否必须强转
    4.枚举类型的声明默认值间隔是为什么防止
    以后类型扩展，和保存的在服务器的数据冲突
    预留的空间，2个值挨着就不好插入了。
    5.枚举可以嵌套一起含义的声明比如防御级别
*/
enum class EquipLv : int
{
    general = 10,
    defA = general,
    //普通 防御A
    high = 20,
    defB = high,
    //高级 防御B
    epic = 30,
    defC = epic,
    //史诗 防御C
    legend = 40,
    defD = legend
    //传说 防御D
};

int operator-(EquipLv a, EquipLv b)
{
    return (int)a - (int)b;
}

ostream &operator<<(ostream &cout, EquipLv e)
{
    cout << (int)e;
    return cout;
}

void test01()
{
    EquipLv weaponA{EquipLv::general};
    // 枚举的定义，weaponA 武器A的品质普通
    EquipLv weaponB{EquipLv::epic};
    // 武器B的品质史诗

    cout << "武器B和武器A的品质差距" << weaponB - weaponA << endl;
    // 枚举类型的比较，因为是安全的类型，必须强转才能对比，这里重载EquipLv的-运算符

    EquipLv boboDef{EquipLv::defB};
    // 定义了bobo的防御，初始化为防御B
    cout << "波波的防御级别：" << boboDef << endl;
    boboDef = EquipLv::defD;
    // 对bobo的防御进行升级
    cout << "升级后波波的防御级别：" << boboDef << endl;
}

int main()
{
    test01();
    return 0;
}
