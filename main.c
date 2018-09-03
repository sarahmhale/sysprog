/* mpasswdsort.c
 *  Sarah Hale
 *  Laboration 1 Systemnära programmering HT18
 *  <Kort enradsbeskrivning av filens innehåll och syfte>
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>
#define BUFSIZE 1023

void read(FILE * fp);
void print(node * head);
void bubbelsort (node * head);
void checkObligatoryFields(char * c);
node * newNode(unsigned int uid, char* uname);

int main(int argc, char *argv[]){
  if(argc >1){
    if(argv[1] != NULL){
      FILE * fp;
      fp = fopen(argv[1],"r");
      read(fp);
      fclose(fp);
    }else{
      read(stdin);
    }
  }else{
    fprintf(stderr,"%s\n", "NO INPUT");
  }

  return 0;
}

// void checkObligatoryFields(char * c){
//     printf("uname: %lu\n", strlen(c));
//       printf("uname: %d\n", strcmp(c, " "));
//   if ((c && !c[0]) || strcmp(c, " ")) {
//     printf("c is empty\n");
//   }
// }
void print(node * head){
  node * current = head;
  printf("%d:%s\n", head->uid, head->uname);
  while(current->next != NULL){
   current = current->next;
   printf("%d:%s\n", current->uid, current->uname);
  }
}


void bubbelsort (node * head){
  node * i, * j;
  node * temp;
  for ( i = head; i->next != NULL; i = i->next ){
    for ( j = i->next; j != NULL; j = j->next ){
      if(i->uid > j->uid){
        temp = newNode(i->uid,i->uname);
        i->uid = j->uid;
        i->uname = j->uname;
        j->uid = temp->uid;
        j->uname = temp->uname;
      }
    }
  }
  print(head);
}


void read(FILE * fp){
  node * head = NULL;
  node * current = NULL;
  char buffer[BUFSIZE];
  const char seperator[2] = ":";
  // if(fgets(buffer, BUFSIZE, fp) == NULL){
  //   fprintf(stderr, "FILE IS EMPTY" );
  //   exit(EXIT_FAILURE);
  // }
  while(fgets(buffer, BUFSIZE, fp) != NULL){
    char * uname = strtok (buffer,seperator);
    strtok (NULL,seperator);
    char * uid = strtok (NULL,seperator);
    char * gid = strtok (NULL,seperator);
    strtok (NULL,seperator);
    char * directory = strtok (NULL,seperator);
    char * shell = strtok (NULL,seperator);

    if(head == NULL){
      head = newNode(atoi(uid), uname);
      current = head;
    }else{
      current->next = newNode(atoi(uid), uname);
      current = current->next;
    }
  }
  bubbelsort(head);
}


node * newNode(unsigned int uid, char* uname){
  node * temp = malloc(sizeof(node));
  temp->uid = uid;
  temp->uname =  malloc(strlen(uname) + 1);
  strcpy(temp->uname, uname);
  temp->next = NULL;
  return temp;

}



// printf("uid: %s\n",uid );
// printf("gid %s\n",gid );
// printf("directory %s\n",directory );
// printf("shell: %s\n",shell );
