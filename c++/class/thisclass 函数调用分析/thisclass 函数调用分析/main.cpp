#include <iostream>
class Role {
public:
	int hp;
	int mp;
	int calcTotal(int a,  int b) {
		this->hp = 100;
		mp = 200;
		return this->hp + mp + a + b;
	}
};



int main() {

	Role r;
	int total = r.calcTotal(10, 20);

	std::cout << total << std::endl;
	return 0;
}