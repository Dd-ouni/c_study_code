#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// ������ void ʹ��

// 1. �����ͱ���

void test01() {
	// void n = 10;
	// �޷�ʹ�ã���Ϊ��������֪���÷�������ڴ�ռ��void����
}

// 2. ��������ֵ�ͺ�������
fun() {
	return 10;
}
void fun2(void) {
	return 10;
}
void test02() {
	printf("%d\n", fun());
	// ���10
	/*
		�������Ҫ����ֵ,ʹ�� void��������ֵ
		���ֺ�ϰ�ߣ���ΪC���Բ����Ͻ�
		�����ӱ���������ʾ���������ܸ�����ʾ�޸Ĵ���
	*/
	// printf("%d\n", fun2()); //�����޷�ͨ��

	// ��������
	fun(10, 10);
	// ������ͨ�����Ͻ�����

	fun2(10, 10);
	// ������ʾ
}

// 3. void* ����ָ��

void test03() {
	// void* ����������ܣ�

	// �����Ƕ���������ͬ���͵�ָ�븳ֵ��ʱ��
	// ��ͬ������Ҫǿ��
	// void* ����ǿת���ɸ����κ�ָ������

	int* pInt = NULL;
	char* pChar = NULL;

	// pInt = pChar; ���󲻼���

	// ����취 ǿת
	pInt = (int*)pChar; 

	// ����ָ�������
	void* pVoid = NULL;
	pInt = pVoid;  // ����ǿת
}


int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}