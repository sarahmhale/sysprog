#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void * value;
  struct node* next;
}node;


int Length(struct node* head);
//void Push(struct node** headRef, int newData);
// node * createLinkedList(int nrOfNodes);
// void appendEndOfList(node * head, node * temp);

int Length(node * head){
  node * current = head;
  int length = 0;
  while(current->next != NULL){
    current = current->next;
    length++;
  }
  return length;
}


// void showList(node * head);
//void append(node * head, node * temp);
//void pop(node * head);

// node * createLinkedList(int nrOfNodes){
//   node * temp = NULL;
//   node * head = NULL;
//
//   for(int i = 0; i <= nrOfNodes; i++){
//     temp = (node*)malloc(sizeof(node));
//     temp->next = NULL;
//
//     if(head == NULL){
//       head = temp;
//     }else{
//       appendEndOfList(head,temp);
//     }
//   }
//   return head;
// }
//
// void appendEndOfList(node * head,node *temp){
//   node * current = NULL;
//   current = head;
//   while(current->next != NULL){
//     current = current->next;
//   }
//   current->next = temp;
// }

// void showList(node * head){
//   node * current = head;
//   while(current->next != NULL){
//    printf("Node: %p @ %p\n", current->value, current);
//     current = current->next;
//   }
// }
