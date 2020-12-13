#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void test01() {
	int arr[]{ 65, 66, 67, 68, 69 };
	for (char ch : arr) {
		cout << ch << endl;
	}
	// c11  数组型特性， 便捷，不用动态获取长度和设置遍历条件

	for (auto i : arr)
		cout << i << endl;

	// auto 自动解析到 arr 属性
}

int main(int argc, char* argv[]) {
	test01();
	return 0;
}