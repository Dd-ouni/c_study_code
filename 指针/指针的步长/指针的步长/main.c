#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 指针的步长

void test01() {
	// 1. 影响+N的大小
	char* ch = NULL;
	printf("%d \n", ch);
	printf("%d \n", ch + 1);
	// 结果是  0 1

	short* sh = NULL;
	printf("%d \n", sh);
	printf("%d \n", sh + 1);
	printf("%d \n", sh + 2);
	// 结果是 0 2 4

	int* i = NULL;
	printf("%d \n", i);
	printf("%d \n", i + 1);
	printf("%d \n", i + 3);
	// 结果是 0 4 12

	// 总结指针步长取决于指针类型 
	// char* 去掉*

}

void test02() {
	// 2.影响解引用的取值大小
	char ch[1000] = { 0 };
	int a = 1000;
	memcpy(ch, &a, sizeof(a));

	char* pCh = ch;
	// 直接强转指针类型，影响取值范围为int
	printf("%d \n", *(int*)pCh);

	memcpy(ch+1, &a, sizeof(a));
	printf("%d \n", *(int*)(pCh + 1));
	// 这里现是修改cpy的内存地址位置步长+1
	// 取值的时候先是char* 的步长+1，在强转int*
}

typedef struct {
	char a;
	char b;
	int c;
} Temp;

void test03() {
	// 指针步长练习
	/*	结构体大小判断
		1 + 1 + 4 = 6
		答案是错误的，结果是8
		因为内存对齐
		2 + 2 + 4 = 8
	*/
	printf("%d \n", sizeof(Temp));

	Temp t = { 0 };
	Temp* pTemp = &t;
	
	char ch = 'a';
	printf("%d  %d\n", pTemp, ((char*)pTemp) + 2);
	memset(((char*)pTemp) + 1, ch, sizeof(char));
	printf("%c \n", pTemp->b);
	// 这里有一个误会一开始，以为内存对齐
	// a = 0 ~ 1   b = 2 ~ 3  c = 4 ~ 7
	// 一开始指针步长是 + 2， 取值出来一直为空的原因
	// 测试后才知道 a = 0  b = 2  c = 4 ~ 7

	pTemp->c = 1000;
	printf("%d \n", *(int*)(((char*)pTemp) + 4));

}

int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}