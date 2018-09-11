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



node * insert(unsigned int uid, char* uname, node * head);
node * bubbelsort (node * head);
node * create_node(unsigned int uid, char* uname, node * next);
void print(node * head);
