#include <iostream>
using namespace std;

void hack() {
	cout << "hello hack" << endl;
}

int count() {

	int arr[10]{};

	return 1000;
}

int main() {

	cout << hack << endl;
	int cc{ count() };
	cout << cc;
	return 0;
}