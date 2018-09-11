#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  unsigned int uid;
  char* uname;
  struct node* next;
}node;

node * insert(unsigned int uid, char* uname, node * head);
node * bubbelsort (node * head);
node * create_node(unsigned int uid, char* uname, node * next);
void print(node * head);
