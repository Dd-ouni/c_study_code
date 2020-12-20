#include <iostream>
using namespace std;
extern "C" {
#include "c_code.h"
}

int getPVer() {
	return 2;
}

int main() {
	cout << getVer() << endl;
	return 0;
}