#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 1.�򻯽ṹ��
typedef struct human{
	char name[16];
	int age;
}Human;

void test01() {
	
	struct human lucy = { "lucy", 17 };
	Human bobo = { "bobo", 21 };
}

// 2.��������

void test02() {
	char* p1, p2;
	// ��ʱ�����Ƿֱ���ʲô���ͣ� 
	printf("sizeof(p1) = %d, sizeof(p2) = %d \n", sizeof(p1), sizeof(p2));
	// ����� sizeof(p1) = 4, sizeof(p2) = 1�� 4�ֽ���ָ�����ͣ� 1�ֽ���char����
	// ������ ��ʵ��ʱ��������Ҫ�Ľ��Ӧ���� p1 �� p2 ����char* ����
	
	// ����취1 char *p1, *p2;

	// ����취2 typedef
	typedef char* pChar;
	pChar p3, p4;
	printf("sizeof(p3) = %d, sizeof(p4) = %d \n", sizeof(p3), sizeof(p4));
	// ����� sizeof(p3) = 4, sizeof(p4) = 4 
}

// 3.��ֲ����ǿ
/*
	c��������ʱ������������±�׼
	���� c89 �� c99
	���� ����ʹ�ã��ࣩܶc99���� long long ����
*/

void test03() {
	long long long1;
	long long long2;
	long long long3;
	// ��ô�����ڲ�֧�ֵ�c99�Ļ����¿����޸����е�long long
	// ��ôֻ��һ��һ����

	// ����취��typedef
	// ������ʹ���±�׼�����������͵�ʱ����ʹ�� typedef
	typedef long long LL;
	// ��ô������ֲ��ʱ��ֻ��Ҫ�޸� long long ���ɡ�
}

int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}