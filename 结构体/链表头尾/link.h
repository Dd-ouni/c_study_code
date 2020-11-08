#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _LinkNode_{
  int value;
  struct _LinkNode_* next;
} LinkNode;


LinkNode* init_link();

void print_link(LinkNode*);

void insert_link(LinkNode*, int, int);

void delete_link(LinkNode*, int);


// 销毁链表 整个销毁
// 清空链表 保留头