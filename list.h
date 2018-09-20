#include <stdio.h>
#include <stdlib.h>

typedef struct user_info {
  unsigned int uid;
  char* uname;
}user_info;

typedef struct node {
  void * value;
  struct node * next;
}node;



node * insert(void * new_user, node * head);
node * bubbelsort (node * head);
node * create_node(void * new_user, node * next);
void print(node * head);
