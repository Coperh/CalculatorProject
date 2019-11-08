#include <stdio.h>

void code_generator() {
	printf("Generating Code\n");
}


/*

NOT COMPLETED YET. UPLOADING SO IT CAN BE WORKED ON AT SCHOOL COMPS

*/


#include<stdio.h>
#include<conio.h>
#include<string.h>


void main(){
  
  char operator;
  FILE *fp1,*fp2;
 
  fp1=fopen("postfix.txt","r");
  fp2=fopen("instructions.txt","w");
  
  while(!feof(fp1)){

    switch(operator){
      case '+':
        fprintf(fp2, "ADD");
        break;
      
      case '-':
        fprintf(fp2, "SUB");
        break;

      case '*':
        fprintf(fp2, "MUL");
        break;

      case '/':
        fprintf(fp2, "DIV");
        break;
    }
  }
    fclose(fp1);
    fclose(fp2);
    getch();
}
