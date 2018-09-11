#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

node * insert(user_info * new_user, node * head){
  node * temp = create_node(new_user, head);
  head = temp;
  return head;
}

node * create_node(user_info * new_user, node * next){
  node * temp = malloc(sizeof(node));

  if(temp == NULL){
    perror("malloc did not allocate memory");
    exit(1);
  }

  temp->value = new_user;
  temp->next = next;
  return temp;
}

void swap_nodes(node * first_node, node * second_node){
  user_info* temp = first_node->value;
  first_node->value = second_node->value;
  second_node->value = temp;
}

node * bubbelsort (node * head){
  node * i, * j;
  for ( i = head; i->next != NULL; i = i->next ){
    for ( j = i->next; j != NULL; j = j->next ){
      if(((user_info*)(i->value))->uid >((user_info*)(j->value))->uid){
        swap_nodes(i,j);
      }
    }
  }
  return head;
}

void print(node * head){
  node * current = head;
  printf("%d:%s\n", ((user_info*)(head->value))->uid, ((user_info*)(head->value))->uname);
  while(current->next != NULL){
   current = current->next;
   printf("%d:%s\n", ((user_info*)(current->value))->uid, ((user_info*)(current->value))->uname);
  }
}
//
// void freeList(node * head) {
//   while(head->next){
//     node * temp = head->next;
//     free(head->uname);
//     free(head);
//     head = temp;
//   }
// }
