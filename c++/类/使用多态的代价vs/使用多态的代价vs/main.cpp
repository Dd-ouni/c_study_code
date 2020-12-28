#include <iostream>
using namespace std;

class F {
public:
    F() {
        cout << "F ���캯��" << endl;
        cout << this << endl;
        this->test();
    }
    virtual F& show() {
        cout << "F show" << endl;
        return *this;
    }
    void test() {
        this->show();
    }
    virtual void autoMove(int step = 2) {
        cout << "F autoMove��" << step << endl;
    }
    virtual ~F() {
        cout << "F ��������" << endl;
        this->test();
    }
};


class S : public F {
public:
    S() {
        cout << "S ���캯��" << endl;
        cout << this << endl;
        this->test();
        F::show();
    }
    S& show() override final {
        cout << "S show" << endl;
        return *this;
    }

    void autoMove(int step = 3) {
        cout << "S autoMove��" << step << endl;
    }

    ~S() override final {
        cout << "S ��������" << endl;
        this->test();
    }
};
// ʹ�ö�̬�Ĵ���
/*  1. �ڹ��������
    ����Ĺ���˳�����ɸ��ൽ���࣬δ���������ʱ�򣬵����麯����
    ��ָ���࣬�����˸����show��ע��ֻ��ͨ��ָ�뷽ʽ���ܴﵽ�麯��������
    �������������������ʱ��Ҳһ��������������֮�󣬸������show��
    ��ʱ����ָ�����show
*/
/*
    2. �����麯���ĸ���汾
    ��ʱ�������Ҫ��������ø����麯��
    F::show(); ����::�麯��()
*/
/*
    3. Ĭ��ʵ�����麯���еĴ���
    S sa;
    F* fa = &sa;
    fa->autoMove();
    // ��� S autoMove��2 �����Ĭ��ֵ������ĺ���
*/
/*
    4. �ͷź����麯�����������
    �������ڶѿ�����һ����̬�Ӷ����
    ʹ�����delete��ȷʵ����ָ��
    F* pfa = new S;
    pfa->test();
    delete pfa;
    ��ʱ��Ȼ���������������
    (����Ҫʹ�ö�̬�麯�����ⲻ��ʹ�ø���ָ��)
    ����Ľ���취�� �麯����������� virtual ~F()
    ���еĻ���������ǿ���ͨ������ѡ����ʾ��
    ʹ��VS�ǲ�����ʾ�ģ�ʹ��Dev����ʾ
*/

void test01() {
    cout << "test" << endl;
    // ���� 1 and 2
    // S sa;
    // sa.test();

    // ����3 
    S sa;
    F* fa = &sa;
    fa->autoMove();
    // S autoMove��2

    // ����4
    /* 
    F* pfa = new S;
    pfa->test();
    delete pfa;
    */
}

int main()
{
    [] ()->void (*)() { return test01; }()();
    return 0;
}
