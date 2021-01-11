#include <iostream>
#include <regex>
#include <exception>
#include <cstdio>
#include <cstdlib>
using namespace std;

void openFile();

int main()
{
    system("chcp 65001");

    try
    {
        openFile();
    }
    catch (exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void openFile()
{
    FILE* ptrFile;
    size_t textSize;
    char* fileBuff;
    size_t result;
  

    ptrFile = fopen("Container.vue", "rb");
    if(ptrFile == NULL){
        perror("open file err");
    }

    //获取文件大小
    // 文件指针定位到最后
    fseek(ptrFile, 0, SEEK_END);
    textSize = (size_t)ftell(ptrFile);
    printf("FileSize:%d \n", textSize);

    // 定位到文件开头
    fseek(ptrFile, 0, SEEK_SET);

    // 创建堆用来存储文件内容
    fileBuff = (char*) malloc(sizeof(char)* textSize);
    if(fileBuff == NULL){
        perror("malloc err");
    }

    result = fread(fileBuff, 1, textSize, ptrFile);
    if(result != textSize) {
        perror("fread size not");
    }

    cout << "Result:" << result << endl;
    // while (*fileBuff)
    // {
    //     printf("%d\n", *fileBuff);
    //     fileBuff++;
    // }

    printf("=======\n");
    
    // char* textBuff = (char*) malloc(sizeof("测试"));
    // memcpy(textBuff, "测试");
    // printf("%s", textBuff);
    char strText[] = "测试";
    char* ptrStr = strText;
   
    // while (*ptrStr)
    // {
    //     printf("%d\n", *ptrStr);
    //     ptrStr++;
    // }

    printf("=======\n");

    printf("%s\n", fileBuff);
    printf("%s\n", ptrStr);
    printf("%s\n", strText);
    

    fclose(ptrFile);
    free(fileBuff);
    // free(textBuff);
}