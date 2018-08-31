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
int checkInput(FILE * fp);
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

int checkInput(FILE * fp){
  int rightInput = 1;
  if (feof(stdin) && feof(fp)){
    fprintf(stderr, "NO INPUT FILE OR STDIN" );
    rightInput = 0;
  }
  return rightInput;
}

void read(FILE * fp){
  if(checkInput(fp)){
    char buffer[BUFSIZE];
    while(fgets(buffer, BUFSIZE, fp) != NULL){
      puts(buffer);
    }
  }
}

// void read(FILE * fp){
//   fseek (fp, 0, SEEK_END);
//   int size = ftell(fp);
//   if (!feof(stdin) && size == 0){
//     fprintf(stderr, "NO INPUT FILE OR STDIN" );
//
//   }
//     char buffer[BUFSIZE];
//
//     while(fgets(buffer, BUFSIZE, fp) != NULL){
//       printf("%s\n","here" );
//       puts(buffer);
//       // for(int i = 0; buffer[i] != '\0'; ++i) {
//       //     //Push((void *)buffer[i]);
//       //     printf("%c\n",buffer[i] );
//       //     Print();
//       // }
//
//   }
// }
