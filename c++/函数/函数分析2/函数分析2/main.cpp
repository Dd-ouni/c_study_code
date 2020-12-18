#include <iostream>
#include <iomanip>

void Hack() {
	system("cls");
	std::cout << "Test Hack" << std::endl;
}


int GetAge() {
	int rt;
	std::cout << "Please input student age：";
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
	std::cout << "Api prt: " << Hack << std::endl;
	std::cout << "Input the student information and print the sum when 0 ends\n";
	std::cout << "result：" << count();
}

/*
void Hack() {
00B01002 EC                   in          al,dx
	system("cls");
00B01003 68 58 31 B0 00       push        0B03158h
00B01008 FF 15 F0 30 B0 00    call        dword ptr ds:[00B030F0h]
00B0100E 83 C4 04             add         esp,4
	std::cout << "Test Hack" << std::endl;
00B01011 68 00 17 B0 00       push        0B01700h
00B01016 68 5C 31 B0 00       push        0B0315Ch
00B0101B A1 80 30 B0 00       mov         eax,dword ptr ds:[00B03080h]
00B01020 50                   push        eax
00B01021 E8 BA 03 00 00       call        00B013E0
00B01026 83 C4 08             add         esp,8
00B01029 8B C8                mov         ecx,eax
00B0102B FF 15 38 30 B0 00    call        dword ptr ds:[00B03038h]
}
00B01031 5D                   pop         ebp
00B01032 C3                   ret

int GetAge() {
00B01040 55                   push        ebp
00B01041 8B EC                mov         ebp,esp
00B01043 51                   push        ecx
	int rt;
	std::cout << "Please input student age：";
00B01044 68 68 31 B0 00       push        0B03168h
00B01049 A1 80 30 B0 00       mov         eax,dword ptr ds:[00B03080h]
00B0104E 50                   push        eax
00B0104F E8 8C 03 00 00       call        00B013E0
00B01054 83 C4 08             add         esp,8
	std::cin >> rt;
00B01057 8D 4D FC             lea         ecx,[ebp-4]
00B0105A 51                   push        ecx
00B0105B 8B 0D 78 30 B0 00    mov         ecx,dword ptr ds:[00B03078h]
00B01061 FF 15 44 30 B0 00    call        dword ptr ds:[00B03044h]
	return rt;
00B01067 8B 45 FC             mov         eax,dword ptr [ebp-4]
}
00B0106A 8B E5                mov         esp,ebp
00B0106C 5D                   pop         ebp
00B0106D C3                   ret
00B0106E CC                   int         3
00B0106F CC                   int         3


int count() {
00B01070 55                   push        ebp
00B01071 8B EC                mov         ebp,esp
00B01073 83 EC 34             sub         esp,34h
	int i{};
00B01076 C7 45 FC 00 00 00 00 mov         dword ptr [ebp-4],0
	int total{};
00B0107D C7 45 F8 00 00 00 00 mov         dword ptr [ebp-8],0
	int age[10]{};
00B01084 33 C0                xor         eax,eax
00B01086 89 45 CC             mov         dword ptr [ebp-34h],eax
00B01089 89 45 D0             mov         dword ptr [ebp-30h],eax
00B0108C 89 45 D4             mov         dword ptr [ebp-2Ch],eax
00B0108F 89 45 D8             mov         dword ptr [ebp-28h],eax
00B01092 89 45 DC             mov         dword ptr [ebp-24h],eax
00B01095 89 45 E0             mov         dword ptr [ebp-20h],eax
00B01098 89 45 E4             mov         dword ptr [ebp-1Ch],eax
00B0109B 89 45 E8             mov         dword ptr [ebp-18h],eax
00B0109E 89 45 EC             mov         dword ptr [ebp-14h],eax
00B010A1 89 45 F0             mov         dword ptr [ebp-10h],eax
	do
	{
		age[i] = GetAge();
00B010A4 E8 97 FF FF FF       call        00B01040
00B010A9 8B 4D FC             mov         ecx,dword ptr [ebp-4]
00B010AC 89 44 8D CC          mov         dword ptr [ebp+ecx*4-34h],eax
		total += age[i];
00B010B0 8B 55 FC             mov         edx,dword ptr [ebp-4]
00B010B3 8B 45 F8             mov         eax,dword ptr [ebp-8]
00B010B6 03 44 95 CC          add         eax,dword ptr [ebp+edx*4-34h]
00B010BA 89 45 F8             mov         dword ptr [ebp-8],eax
	} while (age[i++]);
00B010BD 8B 4D FC             mov         ecx,dword ptr [ebp-4]
00B010C0 8B 54 8D CC          mov         edx,dword ptr [ebp+ecx*4-34h]
00B010C4 89 55 F4             mov         dword ptr [ebp-0Ch],edx
00B010C7 8B 45 FC             mov         eax,dword ptr [ebp-4]
00B010CA 83 C0 01             add         eax,1
00B010CD 89 45 FC             mov         dword ptr [ebp-4],eax
00B010D0 83 7D F4 00          cmp         dword ptr [ebp-0Ch],0
00B010D4 75 CE                jne         00B010A4

	return total;
00B010D6 8B 45 F8             mov         eax,dword ptr [ebp-8]
}
00B010D9 8B E5                mov         esp,ebp
00B010DB 5D                   pop         ebp
00B010DC C3                   ret



int main() {
00B010E0 55                   push        ebp
00B010E1 8B EC                mov         ebp,esp
	std::cout << "========================\n";
00B010E3 68 84 31 B0 00       push        0B03184h
00B010E8 A1 80 30 B0 00       mov         eax,dword ptr ds:[00B03080h]
00B010ED 50                   push        eax
00B010EE E8 ED 02 00 00       call        00B013E0
00B010F3 83 C4 08             add         esp,8
	std::cout << "Api prt: " << Hack << std::endl;
00B010F6 68 00 17 B0 00       push        0B01700h
00B010FB 68 00 10 B0 00       push        0B01000h
00B01100 68 A0 31 B0 00       push        0B031A0h
00B01105 8B 0D 80 30 B0 00    mov         ecx,dword ptr ds:[00B03080h]
00B0110B 51                   push        ecx
00B0110C E8 CF 02 00 00       call        00B013E0
00B01111 83 C4 08             add         esp,8
00B01114 8B C8                mov         ecx,eax
00B01116 FF 15 40 30 B0 00    call        dword ptr ds:[00B03040h]
00B0111C 8B C8                mov         ecx,eax
00B0111E FF 15 38 30 B0 00    call        dword ptr ds:[00B03038h]
	std::cout << "Input the student information and print the sum when 0 ends\n";
00B01124 68 AC 31 B0 00       push        0B031ACh
00B01129 8B 15 80 30 B0 00    mov         edx,dword ptr ds:[00B03080h]
00B0112F 52                   push        edx
00B01130 E8 AB 02 00 00       call        00B013E0
00B01135 83 C4 08             add         esp,8
	std::cout << "result：" << count();
00B01138 E8 33 FF FF FF       call        00B01070
00B0113D 50                   push        eax
00B0113E 68 EC 31 B0 00       push        0B031ECh
00B01143 A1 80 30 B0 00       mov         eax,dword ptr ds:[00B03080h]
00B01148 50                   push        eax
00B01149 E8 92 02 00 00       call        00B013E0
00B0114E 83 C4 08             add         esp,8
00B01151 8B C8                mov         ecx,eax
00B01153 FF 15 3C 30 B0 00    call        dword ptr ds:[00B0303Ch]
}
00B01159 33 C0                xor         eax,eax
00B0115B 5D                   pop         ebp
00B0115C C3                   ret
*/


