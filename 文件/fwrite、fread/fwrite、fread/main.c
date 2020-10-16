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
	// fwrite 写入数据块

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
	fp = fopen("kings.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 写入数据
	// fwrite
	/*
		参数1： 写入buf
		参数2： 写入块大小
		参数3： 写入块数量
		参数4： 文件指针
	*/
	fwrite(k_arr, sizeof(Kings), sizeof(k_arr) / sizeof(Kings), fp);

	// 关闭文件
	fclose(fp);
	fp = NULL;
}

void test02() {
	// fread 读取数据块

	// 打开文件
	FILE* fp = NULL;
	fp = fopen("kings.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 定义读取容器
	Kings k_arr[20];
	// 清空容器
	memset(k_arr, 0, sizeof(k_arr));


	// 读取数据
	// fread 读取数据块
	/*
		参数1： buf 数据块容器
		参数2： 读取块大小
		参数3： 读取数量
		参数4： 文件指针
		返回值：读取块的数量，
	*/
	size_t n = fread(k_arr, sizeof(Kings), sizeof(k_arr) / sizeof(Kings), fp);

	// 打印读取数据
	for (size_t i = 0; i < n; i++)
	{
		printf("name = %s A = %d DEF = %d \n", k_arr[i].name, k_arr[i].A, k_arr[i].DEF);
	}

	// 关闭文件
	fclose(fp);
	fp = NULL;

}

/*
	总结：fwrite fread 是原样操作内存数据到文件
	比较适合用来拷贝数据，或者存储不需要展示的数据
*/

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}