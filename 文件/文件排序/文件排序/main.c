#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
	文件排序
	32				8
	93				12
	12		->		32
	8				78
	78				93

*/

#define LINE 10

void creFile() {
	// 随机数生成文件
	// 设置随机数种子
	srand(time(0));

    // 打开文件

	FILE* fp = NULL;
	fp = fopen("sort_before.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 写入数据
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
	// 排序容器
	int i_arr[10] = { 0 };

	// 读取文件数据
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

	// 循环排序
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

	// 写入到排序后文件
	fp = fopen("sort_after.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 写入到文件
	i = 0;
	while (i < LINE)
	{
		fprintf(fp, "%d\n", i_arr[i]);
		i++;
	}

	// 关闭文件
	fclose(fp);
	fp = NULL;
}

int main(int argc, char* argv[]) {
	sortFile();
	system("pause");
	return 0;
}