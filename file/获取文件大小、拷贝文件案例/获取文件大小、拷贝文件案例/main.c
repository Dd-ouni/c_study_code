#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getFileSize(char* file_name) {
	// ��ȡ�ļ���С˼·
	// 1.��λ�ļ���ָ�뵽�ļ�β��
	// 2.��ȡ�ļ���ָ�뵱ǰ��λ�� ���ļ���С

	// ���ļ�
	FILE* fp = NULL;
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// ��λ�ļ���ָ�뵽β��
	int ret = fseek(fp, 0, 2);
	if (ret == -1) {
		perror("fseek");
		fclose(fp);
		fp = NULL;
		return;
	}

	// ��ȡ�ļ�����ǰλ�ã����β��Ҳ�����ļ���С
	long file_size = ftell(fp);

	printf("%s �Ĵ�С�� %ld\n", file_name, file_size);

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}


void logFile(char* file_name) {
	// �����ļ�˼·
	// 1.��ȡ�ļ���С
	// 2.�鼶�ļ���д���������ļ�

	// ��ȡ�ļ���С
	FILE* fp = NULL;
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	//��ȡ�ļ���С
	fseek(fp, 0, 2);
	long file_size = ftell(fp);

	// �����ļ�
	// +1 �������ļ���β0
	char* buf = NULL;
	buf = (char*)malloc(file_size+1);
	memset(buf, 0, file_size + 1);
	
	// ��λ�ļ���ָ��
	rewind(fp);

	// ��ȡ�ļ����ݣ� �鼶
	fread(buf, file_size, 1, fp);

	printf("%s\n", buf);

	// �����
	if (buf != NULL) {
		free(buf);
		buf = NULL;
	}

	// �ر��ļ�
	fclose(fp);
	fp = NULL;
}

int main(int argc, char* argv[]) {
	logFile(argv[1]);
	system("pause");
	return 0;
}