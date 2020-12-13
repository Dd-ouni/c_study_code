#include <iostream>
#include <vector>
using namespace std;

void test01()
{
    vector<int> cc(10, 10);

    for (int i : cc)
    {
        cout << i << endl;
    }
}
int main(void)
{
    test01();
    return 0;
}
