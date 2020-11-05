#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 二级指针的练习

void printfPInt(int **const pArray, size_t len)
{

    for (size_t i = 0; i < len; i++)
    {
        printf("pArray[%d] = %d \n", (int)i, *pArray[i]);
    }
}

void test01()
{
    // 二级堆指针 输入练习
    size_t len = 5;
    int **pIntArray = NULL;
    pIntArray = calloc(len, sizeof(int *));
    if (pIntArray == NULL)
    {
        perror("calloc");
        return;
    }
    int int_arr[5] = {10, 20, 30, 40, 50};
    for (size_t i = 0; i < len; i++)
    {
        pIntArray[i] = &int_arr[i];
    }
    printfPInt(pIntArray, len);

    if (pIntArray != NULL)
    {
        free(pIntArray);
        pIntArray = NULL;
    }
}

void test02()
{
    // 二级栈指针 输入练习
    int *pIntArray[5] = {NULL};
    size_t len = sizeof(pIntArray) / sizeof(int *);
    printf("len = %d \n", (int)len);

    int intArray[5] = { 10, 20, 30, 40, 50 };

    for (size_t i = 0; i < len; i++)
    {
        pIntArray[i] = calloc(1, sizeof(int));
        pIntArray[i] = &intArray[i];
    }

    printfPInt(pIntArray, len);
    
    for (size_t i = 0; i < len; i++)
    {
        if(pIntArray[i] != NULL) {
            printf("pIntArray[%d] = %p \n", (int) i, pIntArray[i]);
            free(pIntArray[i]);
            pIntArray[i] = NULL;
        }
    }
}

void callocPint(int** pInt, size_t len) {
    pInt = calloc(len, sizeof(int*));
    // for (size_t i = 0; i < len; i++)
    // {
    //     pInt[i] = calloc(1, sizeof(int));
    //     *pInt[i] = (int)(i * 100);
    // }
}

void test03() {
    // 二级指针堆 输出练习
    int** pIntArray = NULL;
    size_t len = 5;
    callocPint(pIntArray, len);

    for (size_t i = 0; i < len; i++)
    {
        printf("*pIntArray[%d] = %d \n", (int)i, *pIntArray[i]);
    }
    
    // for (size_t i = 0; i < len; i++)
    // {
    //     if(pIntArray[i] != NULL) {
    //         free(pIntArray[i]);
    //         pIntArray[i] = NULL;
    //     }
    // }

    if(pIntArray != NULL) {
        free(pIntArray);
        pIntArray = NULL;
    }
    
}

int main()
{
    test03();
    return 0;
}
