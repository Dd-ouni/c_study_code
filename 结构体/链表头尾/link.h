#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _LinkNode_
{
  int value;
  struct _LinkNode_ *next;
} LinkNode;

LinkNode *init_link();

void print_link(LinkNode *);

void insert_link(LinkNode *, int, int);
// 插入节点

void delete_link(LinkNode *, int);
// 删除节点

// 销毁链表 整个销毁
void destroy_list(LinkNode *);

// 清空链表 保留头
void clear_link(LinkNode *);