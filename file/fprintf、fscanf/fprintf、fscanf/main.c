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
	// ��ʽ��д���ļ�����

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
	fp = fopen("kings.json", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// ��ʽ��д������
	// fprintf
	/*
		����һ����д��������Ҫ����
		����1���ļ�ָ��
		����2����ʽ���ַ���
		����N����ʽ��ֵ��
	*/
	size_t n = sizeof(k_arr) / sizeof(Kings);
	
	for (size_t i = 0; i < n; i++)
	{
		fprintf(fp, "{ \"name\": \"%s \", \"A\": %d, \"DEF\": %d },\n", k_arr[i].name, k_arr[i].A, k_arr[i].DEF);
	}
	

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}


void test02() {
	// ��ʽ����ȡ�ļ�����

	// ���ļ�
	FILE* fp = NULL;
	fp = fopen("kings.json", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// ��ʼ���ÿ�����
	Kings k_arr[16];
	memset(k_arr, 0, sizeof(k_arr));

	// ��ʽ����ȡ
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "{ \"name\": \"%s \", \"A\": %d, \"DEF\": %d },\n", k_arr[i].name, &k_arr[i].A, &k_arr[i].DEF);
		i++;
	}

	size_t n = (size_t) i;

	for (size_t i = 0; i < n; i++)
	{
		printf("name = %s, A = %d, DEF = %d \n", k_arr[i].name, k_arr[i].A, k_arr[i].DEF);
	}

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

// �ܽ᲻�ʺ� json

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}