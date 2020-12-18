#include <iostream>

int Ave(int a, int b) {
	a = a + 250;
	return a + b;
}

int Add(int a, int b) {
	int c = 250;
	int d = Ave(a, b);
	c = c + d;
	return c;
}


int main() {

	int x = Add(250, 50);
	std::cout << x << std::endl;
	return 0;
}


/*
int Ave(int a, int b) {
00CC1002 EC                   in          al,dx
	a = a + 250;
00CC1003 8B 45 08             mov         eax,dword ptr [a]
00CC1006 05 FA 00 00 00       add         eax,0FAh
00CC100B 89 45 08             mov         dword ptr [a],eax
	return a + b;
00CC100E 8B 45 08             mov         eax,dword ptr [a]
00CC1011 03 45 0C             add         eax,dword ptr [b]
}
00CC1014 5D                   pop         ebp
00CC1015 C3                   ret


int Add(int a, int b) {
00C61020 55                   push        ebp
00C61021 8B EC                mov         ebp,esp
00C61023 83 EC 08             sub         esp,8
	int c = 250;
00C61026 C7 45 FC FA 00 00 00 mov         dword ptr [c],0FAh
	int d = Ave(a, b);
00C6102D 8B 45 0C             mov         eax,dword ptr [b]
00C61030 50                   push        eax
00C61031 8B 4D 08             mov         ecx,dword ptr [a]
00C61034 51                   push        ecx
00C61035 E8 C6 FF FF FF       call        Ave (0C61000h)
00C6103A 83 C4 08             add         esp,8
00C6103D 89 45 F8             mov         dword ptr [d],eax
	c = c + d;
00C61040 8B 55 FC             mov         edx,dword ptr [c]
00C61043 03 55 F8             add         edx,dword ptr [d]
00C61046 89 55 FC             mov         dword ptr [c],edx
	return c;
00C61049 8B 45 FC             mov         eax,dword ptr [c]
}
00C6104C 8B E5                mov         esp,ebp
00C6104E 5D                   pop         ebp
00C6104F C3                   ret


int main() {
00C61050 55                   push        ebp
00C61051 8B EC                mov         ebp,esp
00C61053 51                   push        ecx

	int x = Add(250, 50);
00C61054 6A 32                push        32h
00C61056 68 FA 00 00 00       push        0FAh
00C6105B E8 C0 FF FF FF       call        Add (0C61020h)
00C61060 83 C4 08             add         esp,8
00C61063 89 45 FC             mov         dword ptr [x],eax
	return 0;
00C61066 33 C0                xor         eax,eax
}
00C61068 8B E5                mov         esp,ebp
00C6106A 5D                   pop         ebp
00C6106B C3                   ret
*/