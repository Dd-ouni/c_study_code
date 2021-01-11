#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    cout << "Hi, I want to access kernel space!" << endl;
    cout << sizeof(void*) << endl;

    try
    {
        *(int *)0xF0808080 = 0x22;
    }
    catch(exception& e)
    {
        cout << "捕获异常" << endl;
        cout << e.what() << endl;
    }
    
    cout << "I would never reach so far!" << endl;
    return 0;
}
