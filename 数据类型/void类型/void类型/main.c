#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 无类型 void 使用

// 1. 无类型变量

void test01() {
	// void n = 10;
	// 无法使用，因为编译器不知道该分配多少内存空间给void类型
}

// 2. 声明返回值和函数参数
fun() {
	return 10;
}
void fun2(void) {
	return 10;
}
void test02() {
	printf("%d\n", fun());
	// 结果10
	/*
		如果不需要返回值,使用 void声明返回值
		是种好习惯，因为C语言不够严谨
		这样子编译器会提示错误，我们能根据提示修改代码
	*/
	// printf("%d\n", fun2()); //报错无法通过

	// 传参声明
	fun(10, 10);
	// 可以跑通，不严谨导致

	fun2(10, 10);
	// 警告提示
}

// 3. void* 万能指针

void test03() {
	// void* 如何体现万能？

	// 当我们定义两个不同类型的指针赋值的时候
	// 不同类型需要强制
	// void* 不用强转即可付给任何指针类型

	int* pInt = NULL;
	char* pChar = NULL;

	// pInt = pChar; 错误不兼容

	// 解决办法 强转
	pInt = (int*)pChar; 

	// 万能指针的体现
	void* pVoid = NULL;
	pInt = pVoid;  // 无需强转
}


int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}