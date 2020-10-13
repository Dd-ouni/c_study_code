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
	// 格式化写入文件数据

	// 创建并初始化写入数据
	Kings k_arr[5] = {
		{ "亚瑟王", 50, 80 },
		{ "安琪拉", 105, 25 },
		{ "妲己", 90, 35 },
		{ "庄周", 40, 100 },
		{ "后裔", 75, 30 }
	};

	// 打开文件
	FILE* fp = NULL;
	fp = fopen("kings.json", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 格式化写入数据
	// fprintf
	/*
		不是一次性写入所以需要遍历
		参数1：文件指针
		参数2：格式化字符串
		参数N：格式化值项
	*/
	size_t n = sizeof(k_arr) / sizeof(Kings);
	
	for (size_t i = 0; i < n; i++)
	{
		fprintf(fp, "{ \"name\": \"%s \", \"A\": %d, \"DEF\": %d },\n", k_arr[i].name, k_arr[i].A, k_arr[i].DEF);
	}
	

	// 关闭文件
	fclose(fp);
	fp = NULL;
}


void test02() {
	// 格式化读取文件数据

	// 打开文件
	FILE* fp = NULL;
	fp = fopen("kings.json", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 初始化置空容器
	Kings k_arr[16];
	memset(k_arr, 0, sizeof(k_arr));

	// 格式化读取
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

	// 关闭文件
	fclose(fp);
	fp = NULL;
}

// 总结不适合 json

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}