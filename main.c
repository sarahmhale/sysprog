/* <fil>.c
 *  <Namn> <Namnsson>
 *  Laboration <n> <kurs> <termin>
 *  <Kort enradsbeskrivning av filens innehåll och syfte>
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define BUFSIZE 1023
struct node* head;

void read(FILE * fp,struct node* head);
int main(int argc, char *argv[]){
  head = NULL;
  if(argv[1] != NULL){
    FILE * fp;
    fp = fopen(argv[1],"r");
    read(fp,head);
    fclose(fp);
  }else{
    read(stdin,head);
  }
  return 0;
}

void read(FILE * fp, struct node** head){
  char buffer[BUFSIZE];
  Push(head, (void*)1);
  Length(head);

  fseek (fp, 0, SEEK_END);
  int size = ftell(fp);

  if (!feof(stdin) && size == 0){
    fprintf(stderr, "NO INPUT FILE OR STDIN" );
  }
  while(fgets(buffer, BUFSIZE, fp) != NULL){
    puts(buffer);
  }
}
