/* <fil>.c
 *  <Namn> <Namnsson>
 *  Laboration <n> <kurs> <termin>
 *  <Kort enradsbeskrivning av filens innehåll och syfte>
 */

#include <stdio.h>
int main(int argc, char *argv[]){

  if(argv[1] != NULL){
    FILE * fp;
    fp = fopen(argv[1],"r");

    char singleLine[1023];
    while(fgets(singleLine, 1023, fp) != NULL){
      puts(singleLine);
    }

    fclose(fp);
  }else{
    printf("%s\n","NO INPUT FILE" );
  }
  return 0;
}
