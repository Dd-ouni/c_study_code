#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// calloc realloc示例

void test01() {
	// calloc 的运用 与 malloc的区别
	// 区别就是calloc申请的堆是自动置0

	int* pInt = NULL;

	pInt = malloc(10 * sizeof(int));

	if (pInt == NULL) {
		perror("malloc");
		return;
	}
	int i = 0;
	while (i < 10)
	{
		printf("%d \n", *(pInt + i));
		i++;
	}
	if (pInt != NULL) {
		free(pInt);
		pInt = NULL;
	}

	pInt = calloc(10, sizeof(int));
	if (pInt == NULL) {
		perror("calloc");
		return;
	}
	i = 0;
	while (i < 10)
	{
		printf("%d \n", *(pInt + i));
		i++;
	}
	if (pInt != NULL) {
		free(pInt);
		pInt = NULL;
	}

}


void test02() {
	// realloc 重新分配堆空间
	int* pInt = calloc(10, sizeof(int));
	if (pInt == NULL) {
		perror("calloc");
		return;
	}

	// 重新分配小的堆空间 打印地址
	printf("pInt = %d \n", pInt);
	pInt = realloc(pInt, 15 * sizeof(int));
	printf("pInt = %d \n", pInt);
	for (size_t i = 0; i < 15; i++)
	{
		printf("*(pInt + %d) = %d \n", i,*(pInt + i));
	}
	// 总结打印结果，新分配的空间不是置空的
	if (pInt != NULL) {
		free(pInt);
		pInt = NULL;
	}
}

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}