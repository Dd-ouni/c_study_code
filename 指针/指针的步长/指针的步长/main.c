#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ָ��Ĳ���

void test01() {
	// 1. Ӱ��+N�Ĵ�С
	char* ch = NULL;
	printf("%d \n", ch);
	printf("%d \n", ch + 1);
	// �����  0 1

	short* sh = NULL;
	printf("%d \n", sh);
	printf("%d \n", sh + 1);
	printf("%d \n", sh + 2);
	// ����� 0 2 4

	int* i = NULL;
	printf("%d \n", i);
	printf("%d \n", i + 1);
	printf("%d \n", i + 3);
	// ����� 0 4 12

	// �ܽ�ָ�벽��ȡ����ָ������ 
	// char* ȥ��*

}

void test02() {
	// 2.Ӱ������õ�ȡֵ��С
	char ch[1000] = { 0 };
	int a = 1000;
	memcpy(ch, &a, sizeof(a));

	char* pCh = ch;
	// ֱ��ǿתָ�����ͣ�Ӱ��ȡֵ��ΧΪint
	printf("%d \n", *(int*)pCh);

	memcpy(ch+1, &a, sizeof(a));
	printf("%d \n", *(int*)(pCh + 1));
	// ���������޸�cpy���ڴ��ַλ�ò���+1
	// ȡֵ��ʱ������char* �Ĳ���+1����ǿתint*
}

typedef struct {
	char a;
	char b;
	int c;
} Temp;

void test03() {
	// ָ�벽����ϰ
	/*	�ṹ���С�ж�
		1 + 1 + 4 = 6
		���Ǵ���ģ������8
		��Ϊ�ڴ����
		2 + 2 + 4 = 8
	*/
	printf("%d \n", sizeof(Temp));

	Temp t = { 0 };
	Temp* pTemp = &t;
	
	char ch = 'a';
	printf("%d  %d\n", pTemp, ((char*)pTemp) + 2);
	memset(((char*)pTemp) + 1, ch, sizeof(char));
	printf("%c \n", pTemp->b);
	// ������һ�����һ��ʼ����Ϊ�ڴ����
	// a = 0 ~ 1   b = 2 ~ 3  c = 4 ~ 7
	// һ��ʼָ�벽���� + 2�� ȡֵ����һֱΪ�յ�ԭ��
	// ���Ժ��֪�� a = 0  b = 2  c = 4 ~ 7

	pTemp->c = 1000;
	printf("%d \n", *(int*)(((char*)pTemp) + 4));

}

int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}