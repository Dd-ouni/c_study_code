#include <iostream>
#include <string>
using namespace std;
class BasePage
{
public:
    void showHeader()
    {
        cout << "Common Header" << endl;
    }
    void showFooter()
    {
        cout << "Common Footer" << endl;
    }
    void showSidebar()
    {
        cout << "Common Sidebar" << endl;
    }
};

class Cpp : public BasePage
{
public:
    void showContent()
    {
        cout << " Cpp 内容123" << endl;
    }
};

class Java : public BasePage
{
public:
    void showContent()
    {
        cout << " Java 内容" << endl;
    }
};

void test01()
{
    Cpp cp;
    Java ja;
    cp.showContent();
    ja.showContent();
}

int main()
{
    test01();
    return 0;
}
