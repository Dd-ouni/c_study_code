#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getFileSize(char* file_name) {
	// 获取文件大小思路
	// 1.定位文件流指针到文件尾部
	// 2.获取文件流指针当前的位置 即文件大小

	// 打开文件
	FILE* fp = NULL;
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 定位文件流指针到尾部
	int ret = fseek(fp, 0, 2);
	if (ret == -1) {
		perror("fseek");
		fclose(fp);
		fp = NULL;
		return;
	}

	// 获取文件流当前位置，结合尾部也就是文件大小
	long file_size = ftell(fp);

	printf("%s 的大小： %ld\n", file_name, file_size);

	// 关闭文件
	fclose(fp);
	fp = NULL;
}


void logFile(char* file_name) {
	// 拷贝文件思路
	// 1.获取文件大小
	// 2.块级文件读写创建拷贝文件

	// 获取文件大小
	FILE* fp = NULL;
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	//获取文件大小
	fseek(fp, 0, 2);
	long file_size = ftell(fp);

	// 拷贝文件
	// +1 是用来文件结尾0
	char* buf = NULL;
	buf = (char*)malloc(file_size+1);
	memset(buf, 0, file_size + 1);
	
	// 复位文件流指针
	rewind(fp);

	// 读取文件内容， 块级
	fread(buf, file_size, 1, fp);

	printf("%s\n", buf);

	// 清除堆
	if (buf != NULL) {
		free(buf);
		buf = NULL;
	}

	// 关闭文件
	fclose(fp);
	fp = NULL;
}

int main(int argc, char* argv[]) {
	logFile(argv[1]);
	system("pause");
	return 0;
}