#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void test01() {
	int a = 10;
	a += 20;
	int arr[5]{10};

	int* pArr = arr;
	pArr = &arr[0];
	*pArr = 20;
	arr[1] = 30;
	arr[2] = 40;
}

int main() {
		
	test01();
	return 0;
}