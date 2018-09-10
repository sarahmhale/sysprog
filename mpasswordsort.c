/* mpasswdsort.c
 *  Sarah Hale
 *  Laboration 1 Systemnära programmering HT18
 *  <Kort enradsbeskrivning av filens innehåll och syfte>
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "list.h"
#define BUFSIZE 1023

void read(FILE * fp);
char * strtok_single(char * buffer, char const * delims);
const char * isStringEmpty(char const * str);
void freeList(struct node * head);
const char * isNumber(char const * str);

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

/*
This code is taken from stackoverflow, source:
https://stackoverflow.com/questions/8705844/need-to-know-when-no-data-appears-between-two-token-separators-using-strtok
*/
char * strtok_single (char * str, char const * delims){
  static char  * src = NULL;
  char  *  p,  * ret = 0;

  if (str != NULL)
    src = str;

  if (src == NULL)
    return NULL;

  if ((p = strpbrk (src, delims)) != NULL) {
    *p  = 0;
    ret = src;
    src = ++p;

  } else if (*src) {
    ret = src;
    src = NULL;
  }
  return ret;
}


const char * isNumber(char const * str){
  if(str != NULL || *str != '\0'){
    while(*str){
      char c =*str;
      if(!isdigit(c)){
        fprintf(stderr, "Invalid format\n" );
        return NULL;
      }
      str++;
    }
    return str;
  }
  fprintf(stderr, "Invalid format\n" );
  return NULL;
}

const char * isStringEmpty(char const * str){
  if(str == NULL || str[0] == '\0'){
    fprintf(stderr, "Invalid format\n" );
    return NULL;
  }
  return str;
}


void read(FILE * fp){
  node * head = NULL;

  char buffer[BUFSIZE];
  while(fgets(buffer, BUFSIZE, fp) != NULL){
    printf("%s\n",buffer );
    const char seperator[2] = ":";
    char * uname = strtok_single(buffer, ":");
    strtok_single(NULL, ":");
    char * uid = strtok_single(NULL,seperator);
    char * gid = strtok_single (NULL,seperator);
    strtok_single (NULL,seperator);
    char * directory = strtok_single (NULL,seperator);
    char * shell = strtok_single (NULL,seperator);

    if(isStringEmpty(uname) == NULL || isStringEmpty(directory) == NULL ||
     isStringEmpty(shell) == NULL){
        printf("Error creating asadasdasd\n");
    }
    else if(isNumber(uid) == NULL || isNumber(gid) == NULL){
        printf("Error creating a new noasdasdasde.\n");

    }else{
      head = insert(atoi(uid),uname, head);
      printf("%i\n",head->uid );
      printf("%s\n",head->uname );
    }

  }

  head = bubbelsort(head);
  print(head);
//  freeList(head);
}


// void freeList(struct node * head){
//    struct node * current;
//    while (head != NULL)
//     {
//        current = head;
//        free(current->uname);
//        head = head->next;
//        free(current);
//     }
// }
