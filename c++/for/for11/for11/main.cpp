#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void test01() {
	int arr[]{ 65, 66, 67, 68, 69 };
	for (char ch : arr) {
		cout << ch << endl;
	}
	// c11  ���������ԣ� ��ݣ����ö�̬��ȡ���Ⱥ����ñ�������

	for (auto i : arr)
		cout << i << endl;

	// auto �Զ������� arr ����
}

int main(int argc, char* argv[]) {
	test01();
	return 0;
}