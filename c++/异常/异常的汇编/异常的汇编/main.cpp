#include <iostream>
using namespace std;
class MyException {
public:
	void printfErr() {
		cout << "MyException" << endl;
	}
};


void func() {
	throw MyException();
}

void test01() {

	try
	{
		func();
	}
	catch (MyException e)
	{
		cout << "�Զ����쳣" << endl;
	}

}


int main() {
	test01();
	return 0;
}