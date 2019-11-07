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

char op[5],arg1[5],arg2[5],result[5];

void main(){
  
  FILE *fp1,*fp2;
 
  fp1=fopen("postfix.txt","r");
  fp2=fopen("instructions.txt","w");
  
  while(!feof(fp1)){

    fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);

    if(strcmp(op,"+") == 0){
      fprintf(fp2,"LOADINT %s",arg1);
      fprintf(fp2,"\nADD %s",arg2);
      fprintf(fp2,"\nMOV %s",result);
    }
    
    if(strcmp(op,"*")==0){
      fprintf(fp2,"\nLOADINT %s",arg1);
      fprintf(fp2,"\nMUL %s",arg2);
      fprintf(fp2,"\nMOV %s",result);
    }
    
    if(strcmp(op,"-")==0){
      fprintf(fp2,"\nLOADINT %s",arg1);
      fprintf(fp2,"\nSUB %s",arg2);
      fprintf(fp2,"\nMOV %s",result);
    }
    
    if(strcmp(op,"/")==0){
      fprintf(fp2,"\nLOADINT %s",arg1);
      fprintf(fp2,"\nDIV %s",arg2);
      fprintf(fp2,"\nMOV %s",result);
    }
    
    if(strcmp(op,"=")==0){
      fprintf(fp2,"\nMOV %s",arg1);
      fprintf(fp2,"\nMOV %s",result);
    }
  }
    fclose(fp1);
    fclose(fp2);
    getch();
}
