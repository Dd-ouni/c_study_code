#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

// 获取结构体属性偏移值
typedef struct {
	char a;       // 0
	int b;		  // 4
	char c[64];   // 8
	int d;        //72 
} Temp;

void test01() {
	Temp t = { 'a', 20, "hello world!", 1000 };
	printf("%d \n", offsetof(Temp, d));

	// 通过偏移获取d
	printf("%d \n", *(int*)(((char*)(&t)) + offsetof(Temp, d)));
	// #define offsetof(s,m) ((size_t)&(((s*)0)->m))
	printf("%d \n", (Temp*)0);   // 0 
	printf("%d \n", &(((Temp*)0)->d));  // 72
	// 总结实现原理 把0转换为 Temp* 指针之后，使用->特性
	// ->d  自动转换为 指针步进 72
}

int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}