#include <iostream>
#include <cstdio>
using namespace std;
// lambda

/*
    []()muitale->int{

    }()
*/
void *dataAdd(void *a, void *b, void *(*pAddFunc)(void *, void *))
{
    return pAddFunc(a, b);
}

void test01()
{
    int a = 10;
    int b = 20;

    cout << *(int *)(dataAdd((void *)&a, (void *)&b, [](void *a, void *b) -> void * {
        int ret = *(int *)a + *(int *)b;
        return *((void)ret);
    })) << endl;
}

int main(void)
{
    test01();
    return 0;
}
