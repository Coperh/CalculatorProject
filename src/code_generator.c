#include <stdio.h>

void code_generator() {
	printf("Generating Code\n");
}


/*

-------------------- NOT COMPLETED YET. --------------------

*/


#include <stdio.h>
#include <string.h>
#include <assert.h>

char readchar(FILE *myfile) {
	char c = getc(myfile);
	return c;
}

void writechar(FILE *newfile, char c) {
	fputc(c, newfile);
}


int main(int argc, char **argv) {

	FILE *input, *output;
	input = fopen("postfix.txt", "r"); 
  	output = fopen("instructions.txt", "w");

	char c = readchar(input);

	char* token = strtok(&c, " "); 
	
	while (token != NULL) { 
        
		int integer;
		if(token = &integer){
			fprintf(output, "\nLOADINT %c", token);
		}
		
		char operator;
		if(token = &operator){
			switch(operator){
				case '+':
					fprintf(output,"\nADD");
					break;
				
				case '-':
					fprintf(output, "\nSUB");
					break;

				case '*':
					fprintf(output,"\nMUL");
					break;

				case '/':
					fprintf(output, "\nDIV");
					break;
			}
		}
		
        token = strtok(NULL, " "); 
		writechar(output, c);
    } 
/*
	for(int i = 0; i <= 9; i++){
		if(c = i){

		}
	}
*/
	return 0;
}
