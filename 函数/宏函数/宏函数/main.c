#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 宏函数
#define MYADD(x, y) x + y
#define MYADD2(x, y) ((x) + (y))
void test01() {
	
	printf("%d \n", MYADD(10, 20));
	// 结果是预料中的 30

	printf("%d \n", MYADD(10, 20) * 30);
	// 预想是900，残酷的结果却是610
	// 为什么？因为宏定义
	// 宏定义是在预编译阶段把 
	// MYADD(10, 20) * 30  == 10 + 20 * 30
	// 解决这个问题 #define MYADD(x, y) ((x) + (y))
	printf("%d \n", MYADD2(10, 20) * 30);
	// 结果900

	// 宏函数
	// 注意：保证运算的完整性
	// 使用场景：短小的运算
	// 优点：以空间换时间，通过宏替换空间变大
	// 减少了普通函数参数如栈的消耗
}


int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}