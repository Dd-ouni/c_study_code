#include <iostream>
#define MYADD(a, b) a + b
using namespace std;
void test01() {
	cout << MYADD(10, 20) << endl;
}

int main(void) {
	test01();
	return 0;
}