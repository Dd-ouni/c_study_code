#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
// 变量的修改方式
void test01() {
	int num = 100;

	// 1.直接修改
	num = 1000;
	printf("num = %d \n", num);

	// 2.间接修改
	int* pInt = &num;
	*pInt = 10000; // 解引用
	printf("*pInt = %d \n", *pInt);
}

// 变量修改方式加强->间接修改
typedef struct {
	char a;
	int b;
	char c;
	int d;
}Human;

void test02() {
	Human lucy = { 'a', 10, 'b', 20 };
	// 1.直接修改
	lucy.d = 100;
	printf("lucy.d = %d \n", lucy.d);

	// 2.间接修改->指针
	Human* p_human = NULL;
	p_human = &lucy;
	p_human->d = 300;
	printf("p_huamn->d = %d \n", p_human->d);

	// 3.加强间接修改之指针跨度
	/*	宽度对齐问题， 首先了解结构体 Human的大小
		typedef struct {
			char a;			0 ~ 3
			int b;			4 ~ 7
			char c;			8 ~ 11
			int d;			12 ~ 15
		}Human;
		合计 16字节
	*/
	printf("sizeof(Human) %d \n", sizeof(Human));
	char* pChar = (char*)&lucy;
	// char* + 1 == 跨度 1 字节 
	// 那么 + 12 即通过指针类型间接访问d
	printf("d = %d\n", *(int*)(pChar + 12));
}

int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}