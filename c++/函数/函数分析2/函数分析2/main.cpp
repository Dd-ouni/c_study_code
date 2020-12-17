#include <iostream>
#include <iomanip>

void Hack() {
	system("cls");
	std::cout << "test" << std::endl;
}


int GetAge() {
	int rt;
	std::cout << "请输入学员的年龄：";
	std::cin >> rt;
	return rt;
}

int count() {
	int i{};
	int total{};
	int age[10]{};
	do
	{
		age[i] = GetAge();
		total += age[i];
	} while (age[i++]);

	return total;
}

int main() {
	std::cout << "========================\n";
	std::cout << "api prt: " << Hack << std::endl;
	std::cout << "输入学员信息，遇到0结束，打印总和\n";
	std::cout << "总和：" << count();
}

/*
void Hack() {
00FB1002 EC                   in          al,dx
	system("cls");
00FB1003 68 58 31 FB 00       push        0FB3158h
00FB1008 FF 15 F0 30 FB 00    call        dword ptr ds:[00FB30F0h]
00FB100E 83 C4 04             add         esp,4
	std::cout << "test" << std::endl;
00FB1011 68 00 17 FB 00       push        0FB1700h
00FB1016 68 5C 31 FB 00       push        0FB315Ch
00FB101B A1 80 30 FB 00       mov         eax,dword ptr ds:[00FB3080h]
00FB1020 50                   push        eax
00FB1021 E8 BA 03 00 00       call        00FB13E0
00FB1026 83 C4 08             add         esp,8
00FB1029 8B C8                mov         ecx,eax
00FB102B FF 15 38 30 FB 00    call        dword ptr ds:[00FB3038h]
}
00FB1031 5D                   pop         ebp
00FB1032 C3                   ret


int GetAge() {
00FB1040 55                   push        ebp
00FB1041 8B EC                mov         ebp,esp
00FB1043 51                   push        ecx
	int rt;
	std::cout << "请输入学员的年龄：";
00FB1044 68 64 31 FB 00       push        0FB3164h
00FB1049 A1 80 30 FB 00       mov         eax,dword ptr ds:[00FB3080h]
00FB104E 50                   push        eax
00FB104F E8 8C 03 00 00       call        00FB13E0
00FB1054 83 C4 08             add         esp,8
	std::cin >> rt;
00FB1057 8D 4D FC             lea         ecx,[ebp-4]
00FB105A 51                   push        ecx
00FB105B 8B 0D 78 30 FB 00    mov         ecx,dword ptr ds:[00FB3078h]
00FB1061 FF 15 44 30 FB 00    call        dword ptr ds:[00FB3044h]
	return rt;
00FB1067 8B 45 FC             mov         eax,dword ptr [ebp-4]
}
00FB106A 8B E5                mov         esp,ebp
00FB106C 5D                   pop         ebp
00FB106D C3                   ret



int count() {
00FB1070 55                   push        ebp
00FB1071 8B EC                mov         ebp,esp
00FB1073 83 EC 34             sub         esp,34h
	int i{};
00FB1076 C7 45 FC 00 00 00 00 mov         dword ptr [ebp-4],0
	int total{};
00FB107D C7 45 F8 00 00 00 00 mov         dword ptr [ebp-8],0
	int age[10]{};
00FB1084 33 C0                xor         eax,eax
00FB1086 89 45 CC             mov         dword ptr [ebp-34h],eax
00FB1089 89 45 D0             mov         dword ptr [ebp-30h],eax
00FB108C 89 45 D4             mov         dword ptr [ebp-2Ch],eax
00FB108F 89 45 D8             mov         dword ptr [ebp-28h],eax
00FB1092 89 45 DC             mov         dword ptr [ebp-24h],eax
00FB1095 89 45 E0             mov         dword ptr [ebp-20h],eax
00FB1098 89 45 E4             mov         dword ptr [ebp-1Ch],eax
00FB109B 89 45 E8             mov         dword ptr [ebp-18h],eax
00FB109E 89 45 EC             mov         dword ptr [ebp-14h],eax
00FB10A1 89 45 F0             mov         dword ptr [ebp-10h],eax
	do
	{
		age[i] = GetAge();
00FB10A4 E8 97 FF FF FF       call        00FB1040
00FB10A9 8B 4D FC             mov         ecx,dword ptr [ebp-4]
00FB10AC 89 44 8D CC          mov         dword ptr [ebp+ecx*4-34h],eax
		total += age[i];
00FB10B0 8B 55 FC             mov         edx,dword ptr [ebp-4]
00FB10B3 8B 45 F8             mov         eax,dword ptr [ebp-8]
00FB10B6 03 44 95 CC          add         eax,dword ptr [ebp+edx*4-34h]
00FB10BA 89 45 F8             mov         dword ptr [ebp-8],eax
	} while (age[i++]);
00FB10BD 8B 4D FC             mov         ecx,dword ptr [ebp-4]
00FB10C0 8B 54 8D CC          mov         edx,dword ptr [ebp+ecx*4-34h]
00FB10C4 89 55 F4             mov         dword ptr [ebp-0Ch],edx
00FB10C7 8B 45 FC             mov         eax,dword ptr [ebp-4]
00FB10CA 83 C0 01             add         eax,1
00FB10CD 89 45 FC             mov         dword ptr [ebp-4],eax
00FB10D0 83 7D F4 00          cmp         dword ptr [ebp-0Ch],0
00FB10D4 75 CE                jne         00FB10A4

	return total;
00FB10D6 8B 45 F8             mov         eax,dword ptr [ebp-8]
}
00FB10D9 8B E5                mov         esp,ebp
00FB10DB 5D                   pop         ebp
00FB10DC C3                   ret



int main() {
003410E0 55                   push        ebp
003410E1 8B EC                mov         ebp,esp
	std::cout << "========================\n";
003410E3 68 78 31 34 00       push        343178h
003410E8 A1 80 30 34 00       mov         eax,dword ptr ds:[00343080h]
003410ED 50                   push        eax
003410EE E8 ED 02 00 00       call        003413E0
003410F3 83 C4 08             add         esp,8
	std::cout << "api prt: " << Hack << std::endl;
003410F6 68 00 17 34 00       push        341700h
003410FB 68 00 10 34 00       push        341000h
00341100 68 94 31 34 00       push        343194h
00341105 8B 0D 80 30 34 00    mov         ecx,dword ptr ds:[00343080h]
0034110B 51                   push        ecx
0034110C E8 CF 02 00 00       call        003413E0
00341111 83 C4 08             add         esp,8
00341114 8B C8                mov         ecx,eax
00341116 FF 15 40 30 34 00    call        dword ptr ds:[00343040h]
0034111C 8B C8                mov         ecx,eax
0034111E FF 15 38 30 34 00    call        dword ptr ds:[00343038h]
	std::cout << "输入学员信息，遇到0结束，打印总和\n";
00341124 68 A0 31 34 00       push        3431A0h
00341129 8B 15 80 30 34 00    mov         edx,dword ptr ds:[00343080h]
0034112F 52                   push        edx
00341130 E8 AB 02 00 00       call        003413E0
00341135 83 C4 08             add         esp,8
	std::cout << "总和：" << count();
00341138 E8 33 FF FF FF       call        00341070
0034113D 50                   push        eax
0034113E 68 C4 31 34 00       push        3431C4h
00341143 A1 80 30 34 00       mov         eax,dword ptr ds:[00343080h]
00341148 50                   push        eax
00341149 E8 92 02 00 00       call        003413E0
0034114E 83 C4 08             add         esp,8
00341151 8B C8                mov         ecx,eax
00341153 FF 15 3C 30 34 00    call        dword ptr ds:[0034303Ch]
}
00341159 33 C0                xor         eax,eax
0034115B 5D                   pop         ebp
0034115C C3                   ret
*/