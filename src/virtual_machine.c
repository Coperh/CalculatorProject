#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define STACK_SIZE 100

double dstack[STACK_SIZE];
int dtop = -1;
char flag = 0;
char answer[100];


void get_answer(char* strOut, unsigned int strSize){
    strncpy(strOut, answer, strSize);
    
}



void dpush(double x)
{
	dstack[++dtop] = x;
}

double dpop()
{
	if (dtop == -1) {
		flag = 1;
		return 0;
	}
	else {
		flag = 0;
		return dstack[dtop--];
	}
}

int stack_execute(int command) {
	double num1 = dpop();
	if (flag == 1)
		return -1;
	double num2 = dpop();
	// if num2 is not available, add 1 back to stack
	if (flag == 1){
		dpush(num1);
		return -1;}

	switch (command) {
	// add
	case 0:
		dpush(num2 + num1);
		break;
	// subtract
	case 1:
		dpush(num2 - num1);
		break;
	// multiply
	case 2:
		dpush(num2 * num1);
		break;
	// divide
	case 3:
		dpush(num2 / num1);
		break;
	}
	return 0;
}

int stack_add(double number) {

	if (dtop >= STACK_SIZE - 1)
		return -1;

	dpush(number);
	return 0;
}

int stack_validator(){
    
    if(dtop > 0){
        printf("Too many items on stack\n");
        return -1;
    }
    else if(dtop < 0){
        printf("Stack is empty\n");
        return -1;
    }
    float ans = dpop();
    if( ans - (int)ans == 0)
        sprintf(answer, "%d",(int)ans);
    else
        sprintf(answer, "%f", ans);
    return 0;
    
    
}


int interpreter() {
	// open file

		//int instr = ...
	const char* delimiter_characters = " ";
	const char* filename = "Instructions.txt";

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
			int cm = -1;
			if (strcmp(token, "ADD\n")==0) {
				cm = 0;
			}
			else if (strcmp(token, "SUB\n") == 0) {
				cm = 1;
			}
			else if (strcmp(token, "MUL\n") == 0) {
				cm = 2;
			}
			else if (strcmp(token, "DIV\n") == 0) {
				cm = 3;
			}

			if (cm > -1){
				if (stack_execute(cm) < 0){
					printf("Not enough numbers on stack\n");
					return(-1);
				}

			}
			else if (strcmp(token, "LOADINT") == 0) {
				int number = atoi(strtok(NULL, delimiter_characters));
				stack_add((double)number);
			}
			else if (strcmp(token, "LOADFLOAT") == 0) {
				double number = strtod(strtok(NULL, delimiter_characters), NULL);
				stack_add(number);
			}
			else {
				printf("Invalid Command\n");
				return(-1);
			}

		}
	}
	fclose(input_file);
	return 0;
}


int virtual_machine(){
    if (interpreter() != 0)
        return -1;
    
    if(stack_validator() == 0)
        printf("Answer: %s\n", answer);
    else 
        return -1;
    return 0;
    
}

