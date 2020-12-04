#include <iostream>
#include <bitset>
using namespace std;
using LightType = unsigned int;
class LightCtrl
{
public:
    LightCtrl()
    {
        cout << "LightCtrl 构造函数" << endl;
        this->m_light = 0x0;

        // 空间大小初始化
        LightType area_size = 0xFF;
        LightType area_size_xor = 0;
        area_size_xor ^= area_size;

        // 初始台球区域
        this->m_billiards_room = 0;
        this->m_billiards_room |= (area_size <<= 24);
        cout << "台球区域 " << bitset<32>(this->m_billiards_room) << endl;

        // 重置空间大小
        area_size = area_size_xor ^ 0;

        // 初始桌游区域
        this->m_table_game_room = 0;
        this->m_table_game_room |= (area_size <<= 16);
        cout << "桌游区域 " << bitset<32>(this->m_table_game_room) << endl;

        // 重置空间大小
        area_size = area_size_xor ^ 0;

        // 初始化酒吧区域
        this->m_bar_room = 0;
        this->m_bar_room |= (area_size <<= 8);
        cout << "酒吧区域 " << bitset<32>(this->m_bar_room) << endl;

        // 初始化休息区域
        this->m_rest_room = 0xFF;
        cout << "休息区域 " << bitset<32>(this->m_rest_room) << endl;
    }
    void billiardsLightHandle()
    {
        LightType billiardsLight = this->m_billiards_room;
        billiardsLight &= this->m_light;
        billiardsLight >>= 24;
        cout << "台球区域 " << bitset<8>(billiardsLight) << endl;
    }
    void billiardsLightHandle(int pos)
    {

        if (pos <= 8 || pos >= 0)
        {
            int section = 24;
            LightType light = 1;
            light <<= pos + section;
            light &= this->m_light;
            bool ret = light % 2;
            light = 1;
            light <<= pos + section;
            cout << bitset<32>(light) << endl;
            if (ret)
            {
            }
            else
            {
            }
        }
        else
        {
            cout << "无效操作" << endl;
        }
    }
    void showAllLight()
    {
        cout << bitset<32>(this->m_light) << endl;
    }

private:
    LightType m_light;
    LightType m_billiards_room;
    LightType m_table_game_room;
    LightType m_bar_room;
    LightType m_rest_room;
};

void test01()
{
    LightCtrl boboLightCtrl;
    boboLightCtrl.billiardsLightHandle(6);
};

int main()
{
    system("clear");
    test01();
    return 0;
}
