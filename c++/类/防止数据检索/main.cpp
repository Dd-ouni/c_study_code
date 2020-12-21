#include <iostream>
using namespace std;
int main() {
    int money = 2500;
    /*
        这里使用为了更好观察汇编 
        -m32 
        -O0 不优化
        -Os 代码变少
    */
    while (1)
    {
        cout << "money：" << money << endl;
        system("pause");
        money -= 100;
    }
}