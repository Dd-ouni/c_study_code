#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// �꺯��
#define MYADD(x, y) x + y
#define MYADD2(x, y) ((x) + (y))
void test01() {
	
	printf("%d \n", MYADD(10, 20));
	// �����Ԥ���е� 30

	printf("%d \n", MYADD(10, 20) * 30);
	// Ԥ����900���п�Ľ��ȴ��610
	// Ϊʲô����Ϊ�궨��
	// �궨������Ԥ����׶ΰ� 
	// MYADD(10, 20) * 30  == 10 + 20 * 30
	// ���������� #define MYADD(x, y) ((x) + (y))
	printf("%d \n", MYADD2(10, 20) * 30);
	// ���900

	// �꺯��
	// ע�⣺��֤�����������
	// ʹ�ó�������С������
	// �ŵ㣺�Կռ任ʱ�䣬ͨ�����滻�ռ���
	// ��������ͨ����������ջ������
}


int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}