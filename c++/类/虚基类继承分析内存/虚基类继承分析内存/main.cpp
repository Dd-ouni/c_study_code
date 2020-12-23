#include <iostream>
using namespace std;

class GameObject {
public:
	unsigned x{0x5};
	unsigned y{0x5};
};


class Person : public virtual GameObject {
public:
	unsigned pa{ 0x100 };
	unsigned pb{ 0x200 };
};

class Wolf : public virtual GameObject {
public:
	unsigned wa{ 0x1000 };
	unsigned wb{ 0x50 };
};

class WolfPerson : public Person, public Wolf {
public:
	unsigned wpa{ 0x300 };
	unsigned wpb{ 0x250 };
};


unsigned test01(unsigned a, unsigned b) {
	a *= 2;
	b *= 2;
	return a + b;
}

int main(int argc, char* argv[]) {

	WolfPerson wp;

	unsigned ret = test01(wp.x, wp.wpa);

	cout << ret << endl;
	return 0;
}