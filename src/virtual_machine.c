#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define STACK_SIZE 100

double stack[STACK_SIZE];
int top = -1;
char flag = 0;

void push(double x)
{
	stack[++top] = x;
}

double pop()
{
	if (top == -1) {
		flag = 1;
		return 0;
	}
	else {
		flag = 0;
		return stack[top--];
	}
}	

int stack_execute(int command) {
	double num1 = pop();
	double num2 = pop();
	if (flag == 1)
		return -1;

	switch (command) {
	// add
	case 0:
		push(num1 + num2);
		break;
	// subtract
	case 1:
		push(num1 - num2);
		break;
	// multiply
	case 2:
		push(num1 * num2);
		break;
	// divide
	case 3:
		push(num1 / num2);
		break;
	}
	return 0;
}

int stack_add(double number) {
	if (top >= STACK_SIZE - 1)
		return -1;
	push(number);
	return 0;
}
void virtual_machine() {
	// open file

		//int instr = ...
	const char* delimiter_characters = " ";
	const char* filename = "instructions.txt";

	FILE* input_file;

	input_file = fopen(filename, "r");


	char buffer[BUFFER_SIZE];
	char* token;
	if (input_file == NULL){
		printf("No input file.");
	}
	else {
		
		while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
			// read a line
			//printf("%s\n", buffer);
			// execute it
			// findn out the instruction
			token = strtok(buffer, delimiter_characters);

			if (strcmp(token, "ADD\n")==0) {
				printf("ADD\n");
				stack_execute(0);
			}
			else if (strcmp(token, "SUB\n") == 0) {
				printf("SUB\n");
				stack_execute(1);
			}
			else if (strcmp(token, "MUL\n") == 0) {
				printf("MUL\n");
				stack_execute(2);
			}
			else if (strcmp(token, "DIV\n") == 0) {
				printf("DIV\n");
				stack_execute(3);
			}
			else if (strcmp(token, "LOADINT") == 0) {
				int number = atoi(strtok(NULL, delimiter_characters));
				printf("LOADINT %d\n", number);
				stack_add((double)number);
			}
			else if (strcmp(token, "LOADFLOAT") == 0) {
				double number = strtod(strtok(NULL, delimiter_characters), NULL);
				printf("LOADFLOAT %f\n", number);
				stack_add(number);

			}
			else {
				printf("Invalid Command\n");
			}

		}
	}
}

int main(int argc, char** argv) {
	
	virtual_machine();
	printf("ans: %f", pop());
	return 0;
}