#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void test01() {

	size_t i = 0;
	while (i < 100)
	{
		if (i % 2 == 0) {
			cout << i << endl;
		}
		i++;
	}
}

/*
	size_t i = 0;
00BE18C8  mov         dword ptr [i],0				// 1. 变量赋值 i = 0
	while (i < 100)
00BE18CF  cmp         dword ptr [i],64h				// 2. 比较 i 与 100
00BE18D3  jae         test01+7Fh (0BE191Fh)			// 3. 大于等于结束循环 否则继续往下执行
	{
		if (i % 2 == 0) {
00BE18D5  mov         eax,dword ptr [i]				// 4. if (i % 2 == 0) {
00BE18D8  xor         edx,edx
00BE18DA  mov         ecx,2
00BE18DF  div         eax,ecx
00BE18E1  test        edx,edx
00BE18E3  jne         test01+74h (0BE1914h)			// test对比结果不上的话跳过打印到条件++
			cout << i << endl;						
00BE18E5  mov         esi,esp
00BE18E7  push        offset std::endl<char,std::char_traits<char> > (0BE1258h)
00BE18EC  mov         edi,esp
00BE18EE  mov         eax,dword ptr [i]
00BE18F1  push        eax
00BE18F2  mov         ecx,dword ptr [__imp_std::cout (0BEB0A8h)]
00BE18F8  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0BEB09Ch)]
00BE18FE  cmp         edi,esp
00BE1900  call        __RTC_CheckEsp (0BE1235h)
00BE1905  mov         ecx,eax
00BE1907  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0BEB0A0h)]
00BE190D  cmp         esi,esp
00BE190F  call        __RTC_CheckEsp (0BE1235h)
		}
		i++;
00BE1914  mov         eax,dword ptr [i]				// 5.判断条件变量自+
00BE1917  add         eax,1
00BE191A  mov         dword ptr [i],eax
	}
00BE191D  jmp         test01+2Fh (0BE18CFh)			// 6.跳转条件判断
}
*/

int main(int argc, char* argv[]) {
	test01();
	return 0;
}