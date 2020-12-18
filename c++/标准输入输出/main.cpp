// c++ 标准输入输出
/*
    从 stdio.h => iostream
    如果要使用久的C库可以 stdio.h => cstdio
    用c表示是c旧库 去掉.h 是c++新标准支持
*/
#include <cstdio>
#include <iostream>

// using namespace std;
// 命名空间 using namespace std 这里是解放所有std命名空间
// 命名空间是为了解决两个产品 同样名字的api 都叫 cout，那该怎么办
// 这时候就有了命名空间，标注那些api属于哪个程序 std::cout 说明使用 std程序的cout api
// 大项目是只解放使用到的 以下，或者在单独的{} 块里使用
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    
    // 旧的标输入输出
    char text[64] = {0};
    printf("pls ipt text:\n");
    scanf("%s", text);
    printf("hello world %s\n", text);
    printf("pls ipt text:\n");

    // 新的标准输入输出
    int num = 0;
    cin >> text;
    // cin >> &num;
    cin >> num;
    cout << "hello world " << text << " - " << num << endl;
    std::cout << "hello world " << text << std::endl;
    // cout 标准输出， 通过 << 把内容传递给 cout对象，打印到屏幕
    // 对比： 少了转换说明符，输出万能常用格式
    // cin 标准输入  
    // 对比： 少了转换说明符，少了&取址符
    // endl： 换行符，并且刷新缓冲区
    // 对比： 统一 \n\r 


    // >> <<
    // 这里是重定义了符号作用也是C++特性，>> << 在cout cin 有了别的作用

    // 总结C++对C做了大量的封装，更易用，特性更强


    /* 结果
        pls ipt text：
        c++
        hello world c++
        pls ipt text：
        c++
        hello world c++
        hello world c++
    */
    return 0;
}
