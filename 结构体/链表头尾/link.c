#include "link.h"

LinkNode *init_link()
{
  LinkNode *link_header = NULL;
  link_header = (LinkNode *)calloc(1, sizeof(LinkNode));
  if (link_header == NULL)
  {
    perror("calloc");
    return NULL;
  }

  link_header->value = -1;
  link_header->next = NULL;

  LinkNode *link_footer = NULL;
  link_footer = link_header;
  int iptValue = 0;

  while (1)
  {
    printf("pls ipt link_node value, if value -1 end \n");
    scanf("%d", &iptValue);
    if (iptValue == -1)
    {
      break;
    }
    LinkNode *link_new = (LinkNode *)calloc(1, sizeof(LinkNode));
    link_new->value = iptValue;
    link_new->next = NULL;

    // 这里有个疑惑什么时候对header 赋予初值
    // link_footer 初始化的时候是 link_header
    link_footer->next = link_new;
    link_footer = link_new;
  }

  return link_header;
}

void print_link(LinkNode *link_header)
{
  if (link_header == NULL || link_header->next == NULL)
  {
    printf("link_list is not \n");
    return;
  }
  LinkNode *cur_link = link_header->next;

  while (cur_link != NULL)
  {
    printf("cur_link->value = %d \n", cur_link->value);
    cur_link = cur_link->next;
  }
}

void insert_link(LinkNode *link_header, int old_value, int new_value)
{

  if (link_header == NULL || link_header->next == NULL)
  {
    return;
  }
  // printf("link_header->value = %d \n", link_header->value);

  LinkNode *cur_link = NULL;
  cur_link = link_header->next;
  LinkNode *prev_link = link_header;
  while (cur_link != NULL)
  {
    if (cur_link->value == old_value)
    {
      LinkNode *new_link = NULL;
      new_link = (LinkNode *)calloc(1, sizeof(LinkNode));
      if (new_link == NULL)
      {
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

    if (cur_link == NULL)
    {
      printf("find not insert pos value %d \n", old_value);
    }
  }
}

void delete_link(LinkNode *link_header, int del_link_value)
{
  if (link_header == NULL || link_header->next == NULL)
  {
    return;
  }

  LinkNode *cur_link = NULL;
  cur_link = link_header->next;
  LinkNode *prev_link = link_header;
  while (cur_link != NULL)
  {
    if (cur_link->value == del_link_value)
    {
      prev_link->next = cur_link->next;
      free(cur_link);
      cur_link = NULL;
      break;
    }
    prev_link = cur_link;
    cur_link = cur_link->next;
  }
}

void clear_link(LinkNode *link_header)
{
  if (link_header == NULL || link_header->next == NULL)
  {
    printf("your link_list is not clear \n");
    return;
  }

  LinkNode *cur_link = link_header->next;
  link_header->next = NULL;

  while (cur_link != NULL)
  {
    LinkNode *next_link = cur_link->next;
    printf("clear value = %d \n", cur_link->value);
    free(cur_link);
    cur_link = next_link;
  }
}

void destroy_list(LinkNode *link_header)
{
  if (link_header == NULL || link_header->next == NULL)
  {
    printf("your link_list is not destroy \n");
    return;
  }

  clear_link(link_header);
  free(link_header);
  link_header->next = NULL;
  link_header = NULL;
}