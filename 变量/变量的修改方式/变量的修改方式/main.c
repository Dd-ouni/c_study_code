#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
// �������޸ķ�ʽ
void test01() {
	int num = 100;

	// 1.ֱ���޸�
	num = 1000;
	printf("num = %d \n", num);

	// 2.����޸�
	int* pInt = &num;
	*pInt = 10000; // ������
	printf("*pInt = %d \n", *pInt);
}

// �����޸ķ�ʽ��ǿ->����޸�
typedef struct {
	char a;
	int b;
	char c;
	int d;
}Human;

void test02() {
	Human lucy = { 'a', 10, 'b', 20 };
	// 1.ֱ���޸�
	lucy.d = 100;
	printf("lucy.d = %d \n", lucy.d);

	// 2.����޸�->ָ��
	Human* p_human = NULL;
	p_human = &lucy;
	p_human->d = 300;
	printf("p_huamn->d = %d \n", p_human->d);

	// 3.��ǿ����޸�ָ֮����
	/*	��ȶ������⣬ �����˽�ṹ�� Human�Ĵ�С
		typedef struct {
			char a;			0 ~ 3
			int b;			4 ~ 7
			char c;			8 ~ 11
			int d;			12 ~ 15
		}Human;
		�ϼ� 16�ֽ�
	*/
	printf("sizeof(Human) %d \n", sizeof(Human));
	char* pChar = (char*)&lucy;
	// char* + 1 == ��� 1 �ֽ� 
	// ��ô + 12 ��ͨ��ָ�����ͼ�ӷ���d
	printf("d = %d\n", *(int*)(pChar + 12));
}

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}