/*
void Hack() {
00B01002 EC                   in          al,dx
	system("cls");
00B01003 68 58 31 B0 00       push        0B03158h
00B01008 FF 15 F0 30 B0 00    call        dword ptr [__imp__system (0B030F0h)]
00B0100E 83 C4 04             add         esp,4
	std::cout << "Test Hack" << std::endl;
00B01011 68 00 17 B0 00       push        offset std::endl<char,std::char_traits<char> > (0B01700h)
00B01016 68 5C 31 B0 00       push        0B0315Ch
00B0101B A1 80 30 B0 00       mov         eax,dword ptr [__imp_std::cout (0B03080h)]
00B01020 50                   push        eax
00B01021 E8 BA 03 00 00       call        std::operator<<<std::char_traits<char> > (0B013E0h)
00B01026 83 C4 08             add         esp,8
00B01029 8B C8                mov         ecx,eax
00B0102B FF 15 38 30 B0 00    call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0B03038h)]
}
00B01031 5D                   pop         ebp
00B01032 C3                   ret


int GetAge() {
00B01040 55                   push        ebp
00B01041 8B EC                mov         ebp,esp
00B01043 51                   push        ecx
	int rt;
	std::cout << "Please input student age��";
00B01044 68 68 31 B0 00       push        0B03168h
00B01049 A1 80 30 B0 00       mov         eax,dword ptr [__imp_std::cout (0B03080h)]
00B0104E 50                   push        eax
00B0104F E8 8C 03 00 00       call        std::operator<<<std::char_traits<char> > (0B013E0h)
00B01054 83 C4 08             add         esp,8
	std::cin >> rt;
00B01057 8D 4D FC             lea         ecx,[rt]
00B0105A 51                   push        ecx
00B0105B 8B 0D 78 30 B0 00    mov         ecx,dword ptr [__imp_std::cin (0B03078h)]
00B01061 FF 15 44 30 B0 00    call        dword ptr [__imp_std::basic_istream<char,std::char_traits<char> >::operator>> (0B03044h)]
	return rt;
00B01067 8B 45 FC             mov         eax,dword ptr [rt]
}
00B0106A 8B E5                mov         esp,ebp
00B0106C 5D                   pop         ebp
00B0106D C3                   ret
00B0106E CC                   int         3
00B0106F CC                   int         3


int count() {
00B01070 55                   push        ebp
00B01071 8B EC                mov         ebp,esp
00B01073 83 EC 34             sub         esp,34h
	int i{};
00B01076 C7 45 FC 00 00 00 00 mov         dword ptr [i],0
	int total{};
00B0107D C7 45 F8 00 00 00 00 mov         dword ptr [total],0
	int age[10]{};
00B01084 33 C0                xor         eax,eax
00B01086 89 45 CC             mov         dword ptr [age],eax
00B01089 89 45 D0             mov         dword ptr [ebp-30h],eax
00B0108C 89 45 D4             mov         dword ptr [ebp-2Ch],eax
00B0108F 89 45 D8             mov         dword ptr [ebp-28h],eax
00B01092 89 45 DC             mov         dword ptr [ebp-24h],eax
00B01095 89 45 E0             mov         dword ptr [ebp-20h],eax
00B01098 89 45 E4             mov         dword ptr [ebp-1Ch],eax
00B0109B 89 45 E8             mov         dword ptr [ebp-18h],eax
00B0109E 89 45 EC             mov         dword ptr [ebp-14h],eax
00B010A1 89 45 F0             mov         dword ptr [ebp-10h],eax
	do
	{
		age[i] = GetAge();
00B010A4 E8 97 FF FF FF       call        GetAge (0B01040h)
00B010A9 8B 4D FC             mov         ecx,dword ptr [i]
00B010AC 89 44 8D CC          mov         dword ptr age[ecx*4],eax
		total += age[i];
00B010B0 8B 55 FC             mov         edx,dword ptr [i]
00B010B3 8B 45 F8             mov         eax,dword ptr [total]
00B010B6 03 44 95 CC          add         eax,dword ptr age[edx*4]
00B010BA 89 45 F8             mov         dword ptr [total],eax
	} while (age[i++]);
00B010BD 8B 4D FC             mov         ecx,dword ptr [i]
00B010C0 8B 54 8D CC          mov         edx,dword ptr age[ecx*4]
00B010C4 89 55 F4             mov         dword ptr [ebp-0Ch],edx
00B010C7 8B 45 FC             mov         eax,dword ptr [i]
00B010CA 83 C0 01             add         eax,1
00B010CD 89 45 FC             mov         dword ptr [i],eax
00B010D0 83 7D F4 00          cmp         dword ptr [ebp-0Ch],0
00B010D4 75 CE                jne         count+34h (0B010A4h)

	return total;
00B010D6 8B 45 F8             mov         eax,dword ptr [total]
}
00B010D9 8B E5                mov         esp,ebp
00B010DB 5D                   pop         ebp
00B010DC C3                   ret




int main() {
00B010E0 55                   push        ebp
00B010E1 8B EC                mov         ebp,esp
	std::cout << "========================\n";
00B010E3 68 84 31 B0 00       push        0B03184h
00B010E8 A1 80 30 B0 00       mov         eax,dword ptr [__imp_std::cout (0B03080h)]
00B010ED 50                   push        eax
00B010EE E8 ED 02 00 00       call        std::operator<<<std::char_traits<char> > (0B013E0h)
00B010F3 83 C4 08             add         esp,8
	std::cout << "Api prt: " << Hack << std::endl;
00B010F6 68 00 17 B0 00       push        offset std::endl<char,std::char_traits<char> > (0B01700h)
00B010FB 68 00 10 B0 00       push        offset Hack (0B01000h)
00B01100 68 A0 31 B0 00       push        0B031A0h
00B01105 8B 0D 80 30 B0 00    mov         ecx,dword ptr [__imp_std::cout (0B03080h)]
00B0110B 51                   push        ecx
00B0110C E8 CF 02 00 00       call        std::operator<<<std::char_traits<char> > (0B013E0h)
00B01111 83 C4 08             add         esp,8
00B01114 8B C8                mov         ecx,eax
00B01116 FF 15 40 30 B0 00    call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0B03040h)]
00B0111C 8B C8                mov         ecx,eax
00B0111E FF 15 38 30 B0 00    call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0B03038h)]
	std::cout << "Input the student information and print the sum when 0 ends\n";
00B01124 68 AC 31 B0 00       push        0B031ACh
00B01129 8B 15 80 30 B0 00    mov         edx,dword ptr [__imp_std::cout (0B03080h)]
00B0112F 52                   push        edx
00B01130 E8 AB 02 00 00       call        std::operator<<<std::char_traits<char> > (0B013E0h)
00B01135 83 C4 08             add         esp,8
	std::cout << "result��" << count();
00B01138 E8 33 FF FF FF       call        count (0B01070h)
00B0113D 50                   push        eax
00B0113E 68 EC 31 B0 00       push        0B031ECh
00B01143 A1 80 30 B0 00       mov         eax,dword ptr [__imp_std::cout (0B03080h)]
00B01148 50                   push        eax
00B01149 E8 92 02 00 00       call        std::operator<<<std::char_traits<char> > (0B013E0h)
00B0114E 83 C4 08             add         esp,8
00B01151 8B C8                mov         ecx,eax
00B01153 FF 15 3C 30 B0 00    call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0B0303Ch)]
}
00B01159 33 C0                xor         eax,eax
00B0115B 5D                   pop         ebp
00B0115C C3                   ret
*/