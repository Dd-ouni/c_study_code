#include <iostream>
#include <cstring>
#include <cstdio>
#include <locale>
using namespace std;
void test01(){
  // 1. char
  /*
  溢出问题，我们在栈区申请了5字节的空间，输入的却超过5字节
  这个问题可能会导致栈区被修改执行其他的代码
  https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html
  编译指令  -fstack-protector-all

  遇到中文，分为2个字节存储
  */
  
  // printf("%s", "请输入字符串 \n");
  // char ch[0x5]{};
  // scanf("%s", ch);
  // printf("ch strlen = %u \n", (unsigned int) strlen(ch));
  // printf("%s\n", ch);


  // 2. wchar
  // 宽字符， 所有的字符串都是2个字节
  setlocale(LC_ALL, "chs");
  wchar_t wch[5];
  wscanf(L"%s", wch);
  wprintf(L"s\n", wch);

  // 这里需要注意的是 打印到控制台是根据字节表，这边使用宽字符之后
  // 就得使用 setlocale(LC_ALL, "chs");

}

int main()
{
  system("cls");
  test01();  
  return 0;
}
