/* <fil>.c
 *  <Namn> <Namnsson>
 *  Laboration <n> <kurs> <termin>
 *  <Kort enradsbeskrivning av filens innehåll och syfte>
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define BUFSIZE 1023
void read(FILE * fp);
int main(int argc, char *argv[]){
  if(argv[1] != NULL){
    FILE * fp;
    fp = fopen(argv[1],"r");
    read(fp);
    fclose(fp);

  }else{
    read(stdin);
  }
  return 0;
}

void read(FILE * fp){
  char buffer[BUFSIZE];
  while(fgets(buffer, BUFSIZE, fp) != NULL){
    puts(buffer);
  }
}
