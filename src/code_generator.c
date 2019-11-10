#include <stdio.h>

void code_generator() {
	printf("Generating Code\n");
}


/*

NOT COMPLETED YET. UPLOADING SO IT CAN BE WORKED ON AT SCHOOL COMPS

*/


#include <stdio.h>
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

	char operator;
	switch(operator){
		case '+':
			fprintf(output,"ADD");
			break;
		
		case '-':
			fprintf(output, "SUB");
			break;

		case '*':
			fprintf(output,"MUL");
			break;

		case '/':
			fprintf(output, "DIV");
			break;
	}


	char c = readchar(input);
	writechar(output, c);
	return 0;
}
