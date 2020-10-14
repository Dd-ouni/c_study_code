#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
	�ļ�����
	32				8
	93				12
	12		->		32
	8				78
	78				93

*/

#define LINE 10

void creFile() {
	// ����������ļ�
	// �������������
	srand(time(0));

    // ���ļ�

	FILE* fp = NULL;
	fp = fopen("sort_before.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// д������
	int i = LINE;
	while (i > 0)
	{
		//printf("%d \n", rand() % 100 + 1);
		fprintf(fp, "%d\n", rand() % 100 + 1);
		i--;
	}

	fclose(fp);
	fp = NULL;
}

void sortFile() {
	// ��������
	int i_arr[10] = { 0 };

	// ��ȡ�ļ�����
	FILE* fp = NULL;
	fp = fopen("sort_before.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	size_t i = 0;
	while (i < LINE)
	{
		fscanf(fp, "%d\n", &i_arr[i]);
		//printf("%d\n", i_arr[i]);
		i++;
	}

	fclose(fp);
	fp = NULL;

	// ѭ������
	for (i = 0; i < LINE; i++)
	{
		for (size_t j = 0; j < LINE - (i + 1); j++)
		{
			if (i_arr[j] > i_arr[j + 1]) {
				int z = i_arr[j];
				i_arr[j] = i_arr[j + 1];
				i_arr[j + 1] = z;
			}
		}
	}

	// д�뵽������ļ�
	fp = fopen("sort_after.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// д�뵽�ļ�
	i = 0;
	while (i < LINE)
	{
		fprintf(fp, "%d\n", i_arr[i]);
		i++;
	}

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

int main(int argc, char* argv[]) {
	sortFile();
	system("pause");
	return 0;
}