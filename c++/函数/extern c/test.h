/*
  方法2： 通过条件编译
  告诉编译器如果 __cplusplus 宏
  说明是C++编译器，然后用
  extern "C" { 阔住代码 }
  里面的代码都将以C语言去编译
*/

#ifdef __cplusplus
extern "C" {
#endif

#pragma once
#include <stdio.h>
void show();

#ifdef __cplusplus
}
#endif