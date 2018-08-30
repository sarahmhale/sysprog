#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void * value;
  struct node* next;
}node;


int Length(struct node* head);
void Push(struct node** headRef, void * newData);
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

void Push(struct node* head, void * newData){
  node * temp = (node*)malloc(sizeof(node));
  temp->value = newData;
  temp->next = head;
  head = temp;

}
void Print(){
  struct node * current = head;
  while(current != NULL){
   printf("Node: %p @ %p\n", current->value, current);
    current = current->next;
  }
}
