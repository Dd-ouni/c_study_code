#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void test01() {
	// ��λ�ļ�ָλ�� rewind
	// ʵ�ֶ�дģʽ��д�������ȡ����

	// ���ļ�
	FILE* fp = NULL;
	fp = fopen("test.txt", "w+");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// д������
	fprintf(fp, "%s\n", "hello world");

	// ��λ�ļ�ָ��
	rewind(fp);

	// ��ȡд������
	char buf[128] = { 0 };
	fscanf(fp, "%s\n", buf);

	// ��ӡ��ȡ����
	printf("%s\n", buf);

	// �ر��ļ�
	fclose(fp);
	fp = NULL;

	// �ܽ�w+ д��������ȡ����

}

int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}