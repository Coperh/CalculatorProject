#include <stdio.h>

void code_generator() {
	printf("Generating Code\n");
}



/*

NOT COMPLETED YET. UPLOADING SO IT CAN BE WORKED ON AT SCHOOL COMPS

*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXCHAR 100

char buffer[MAXCHAR];
const char outputFile[] = "Instruction.txt";

//read a file 
//if token is separated by whitespace, use swtich statement
//print string and token
//print onto new .txt file 

int main(){

    char operator; 
    int c;

    FILE *fpostfix;
    fpostfix = fopen("postfix.txt", "r");

    while(!feof(fpostfix)){
        fgets(buffer, 100, fpostfix);
        puts(buffer);
    }

    if()


    //Operators
    operator = fgetc(fpostfix);
    switch (operator){
        case '+':
            printf("ADD \n");
            break;

        case '-':
            printf("SUB \n");
            break;

        case '*':
            printf("MUL \n");
            break;
        
        case '/':
            printf("DIV \n");
            break;

        default:
           printf("Error! Operation Not Valid \n");
    }

    fclose(fpostfix);

    //FILE *ouput = fopen(outputFile,"w");

    return 0;
}
