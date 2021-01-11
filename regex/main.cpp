#include <iostream>
#include <regex>
#include <exception>
#include <cstdio>
#include <cstdlib>
using namespace std;

void readFile(char *&);
void replaceTransl(char *&);
void test();

int main()
{
    // system("chcp 65001");

    try
    {
        test();
    }
    catch (exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void test()
{
    char *fileBuff = NULL;
    // 读取文件
    readFile(fileBuff);

    // 替换翻译
    replaceTransl(fileBuff);

    // printf("%s\n", fileBuff);

    if (fileBuff != NULL)
    {
        // printf("释放 fileBuff \n");
        free(fileBuff);
        fileBuff = NULL;
    }
}

void replaceTransl(char *&fileBuff)
{

    smatch results;
    string str = fileBuff;
    cout << str << endl;

    while (regex_search(str, results, regex("(t\\()(.*)(\\))")))
    {
        for (auto x : results)
        {
            cout << x << " ";
        }
        cout << endl;
        str = results.suffix().str();
    }
}

void readFile(char *&fileBuff)
{
    FILE *ptrFile;
    size_t textSize;
    size_t result;

    ptrFile = fopen("Container.vue", "rb");
    if (ptrFile == NULL)
    {
        perror("open file err");
    }

    //获取文件大小
    // 文件指针定位到最后
    fseek(ptrFile, 0, SEEK_END);
    textSize = (size_t)ftell(ptrFile);
    printf("FileSize:%d \n", (int)textSize);

    // 定位到文件开头
    fseek(ptrFile, 0, SEEK_SET);

    // 创建堆用来存储文件内容
    fileBuff = (char *)malloc(sizeof(char) * textSize);
    if (fileBuff == NULL)
    {
        perror("malloc err");
    }

    result = fread(fileBuff, 1, textSize, ptrFile);
    if (result != textSize)
    {
        perror("fread size not");
    }

    fclose(ptrFile);
}