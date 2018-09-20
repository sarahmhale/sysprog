/* mpasswdsort.c
 *  Sarah Hale
 *  Laboration 1 Systemnära programmering HT18
 *  sorts user by UID from a given file
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
const char * is_string_empty(char const * str);
void freeList(struct node * head);
const char * is_number(char const * str);
const char * checkFields(char * uname, char * uid, char * gid, char * directory,
   char* shell, char * destination, int line);

//If one of the obligatory field fails this number will increment
int fail = 0;


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
  if(fail > 0){
    return 1;
  }
  return 0;
}

/*
* This code is taken from stackoverflow, source:
* https://stackoverflow.com/questions/8705844/need-to-know-when-no-data-appears-between-two-token-separators-using-strtok
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

/*Purpose: Check if a string is a number
* Return Value: NULL if it is not a number
*               the number if it is a number
*/
const char * is_number(char const * str){
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

/*Purpose: Check if string is empty
* Return Value: NULL if it is empty
*               the string if it is not empty
*/
const char * is_string_empty(char const * str){
  if(str == NULL || str[0] == '\0'){
    return NULL;
  }
  return str;
}


/*Purpose: Check the obligatory fields
* Return Value: NULL if a field is wrong format
*               OK if all fields are okay.
*/
const char * checkFields(char * uname, char * uid, char * gid, char * directory,
   char* shell, char * destination, int line){
     if(is_string_empty(uname) == NULL){
       fail++;
       fprintf(stderr,"Line %d : Invalid format: %s\n",line, destination);
       return NULL;
     }
     else if(is_string_empty(directory) == NULL){
       fprintf(stderr,"Line %d : Invalid format: %s\n",line, destination );
       return NULL;
     }
     else if(is_string_empty(shell) == NULL){
       fprintf(stderr,"Line %d : Invalid format: %s\n",line, destination );
       return NULL;
     }
     else if(atoi(uid)<0){
       fprintf(stderr,"Line %d : The 'gid' field has to be postive: %s\n",line, destination);
       return NULL;
     }
     else if(atoi(gid)<0){
       fprintf(stderr,"Line %d : The 'gid' field has to be postive: %s\n",line, destination);
       return NULL;
     }
     else if(is_number(uid) == NULL){
       fprintf(stderr,"Line %d : The 'uid' field has to be numeric: %s\n",line, destination);
       return NULL;
     }
     else if (is_number(gid) == NULL){
       fprintf(stderr,"Line %d : The 'gid' field has to be numeric: %s\n",line, destination);
       return NULL;
     }
     return "OK";
}

/*Purpose: reads from file and addes a the user to the list if all fields are
*          are okay.
*/
void read(FILE * fp){
  node * list = NULL;
  int line = 1;
  char destination[BUFSIZE];
  char buffer[BUFSIZE];

  while(fgets(buffer, BUFSIZE, fp) != NULL){
    int len = strlen(buffer);
    if( buffer[len-1] == '\n' )
      buffer[len-1] = 0;
    strcpy(destination, buffer);

    const char seperator[2] = ":";
    char * uname = strtok_single(buffer, ":");
    strtok_single(NULL, ":");
    char * uid = strtok_single(NULL,seperator);
    char * gid = strtok_single (NULL,seperator);
    strtok_single (NULL,seperator);
    char * directory = strtok_single (NULL,seperator);
    char * shell = strtok_single (NULL,seperator);

    if(checkFields(uname, uid, gid, directory, shell, destination,line) == NULL){
      fail++;
    }else{
      user_info * new_user = malloc(sizeof(user_info));

      if(new_user == NULL){
        perror("malloc did not allocate memory");
        exit(1);
      }
      new_user->uid = atoi(uid);
      new_user->uname = malloc(strlen(uname)+1);
      
      if(new_user->uname == NULL){
        perror("malloc did not allocate memory");
        exit(1);
      }
      strcpy(new_user->uname, uname);
      list = create_node(new_user,list);
     }
     line++;
  }
  if(list != NULL){
    list = bubbelsort(list);
    print(list);
    freeList(list);
  }

}
