#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 1. sizeof 为什么不是函数是运算符
void test01() {
	printf("%d\n", sizeof(int));
	int n = 10;
	printf("%d\n", sizeof n);
	// 当获取变量名大小的时候可以不加括号
	// 不加括号说明sizeof是运算符
}

// 2. sizeof 的返回值 unsigned int

void test02() {
	// 印证返回值 unsigned int

	unsigned int n = 10;
	if (n - 20 > 0) {
		printf("大于0\n");
	}
	else {
		printf("小于0\n");
	}
	// 结果大于零，为什么？
	// unsigned int 与 int运算的时候会把结果转换为无符号
	// 无符号代表没有负数，没有负数结果比0大

	// 这里如果使用%d 还是负数，打印取决格式化符
	// 值是无符号即用 %u
	printf("%u \n", sizeof n - 5);
}

// 3.  sizeof 的运用
void printfArraySize(int arr[]) { 
	// 被转换为int*  结果4
	printf("sizeof arr = %u \n", sizeof arr);
	// 这就说明为什么数组传递，都会多传个长度
}

void test03() {
	int i_arr[] = { 1,2,3,4,5,6,7,8 };
	printf("sizeof i_arr = %u \n", sizeof i_arr);
	// 结果32
	printfArraySize(i_arr);
	// 获取数组名大小，数组名代表整个数组的大小
}


int main(int argc, char* argv[]) {
	test03();
	system("pause");
	return 0;
}