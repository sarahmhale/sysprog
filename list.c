#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*Purpose: Inserts a node at the start of the list
*/
node * insert(user_info * new_user, node * head){
  node * temp = create_node(new_user, head);
  head = temp;
  return head;
}

/*Purpose: creates a new node.
*/
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

/*Purpose: swap places of two nodes
*/
void swap_nodes(node * first_node, node * second_node){
  user_info* temp = first_node->value;
  first_node->value = second_node->value;
  second_node->value = temp;
}

/*Purpose: sorts the nodes by UID in descending order
*/
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
/*Purpose: Prints the user info by looping through the list.
*/
void print(node * head){
  node * current = head;
  printf("%d:%s\n", ((user_info*)(head->value))->uid, ((user_info*)(head->value))->uname);
  while(current->next != NULL){
   current = current->next;
   printf("%d:%s\n", ((user_info*)(current->value))->uid, ((user_info*)(current->value))->uname);
  }
}

/*Purpose: Frees the memory that the list has used
*/
void freeList(node * head) {
  node * temp;
  while(head != NULL){
    temp = head;
    head = head->next;
    user_info * user =temp->value;
    free(temp);
    free(user->uname);
    free(user);
  }
}
