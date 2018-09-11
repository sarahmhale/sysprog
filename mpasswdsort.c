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
  printf("%s\n","hello world" );

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
        return NULL;
      }
      str++;
    }
    return str;
  }
  return NULL;
}

const char * isStringEmpty(char const * str){
  if(str == NULL || str[0] == '\0'){
    return NULL;
  }
  return str;
}


void read(FILE * fp){
  node * head = NULL;
  int line = 1;
  char buffer[BUFSIZE];
  while(fgets(buffer, BUFSIZE, fp) != NULL){
    const char seperator[2] = ":";
    char * uname = strtok_single(buffer, ":");
    strtok_single(NULL, ":");
    char * uid = strtok_single(NULL,seperator);
    char * gid = strtok_single (NULL,seperator);
    strtok_single (NULL,seperator);
    char * directory = strtok_single (NULL,seperator);
    char * shell = strtok_single (NULL,seperator);


    if(isStringEmpty(uname) == NULL){
      fprintf(stderr,"Line %d : %s\n",line, "uname format wrong");
    }
    else if(isStringEmpty(directory) == NULL){
        fprintf(stderr,"Line %d : %s\n",line, "directory format wrong");
    }
    else if(isStringEmpty(shell) == NULL){
        fprintf(stderr,"Line %d : %s\n",line, "shell format wrong");
    }
    else if(isNumber(uid) == NULL){
        fprintf(stderr,"Line %d : %s\n",line, "uid format wrong");
    }

    else if(isNumber(gid) == NULL){
        fprintf(stderr,"Line %d :%s\n",line, "gid format wrong");
    }else{
       head = insert(atoi(uid),uname, head);
     }
     line++;
  }

  head = bubbelsort(head);
  print(head);
  freeList(head);
  free(head);
}