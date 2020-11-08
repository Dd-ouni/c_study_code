#include <stdio.h>
#include <stdlib.h>

// typedef struct
// {
//   int value;
//   LinkNode* next;
// } LinkNode;
// 这样子写是无法识别 LinkNode* next; 
//  unknown type name 'LinkNode'

// typedef struct
// {
//   int value;
//   struct LinkNode* next;
// } LinkNode;
// 这样子写也是错误的，15 line 和 16 line 根本

typedef struct _LinkNode_
{
  int value;
  struct _LinkNode_* next;
} LinkNode;


void test01() {

  // 静态链表
  LinkNode node1 = { 10, NULL };
  LinkNode node2 = { 20, NULL };
  LinkNode node3 = { 30, NULL };
  LinkNode node4 = { 40, NULL };
  LinkNode node5 = { 50, NULL };

  // 链接关系
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;

  LinkNode* curLinkNode = &node1;

  while (curLinkNode != NULL)
  {
    printf("%d \n", curLinkNode->value);
    curLinkNode = curLinkNode->next;
  }
  
}

void test02() {
  // 动态链表
  LinkNode* node1 = calloc(1, sizeof(LinkNode));
  LinkNode* node2 = calloc(1, sizeof(LinkNode));
  LinkNode* node3 = calloc(1, sizeof(LinkNode));
  LinkNode* node4 = calloc(1, sizeof(LinkNode));
  LinkNode* node5 = calloc(1, sizeof(LinkNode));

  node1->value = 100;
  node1->next = node2;

  node2->value = 200;
  node2->next = node3;

  node3->value = 300;
  node3->next = node4;

  node4->value = 400;
  node4->next = node5;

  node5->value = 500;
  node5->next = NULL;
  
  LinkNode* curNode = node1;

  while (curNode != NULL)
  {
    printf("%d \n", curNode->value);
    curNode = curNode->next;
  }

  free(node1);
  free(node2);
  free(node3);
  free(node4);
  free(node5);  
}

int main(void)
{
  test02();
  return 0;
}
