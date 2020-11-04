#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// calloc reallocʾ��

void test01() {
	// calloc ������ �� malloc������
	// �������calloc����Ķ����Զ���0

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
	// realloc ���·���ѿռ�
	int* pInt = calloc(10, sizeof(int));
	if (pInt == NULL) {
		perror("calloc");
		return;
	}

	// ���·���С�Ķѿռ� ��ӡ��ַ
	printf("pInt = %d \n", pInt);
	pInt = realloc(pInt, 15 * sizeof(int));
	printf("pInt = %d \n", pInt);
	for (size_t i = 0; i < 15; i++)
	{
		printf("*(pInt + %d) = %d \n", i,*(pInt + i));
	}
	// �ܽ��ӡ������·���Ŀռ䲻���ÿյ�
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