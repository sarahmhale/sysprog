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
#define RETURN_VALUE 0;

void read(FILE * fp);
char * strtok_single(char * buffer, char const * delims);
const char * isStringEmpty(char const * str);
void freeList(struct node * head);
const char * isNumber(char const * str);

int main(int argc, char *argv[]){

  if(argc >1){
    if(argv[1] != NULL){
      FILE * fp = fopen(argv[1],"r");

      if (fp == NULL) {
        perror("Error reading file");
        exit(1);
      }
      read(fp);
      fclose(fp);
    }
  }else{
    read(stdin);
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
  node * list = NULL;
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
      RETURN_VALUE = 1;
      fprintf(stderr,"Line %d : %s\n",line, "uname format wrong");
    }
    else if(isStringEmpty(directory) == NULL){
        RETURN_VALUE = 1;
        fprintf(stderr,"Line %d : %s\n",line, "directory format wrong");

    }
    else if(isStringEmpty(shell) == NULL){
        RETURN_VALUE = 1;
        fprintf(stderr,"Line %d : %s\n",line, "shell format wrong");

    }
    else if(isNumber(uid) == NULL){
        RETURN_VALUE = 1;
        fprintf(stderr,"Line %d : %s\n",line, "uid format wrong");
    }

    else if(isNumber(gid) == NULL){
      RETURN_VALUE = 1;
        fprintf(stderr,"Line %d :%s\n",line, "gid format wrong");
    }else{
      user_info * new_user = malloc(sizeof(user_info));
      new_user->uid = atoi(uid);
      new_user->uname = malloc(strlen(uname)+1);
      strcpy(new_user->uname, uname);
      list = create_node(new_user,list);
     }
     line++;
  }

  if(list != NULL){
    RETURN_VALUE = 0;
    list = bubbelsort(list);
    print(list);
    freeList(list);
  }

}
