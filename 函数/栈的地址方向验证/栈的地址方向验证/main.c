#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void test01() {
	// ջ�ĵ�ַ������֤
	// ջ�����ԣ��Ƚ����
	// �Ƚ�����ջ�ͣ��������ջ��
	int a = 10;    // ջ��		2817004
	int b = 20;	   //			2816992
	int c = 30;    //			2816980
	int d = 40;    // ջ��		2816968
	printf("%d %d %d %d\n", &a, &b, &c, &d);
	// �ܽ� ջ���Ǹߵ�ַ ջ���ǵ͵�ַ 
}

int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}