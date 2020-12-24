#include <iostream>
using namespace std;
// �麯�������Ա������̬�ķ���
/*
	��Ա������̬���Խ��ʲô�����أ�
	1������ָ��(ԭ)���͵��ö�Ӧ����ķ���(���������࣬���Ҹ���ĸú������麯��)
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
	1. MoveObj void move() { ��ʱ�� MoveObj move
	2. MoveObj virtual void move() { ��ʱ�� NPC move
	virtual ���� ����MoveObj�� move Ϊ���麯���������ʹ�ø���ָ�����move���ҵ��Զ��ҵ�����move
	���Ͼ��Ƕ�̬��Ա���������þ��Ƕ������ʵ����ͨ��ת����������麯������̬���Զ��ҵ�����move
	3. Role move
	*/

	// Ҳ����ʹ�ú���
	[](MoveObj* obj) {
		obj->move();
	}(ma);

	// ע������
	// 1.������Ķ����޷�ʹ���麯������ʵ�Ǻ������õ�ʱ������ֵ����
	[](MoveObj obj) {
		obj.move();
		// �õ����� MoveObj move
	}(na);
	// 2.virtual ��������ֻ�������ڲ������ܰ� virtualд�����ⲿ������
	/* 3.�麯���Ĳ�����������������һ��,NPC����Ĳ�����һ����
	�����ӡ���� MoveObj move*/
	/*
		4.�麯���ķ���ֵ�� �����඼Ҫ��һ�£����Ƿ��� �� ���͵�ָ������õ�ʱ������
		������� Э�䣬 �������ϵ���麯����֧�ַ����� ���ͱ����ָ���������
		���Է��ظ�������ָ�� or ����
	*/
	ma->move().move();
	// 5.�麯�������Ǻ���ģ��

	/*
	   6.�̳е��麯���������⣬������˲������������ǲ�����ʾ�ģ�
	   ���õĶ��Ǹ��麯�����ž��취���Ǹ��̳��麯���ļ������η�
	   override ǿ��Ҫ���麯������
	*/

	/*
	   7.�̳е��麯�������ǿ��Զ���Ϊ�麯���ģ��麯�����ǹ�������
	   �������ܸ����Զ����ã�����Ǹ��������β�Ҫ������
	   final ǿ����ֹ��������
	*/
}


int main(int argc, char* argv[]) {
	test01();
	return 0;
}