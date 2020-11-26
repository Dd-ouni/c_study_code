#include <iostream>
#include <cstring>
using namespace std;

// 重载复制运算符
// 解决浅拷贝问题 清除堆段错误问题

class MyStr
{
    friend ostream& operator<<(ostream& cout, MyStr& str);
public:
    MyStr(){
        this->name = NULL;
    }
    MyStr(char* name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    ~MyStr() {
        cout << "~MyStr" << endl;
        delete []this->name;
        this->name = NULL;
    }
    // 实现深拷贝,编译器自己生成是浅拷贝
    MyStr(const MyStr& str) {
        this->name = NULL;
        this->name = new char[strlen(str.name)+1];
        strcpy(this->name, str.name);
    }
    // 为了实现连续赋值 a = b = c 返回一个引用 
    MyStr& operator=(MyStr& str) {
        // 赋值拷贝有可能是再次 
        delete []this->name;
        this->name = NULL;
        this->name = new char[strlen(str.name)+1];
        strcpy(this->name, str.name);
        return *this;
    }

private:
    char *name;
};


ostream& operator<<(ostream& cout, MyStr& str){
    cout << str.name;
    return cout;
}

void test01()
{
    // 实现运算符拷贝结果
    int a = 10;
    int b = 20;
    int c = a = b;
    cout << "a " << a << " b " << b << " c " << c << endl;
    // a 20 b 20 c 20


    MyStr str1((char*)"12345");
    MyStr str2((char*)"123");
    MyStr str3 = str2 = str1;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
}

int main()
{
    test01();
    return 0;
}
