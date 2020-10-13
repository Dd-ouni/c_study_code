#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[8];
	int A;
	int DEF;
}Kings;

void test01() {
	// fwrite д�����ݿ�

	// ��������ʼ��д������
	Kings k_arr[5] = {
		{ "��ɪ��", 50, 80 },
		{ "������", 105, 25 },
		{ "槼�", 90, 35 },
		{ "ׯ��", 40, 100 },
		{ "����", 75, 30 }
	};

	// ���ļ�
	FILE* fp = NULL;
	fp = fopen("kings.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// д������
	// fwrite
	/*
		����1�� д��buf
		����2�� д����С
		����3�� д�������
		����4�� �ļ�ָ��
	*/
	fwrite(k_arr, sizeof(Kings), sizeof(k_arr) / sizeof(Kings), fp);

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

void test02() {
	// fread ��ȡ���ݿ�

	// ���ļ�
	FILE* fp = NULL;
	fp = fopen("kings.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// �����ȡ����
	Kings k_arr[20];
	// �������
	memset(k_arr, 0, sizeof(k_arr));


	// ��ȡ����
	// fread ��ȡ���ݿ�
	/*
		����1�� buf ���ݿ�����
		����2�� ��ȡ���С
		����3�� ��ȡ����
		����4�� �ļ�ָ��
		����ֵ����ȡ���������
	*/
	size_t n = fread(k_arr, sizeof(Kings), sizeof(k_arr) / sizeof(Kings), fp);

	// ��ӡ��ȡ����
	for (size_t i = 0; i < n; i++)
	{
		printf("name = %s A = %d DEF = %d \n", k_arr[i].name, k_arr[i].A, k_arr[i].DEF);
	}

	// �ر��ļ�
	fclose(fp);
	fp = NULL;

}

/*
	�ܽ᣺fwrite fread ��ԭ�������ڴ����ݵ��ļ�
	�Ƚ��ʺ������������ݣ����ߴ洢����Ҫչʾ������
*/

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}