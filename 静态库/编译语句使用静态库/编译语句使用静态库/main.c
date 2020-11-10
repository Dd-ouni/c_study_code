#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "StaticLib1.h"
#pragma comment(lib,"./libtest.lib")
int main(int argc, char* argv[]) {
	printf("hello world! %d\n", add(10, 20));
	system("pause");
	return 0;
}