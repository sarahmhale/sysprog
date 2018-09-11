#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  temp->uname = malloc(strlen(uname) + 1);
  strcpy(temp->uname, uname);;
  temp->next = next;
  return temp;
}

node * bubbelsort (node * head){
  node * i, * j, * temp;
  for ( i = head; i->next != NULL; i = i->next ){
    for ( j = i->next; j != NULL; j = j->next ){
      if(i->uid > j->uid){
        temp = create_node(i->uid, i->uname, NULL);
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

void print(node * head){
  node * current = head;
  printf("%d:%s\n", head->uid, head->uname);
  while(current->next != NULL){
   current = current->next;
   printf("%d:%s\n", current->uid, current->uname);
  }
}

void freeList(node * head) {
    while (head->next) {
        node *temp = head->next;
        head->next = head->next->next;
        free(temp->uname);
        free(temp);
    }

    free(head->uname);
}
