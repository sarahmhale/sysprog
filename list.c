#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node * insert(unsigned int uid, char* uname, node * head){
  node * temp = create_node(uid,uname,head);
  head = temp;
  return head;
}
node * create_node(unsigned int uid, char* uname, node * next){
  node * temp = malloc(sizeof(node));
  if(temp == NULL){
    printf("Error creating a new node.\n");
       exit(0);
  }
  temp->uid = uid;
  temp->uname =  uname;
  temp->next = next;
  return temp;
}

node * bubbelsort (node * head){
  node * i, * j;
  node * temp = NULL;
  for ( i = head; i->next != NULL; i = i->next ){
    for ( j = i->next; j != NULL; j = j->next ){
      if(i->uid > j->uid){
        temp->uid = i->uid;
        temp->uname =i->uname;
        i->uid = j->uid;
        i->uname = j->uname;
        j->uid = temp->uid;
        j->uname = temp->uname;
      }
    }
  }
  return head;
}

void print(node * head){
  node * current = head;
  printf("%d:%s\n", head->uid, head->uname);
  while(current->next != NULL){
   current = current->next;
   printf("%d:%s\n", current->uid, current->uname);
  }
}
