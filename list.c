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

node * bubbelsort (node * head){
  node * i, * j;

  for ( i = head; i->next != NULL; i = i->next ){
    for ( j = i->next; j != NULL; j = j->next ){
      if(i->uid > j->uid){
        struct node temp;
        temp.uid = uid;
        temp.uname = uname;
        temp.next = NULL
        i->uid = j->uid;
        i->uname = j->uname;
        j->uid = temp->uid;
        j->uname = temp->uname;
        free(temp);
      }
    }
  }
  return head;
}
//
// void print(node * head){
//   node * current = head;
//   printf("%d:%s\n", head->uid, head->uname);
//   while(current->next != NULL){
//    current = current->next;
//    printf("%d:%s\n", current->uid, current->uname);
//   }
// }
//
// void freeList(node * head) {
//   while(head->next){
//     node * temp = head->next;
//     free(head->uname);
//     free(head);
//     head = temp;
//   }
// }
