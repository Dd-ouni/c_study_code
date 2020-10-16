#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 1.简化结构体
typedef struct human{
	char name[16];
	int age;
}Human;

void test01() {
	
	struct human lucy = { "lucy", 17 };
	Human bobo = { "bobo", 21 };
}

// 2.区分类型

void test02() {
	char* p1, p2;
	// 这时候他们分别是什么类型？ 
	printf("sizeof(p1) = %d, sizeof(p2) = %d \n", sizeof(p1), sizeof(p2));
	// 结果： sizeof(p1) = 4, sizeof(p2) = 1。 4字节是指针类型， 1字节是char类型
	// 分析： 其实有时候定义者想要的结果应该是 p1 和 p2 都是char* 类型
	
	// 解决办法1 char *p1, *p2;

	// 解决办法2 typedef
	typedef char* pChar;
	pChar p3, p4;
	printf("sizeof(p3) = %d, sizeof(p4) = %d \n", sizeof(p3), sizeof(p4));
	// 结果： sizeof(p3) = 4, sizeof(p4) = 4 
}

// 3.移植性增强
/*
	c语言随着时间增加提出了新标准
	例如 c89 和 c99
	假如 我们使用（很多）c99特性 long long 类型
*/

void test03() {
	long long long1;
	long long long2;
	long long long3;
	// 那么我们在不支持的c99的环境下可能修改所有的long long
	// 那么只能一个一个改

	// 解决办法：typedef
	// 我们在使用新标准的新特性类型的时候尽量使用 typedef
	typedef long long LL;
	// 那么我们移植的时候只需要修改 long long 即可。
}

int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}