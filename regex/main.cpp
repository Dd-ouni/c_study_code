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
    system("chcp 65001");

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

    string str = fileBuff;
    regex reg("\\$t\\('(.*?)'\\)");

    smatch m;
    auto pos = str.cbegin();
    auto end = str.cend();
    for (; regex_search(pos, end, m, reg); pos = m.suffix().first)
    {
        cout << "----------------" << endl;
        cout << m.str() << endl;
        cout << m.str(1) << endl;
        // cout << m.str(2) << endl;
        // cout << m.str(3) << endl;
    }

    // regex reg("<(.*?)>(.*?)</(\\1)>");
    // string content("123<xml>value</xml>456<xml>center</xml>hahaha<vertical>window</vertical>the end");
    // regex reg("\\$t\\('(.*?)'\\)");
    // string content("$t('请输入关键词搜索')$t('cccc')$t('aaaa')");
    // smatch m;
    // auto pos = content.cbegin();
    // auto end = content.cend();
    // for (; regex_search(pos, end, m, reg); pos = m.suffix().first)
    // {
    //     cout << "----------------" << endl;
    //     cout << m.str() << endl;
    //     cout << m.str(1) << endl;
    //     // cout << m.str(2) << endl;
    //     // cout << m.str(3) << endl;
    // }
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