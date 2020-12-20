#include <iostream>
using namespace std;

template <typename IncTmpType>
IncTmpType inc(IncTmpType a, IncTmpType b) {
        cout << typeid(a).name() << endl;
    return a + b;
}

// 函数模板例外，用来处理指针
template <>
int* inc(int* a, int* b) {
        cout << typeid(a).name() << endl;
    return *a > *b? a : b;
}

int inc(int a, int b){
    cout << "int 类型" << endl;
    return a + b;
}

// 高级用法 1
template<typename TR, typename T1, typename T2>
TR add(T1 a, T2 b){
    return a + b;
}
// 只需要设置返回类型即可使用
// add<int>(10, 20);

// 高级用法 2 指定默认类型
template<typename T1, typename T2, typename TR = int>
TR add(T1 a, T2 b){
    return a + b;
}
// add(10, 20);

// 高级用法3 抽象 TR 默认是 T1
template<typename T1, typename T2, typename TR = T1>
TR add(T1 a, T2 b){
    return a + b;
}

// 高级用法4 非模板类型
template<int max, int min, typename T1>
bool changeHp(T1& hp, T1 hurt) {
    // 血量减去伤害剩余
    hp-= hurt;
    // 2500-=200 = 2300
    // 血量大于 2000 即复位血量
    if(hp > max) hp = max;
    // return false 2000 < 1000:true:false
    return hp < min;
} 
/*
    int hp{2500};
    bool ret = changeHp<2000, 1000>(hp, 200);
*/

// 高级用法5 结合auto 类型
template<typename T1, typename T2>
auto add(T1 a, T2 b){
    return a + b;
}
// 这里会丢失& 类型

// 高级用法6 结合类型计算
template<typename T1, typename T2>
decltype(auto) add(T1 a, T2) {
    return a + b;
}
/* c14型写法，丢弃尾插 */

void test01() {
    // 1. 自动检测类型使用   
    int a{109}, b{150}; 
    cout << inc(a, b) << endl;

    // 2.必须是同类型
    // cout << inc(200.0f, 300) << endl;
    cout << inc(200.0f, (float)300) << endl;

    // 3.函数重载优先级高于函数模板
    // 1.的打印是 int 类型


    // 4.高级用法之 不同类型
    // cout << add<int>(100, (int)2.20f) << endl;

}
int main()
{
    test01();
    return 0;
}
