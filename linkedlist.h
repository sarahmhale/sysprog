#include <stdio.h>
#include <stdlib.h>
struct node* head;

typedef struct node {
  void * value;
  struct node* next;
}node;


int Length(struct node* head);
void Push(void * newData);
void Print();

int Length(node * head){
  node * current = head;
  int length = 0;
  while(current->next != NULL){
    current = current->next;
    length++;
  }
  return length;
}

void Push(void * newData){
  node * temp = (node*)malloc(sizeof(node));
  temp->value = newData;
  temp->next = head;
  head = temp;

}
void Print(){
  struct node * current = head;
  while(current != NULL){
   printf("Node: %s @ %p\n", (char *)current->value, current);
    current = current->next;
  }
}
