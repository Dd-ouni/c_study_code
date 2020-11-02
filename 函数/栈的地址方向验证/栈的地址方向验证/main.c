#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void test01() {
	// 栈的地址方向验证
	// 栈的特性：先进后出
	// 先进的是栈低，后进的是栈顶
	int a = 10;    // 栈低		2817004
	int b = 20;	   //			2816992
	int c = 30;    //			2816980
	int d = 40;    // 栈顶		2816968
	printf("%d %d %d %d\n", &a, &b, &c, &d);
	// 总结 栈低是高地址 栈顶是低地址 
}

int main(int argc, char* argv[]) {
	test01();
	system("pause");
	return 0;
}