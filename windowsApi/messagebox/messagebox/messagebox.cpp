#include <iostream>
#include <Windows.h>


int main()
{
    int ret = MessageBox(NULL, TEXT("Hello world!"), TEXT("标题"), MB_OK);
    return 0;
}


