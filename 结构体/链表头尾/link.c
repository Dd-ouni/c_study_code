#include "link.h"

LinkNode* init_link() {
  LinkNode* link_header = NULL;
  link_header = (LinkNode*) calloc(1, sizeof(LinkNode));
  if(link_header == NULL) {
    perror("calloc");
    return NULL;
  }

  link_header->value = -1;
  link_header->next = NULL;

  LinkNode* link_footer = NULL;
  link_footer = (LinkNode*) calloc(1, sizeof(LinkNode));
  if(link_footer == NULL) {
    perror("calloc");
    return NULL;
  }

  int iptValue = 0;

  printf("pls ipt link_node value, if value -1 end \n");
  scanf("%d", &iptValue);
  if(iptValue == -1){
    return link_header;
  }else{
    LinkNode* link_new = (LinkNode*) calloc(1, sizeof(LinkNode));
    link_new->value = iptValue;
    link_new->next = NULL;
    link_header->next = link_new;
    link_footer->next = link_new;
  }

  while (1)
  {
    printf("pls ipt link_node value, if value -1 end \n");
    scanf("%d", &iptValue);
    if(iptValue == -1) {
      break;
    }
    LinkNode* link_new = (LinkNode*) calloc(1, sizeof(LinkNode));
    link_new->value = iptValue;
    link_new->next = NULL;

    link_footer->next->next = link_new;
    link_footer->next = link_new;
  }
  

  return link_header;
}


void print_link(LinkNode* link_header){
  LinkNode* cur_link = link_header->next;

  while (cur_link != NULL)
  {
    printf("%d \n", cur_link->value);
    cur_link = cur_link->next;
  }
}

void insert_link(LinkNode* link_header, int old_value, int new_value){
  LinkNode* cur_link = NULL;
  cur_link = link_header->next;
  LinkNode* prev_link = NULL;
  while (cur_link != NULL)
  {
    if(cur_link->value == old_value) {
      LinkNode* new_link = NULL;
      new_link = (LinkNode*) calloc(1, sizeof(LinkNode));
      if(new_link == NULL){
        perror("calloc");
        return;
      }
      new_link->value = new_value;
      new_link->next = cur_link;
      prev_link->next = new_link;
      break;
    }

    prev_link = cur_link;
    cur_link = cur_link->next;
  }

}

void delete_link(LinkNode* link_header, int del_link_value){
  LinkNode* cur_link = NULL;
  cur_link = link_header->next;
  LinkNode* prev_link = NULL;
  while (cur_link != NULL)
  {
    if(cur_link->value == del_link_value) {
      prev_link->next = cur_link->next;
      free(cur_link);
      cur_link = NULL;
      break;
    }
    prev_link = cur_link;
    cur_link = cur_link->next;
  }
}