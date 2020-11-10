// c++ 标准输入输出
/*
    从 stdio.h => iostream
    如果要使用久的C库可以 stdio.h => cstdio
    用c表示是c旧库 去掉.h 是c++新标准支持
*/
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    char text[64] = {0};
    printf("pls ipt text：\n");
    scanf("%s", text);
    printf("hello world %s\n", text);
    printf("pls ipt text：\n");
    cin >> text;
    cout << "hello world " << text << endl;
    std::cout << "hello world " << text << std::endl;
    // c 与 c++的输入输出区别在于少了 格式符，多了命名空间 using namespace std
    // 命名空间是为了解决两个产品 同样名字的api 都叫 cout，那该怎么办
    // 这时候就有了命名空间，标注那些api属于哪个程序 std::cout 说明使用 std程序的cout api
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
