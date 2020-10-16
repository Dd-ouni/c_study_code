#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void test01() {
	// 复位文件指位置 rewind
	// 实现读写模式下写完立马读取数据

	// 打开文件
	FILE* fp = NULL;
	fp = fopen("test.txt", "w+");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 写入内容
	fprintf(fp, "%s\n", "hello world");

	// 复位文件指针
	rewind(fp);

	// 读取写入内容
	char buf[128] = { 0 };
	fscanf(fp, "%s\n", buf);

	// 打印读取内容
	printf("%s\n", buf);

	// 关闭文件
	fclose(fp);
	fp = NULL;

	// 总结w+ 写入立即读取方法

}

int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}