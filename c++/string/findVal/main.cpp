#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void test01() {

  string str{"username=admin&password=123456&email=1康康@qq.com"};
  str+="&";

  string findArr[]{"username", "password", "email"};

  for (auto itemStr : findArr)
  {
    string findBefore = itemStr + "=";
    // 查找要查找字段的位置
    int pos = (int)(str.find(findBefore) + findBefore.size());
    cout << itemStr;
    cout << " ";
    cout << pos;
    cout << " ";
    cout << str.find("&", pos);
    cout << " ";
    cout << str.substr(pos, str.find("&", pos) - pos) << endl;
    // substr 
  }
  /*
  username 9 14 admin
  password 24 30 123456
  email 37 49 1康康@qq.com
  */
}

void test02() {
  // 计算中英混合string 个数

  // abc你好
  // 这里正确的是5个， 但是因为 你好各自占2个 这里取到的是 7

  string str{"abc你好"};
  // strlen 需要使用C头文件 string.h to c++ cstring
  cout << "str len：" << strlen(str.c_str()) << endl;
  // 7

  /*  计算思路
    c/c++ 的字符的关系
    
    内存到屏幕： 二进制 -> 编码表 -> 字符
    键盘到内存： 字符 -> 编码表 -> 二进制

    所以表编码表有很多，英文的编码表是ASCALL码 0-127
    而中国的比如 GBK 
  */

  // 1. 打印GBK编码的返回

  /*
    size_t i = 0;
    while (str[i])
    {
      cout << (int)(str[i]) << endl;    
      ++i;
    }
  97
  98
  99
  -60
  -29
  -70
  -61     可以看出什么 你好分别都是小与0
  */

  //2. 获取长度
  size_t i = 0, len = 0;
  while (str[i])
  {
      if(str[i] < 0){
        ++i;
      }
      ++len;    
      ++i;
  }
 
  cout << "str len：" << len << endl;
  // 结果5
}

int main()
{
  system("cls");
  test02();
  return 0;
}
