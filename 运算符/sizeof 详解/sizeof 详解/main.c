#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 1. sizeof Ϊʲô���Ǻ����������
void test01() {
	printf("%d\n", sizeof(int));
	int n = 10;
	printf("%d\n", sizeof n);
	// ����ȡ��������С��ʱ����Բ�������
	// ��������˵��sizeof�������
}

// 2. sizeof �ķ���ֵ unsigned int

void test02() {
	// ӡ֤����ֵ unsigned int

	unsigned int n = 10;
	if (n - 20 > 0) {
		printf("����0\n");
	}
	else {
		printf("С��0\n");
	}
	// ��������㣬Ϊʲô��
	// unsigned int �� int�����ʱ���ѽ��ת��Ϊ�޷���
	// �޷��Ŵ���û�и�����û�и��������0��

	// �������ʹ��%d ���Ǹ�������ӡȡ����ʽ����
	// ֵ���޷��ż��� %u
	printf("%u \n", sizeof n - 5);
}

// 3.  sizeof ������
void printfArraySize(int arr[]) { 
	// ��ת��Ϊint*  ���4
	printf("sizeof arr = %u \n", sizeof arr);
	// ���˵��Ϊʲô���鴫�ݣ�����ഫ������
}

void test03() {
	int i_arr[] = { 1,2,3,4,5,6,7,8 };
	printf("sizeof i_arr = %u \n", sizeof i_arr);
	// ���32
	printfArraySize(i_arr);
	// ��ȡ��������С��������������������Ĵ�С
}


int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}