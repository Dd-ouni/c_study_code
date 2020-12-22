#include <iostream>
using namespace std;

class T{
public:
    static T* ptrT;
    void* operator new(size_t size) {
        cout << size << endl;
        return ptrT;
    }
};

T* T::ptrT = (T*)malloc(sizeof(T) * 1000);

int main()
{
    
    return 0;
}
