#include <iostream>
using namespace std;


// 二级指针的运用
struct Human{
  int age;
};
void test01() {
  Human* lucy = NULL;

 [](Human** pHuman){

   *pHuman = NULL;
   *pHuman = (Human *) malloc(sizeof(Human));
   if(*pHuman == NULL) {
     perror("malloc");
     return;
   }
   (*pHuman)->age = 100;

 }(&lucy);

 cout << lucy->age << endl;
}

// 指针的引用(简化指针)
void test02() {
  Human* lucy = NULL;
  [](Human* &pqHuman){
    // cout << pqHuman << endl; 
    // 0  == *lucy == NULL 简化了
    pqHuman = (Human*) malloc(sizeof(Human));
    pqHuman->age = 1000; 
  }(lucy);   // Human* &pqHuman => *lucy

  cout << lucy->age << endl;
}


int main(void)
{
  test02();  
  return 0;
}
