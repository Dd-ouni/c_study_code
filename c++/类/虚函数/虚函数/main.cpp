#include <iostream>
using namespace std;
// 虚函数是类成员函数多态的方法
/*
	成员函数多态可以解决什么问题呢？
	1、根据指针(原)类型调用对应子类的方法(必须是子类，并且父类的该函数是虚函数)
*/
class MoveObj {
public:
	virtual MoveObj& move() {
 		cout << "MoveObj move" << endl;
		return *this;
	}
};
class NpcObj : public MoveObj {
public:
	NpcObj& move() override final{
		cout << "NPC move" << endl;
		return *this;
	}
};
class RoleObj : public MoveObj {
public:
	RoleObj& move() override final{
		cout << "Role move" << endl;
		return *this;
	}
};
void test01() {
	NpcObj na;
	RoleObj ra;
	MoveObj* ma = &na;
	ma->move();
	MoveObj* mb = &ra;
	mb->move();
	/*
	1. MoveObj void move() { 的时候 MoveObj move
	2. MoveObj virtual void move() { 的时候 NPC move
	virtual 声明 父类MoveObj的 move 为的虚函数，子类的使用父类指针调用move会找到自动找到子类move
	以上就是多态成员函数，作用就是多个子类实例，通过转换父类调用虚函数，动态到自动找到子类move
	3. Role move
	*/

	// 也可以使用函数
	[](MoveObj* obj) {
		obj->move();
	}(ma);

	// 注意事项
	// 1.调用类的对象无法使用虚函数，其实是函数调用的时候不能用值拷贝
	[](MoveObj obj) {
		obj.move();
		// 得到的是 MoveObj move
	}(na);
	// 2.virtual 声明定义只能在类内部，不能把 virtual写在类外部定义中
	/* 3.虚函数的参数，父类和子类必须一致,NPC子类的参数不一样，
	结果打印的是 MoveObj move*/
	/*
		4.虚函数的返回值， 父子类都要求一致，但是返回 类 类型的指针和引用的时候例外
		这个叫做 协变， 父子类关系的虚函数，支持返回类 类型本身的指针或者引用
		可以返回父类类型指针 or 自身
	*/
	ma->move().move();
	// 5.虚函数不能是函数模板

	/*
	   6.继承的虚函数参数问题，如果改了参数，编译器是不会提示的，
	   调用的都是父虚函数，杜绝办法就是给继承虚函数的加上修饰符
	   override 强制要求检查函数重载
	*/

	/*
	   7.继承的虚函数，还是可以定义为虚函数的，虚函数就是供人重载
	   并且又能父类自动调用，最好是给子类修饰不要在重载
	   final 强制终止函数重载
	*/
}


int main(int argc, char* argv[]) {
	test01();
	return 0;
}