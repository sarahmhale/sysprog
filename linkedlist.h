#include <stdio.h>
#include <stdlib.h>
struct node* head;

typedef struct node {
  unsigned int uid;
  char* uname;
  struct node* next;
}node;


int Length(struct node* head);
void Push(void * newData);


int Length(node * head){
  node * current = head;
  int length = 0;
  while(current->next != NULL){
    current = current->next;
    length++;
  }
  return length;
}
