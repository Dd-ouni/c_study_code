#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void test01() {
	for (size_t i = 0; i < 100; i++)
	{
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
}

/*
	for (size_t i = 0; i < 100; i++)
002A18C8  mov         dword ptr [ebp-8],0		// 1. ��0��������i
002A18CF  jmp         test01+3Ah (02A18DAh)		// 2. ��ת�� 3
002A18D1  mov         eax,dword ptr [ebp-8]		// 8. �Ĵ����Ա���i+1 
002A18D4  add         eax,1
002A18D7  mov         dword ptr [ebp-8],eax     // 8 to 3 �������ж�ѭ��
002A18DA  cmp         dword ptr [ebp-8],64h	    // 3. �Աȱ���i �� 100
002A18DE  jae         test01+81h (02A1921h)     // 4. ǰ�ߴ��ڵ��� 100 ��תѭ������
	{
		if (i % 2 == 0) {
002A18E0  mov         eax,dword ptr [ebp-8]     // ...
002A18E3  xor         edx,edx					//
002A18E5  mov         ecx,2						//
002A18EA  div         eax,ecx					//
002A18EC  test        edx,edx					//  
002A18EE  jne         test01+7Fh (02A191Fh)     // 5 ... �ж� i % 2 == 0 �����������ִ�У����򼴽��͵�ǰѭ��002A191F
			cout << i << endl;
002A18F0  mov         esi,esp				    // 6. ����ִ��cout << i << endl;
002A18F2  push        offset std::endl<char,std::char_traits<char> > (02A1258h)
002A18F7  mov         edi,esp
002A18F9  mov         eax,dword ptr [ebp-8]
002A18FC  push        eax
002A18FD  mov         ecx,dword ptr [__imp_std::cout (02AB0A8h)]
002A1903  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (02AB09Ch)]
002A1909  cmp         edi,esp
002A190B  call        __RTC_CheckEsp (02A1235h)
002A1910  mov         ecx,eax
002A1912  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (02AB0A0h)]
002A1918  cmp         esi,esp
002A191A  call        __RTC_CheckEsp (02A1235h)
		}
	}
002A191F  jmp         test01+31h (02A18D1h)    // 7. ִ����һ��ѭ�� �ص� �ж����������Լ� 02A18D1
}
*/
int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}