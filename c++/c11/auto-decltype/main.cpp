#include <iostream>
using namespace std;

// auto add(int* a, int* b) {
//     return *a + *b;
// }

// auto尾插法，不然会丢失修饰符
auto add(int* a, int* b)->int*{
    *a += *b;
    return a;
}

// decktype 计算返回类型
auto add(int& a, int& b)-> decltype(a > b?a:b){
    return a > b?a:b;
}



void test01() {
    // 1. auto 的缺陷, 丢失修饰符
    const int b{100};
    auto cb{b};
    cb = 2000;
    cout << cb << endl;

    // 2. auto func，尾插设置返回类型
    int a1{10};
    int a2{20};
    *add(&a1, &a2) = 500;
    cout << a1 << " " << a2 << endl;
    // 500 20

    // decltype 不是方法,s是关键字，编译阶段和sizeof一样
    // decltype 用来计算类型
    
    // 1. decltype 没有通过计算，直接获取类型
    decltype(a1) aa;
    cout << typeid(aa).name() << endl;
    // int

    // 2. 常量计算类型
    decltype(100 - 10) ab;
    cout << typeid(ab).name() << endl;

    // 3. 不同类型计算
    int ac{};
    unsigned ad{};
    decltype(ac-ad) ae;
    cout << typeid(ae).name() << endl;
    // ad - ad 并没有正真的计算 unsigned 

    // 4. 指针类型计算
    int* af;
    decltype(af) ag = &ac;
    cout << typeid(ag).name() << endl;
    // 指针类型

    // 5 计算函数返回类型
    int ah{30};
    int ai{500};
    add(ah, ai) = 10;
    cout << ah << " " <<  ai << endl;
    // 30 10
}

int main()
{
    system("cls");
    test01();
    return 0;
}
