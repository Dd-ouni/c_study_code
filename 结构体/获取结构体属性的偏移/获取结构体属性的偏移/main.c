#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

// ��ȡ�ṹ������ƫ��ֵ
typedef struct {
	char a;       // 0
	int b;		  // 4
	char c[64];   // 8
	int d;        //72 
} Temp;

void test01() {
	Temp t = { 'a', 20, "hello world!", 1000 };
	printf("%d \n", offsetof(Temp, d));

	// ͨ��ƫ�ƻ�ȡd
	printf("%d \n", *(int*)(((char*)(&t)) + offsetof(Temp, d)));
	// #define offsetof(s,m) ((size_t)&(((s*)0)->m))
	printf("%d \n", (Temp*)0);   // 0 
	printf("%d \n", &(((Temp*)0)->d));  // 72
	// �ܽ�ʵ��ԭ�� ��0ת��Ϊ Temp* ָ��֮��ʹ��->����
	// ->d  �Զ�ת��Ϊ ָ�벽�� 72
}

int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}