/*
 * Virtual Machine
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * 
 * Interprets and executes code
 * Verifies the result
 * Prints result to standar output
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define STACK_SIZE 100



double dstack[STACK_SIZE];
int dtop = -1;
char flag = 0;
char answer[100];

/*
 * Returns output string
 * strOut: Buffer where the answer will be stored
 * strSize: size of the buffer
 */
void get_answer(char* strOut, unsigned int strSize){
    // copy answer into buffer
    strncpy(strOut, answer, strSize);
}
// push double on stack
void dpush(double x)
{
	dstack[++dtop] = x;
}
// gets double from stack
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


/*
 * Pops 2 items from stack and executes an operation
 * returning the result to the stack
 * command: the code for each operation
 */
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
        // if dividing by 0
        if(num1 == 0)
            return -1;
		dpush(num2 / num1);
		break;
	}
	return 0;
}


/*
 * Adds a number to the stack
 * number: the bnumber being added to the stack
 * 
 */
int stack_add(double number) {

	if (dtop >= STACK_SIZE - 1)
		return -1;

	dpush(number);
	return 0;
}

/*
 * Validates the stack post execution
 * 
 */
int stack_validator(){
    
    // if more than one item
    if(dtop > 0){
        printf("Too many items on stack\n");
        return -1;
    }
    // if stack is empty
    else if(dtop < 0){
        printf("Stack is empty\n");
        return -1;
    }
    
    float ans = dpop();
    // if result does not have a deicmal place, answs is int
    if( ans - (int)ans == 0)
        sprintf(answer, "%d",(int)ans);
    // else answer is float
    else
        sprintf(answer, "%f", ans);
    return 0;
}

/*
 * Interprets the instructions from the code generator
 * and executes the instructions
 */


int interpreter() {
	// open file
    
    // clear stack
    dtop = -1;
    
	const char* delimiter_characters = " ";
	const char* filename = "Instructions.txt";

	FILE* input_file;

	input_file = fopen(filename, "r");


	char buffer[BUFFER_SIZE];
	char* token;
    // if file is empty
	if (input_file == NULL){
		printf("No input file.");
        return -1;
	}
	else {

        
		while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
			// read a line
			// execute it
			// findn out the instruction
			token = strtok(buffer, delimiter_characters);
			int cm = -1;
            // see if operation
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
			// else if load int
			else if (strcmp(token, "LOADINT") == 0) {
				int number = atoi(strtok(NULL, delimiter_characters));
				stack_add((double)number);
			}
			// else if load float
			else if (strcmp(token, "LOADFLOAT") == 0) {
				double number = strtod(strtok(NULL, delimiter_characters), NULL);
				stack_add(number);
			}
			// return error
			else {
				printf("Invalid Command\n");
				return(-1);
			}

		}
	}
	fclose(input_file);
	return 0;
}

/*
 * Runs the components of the virtual machine
 * and prints the result to standard output
 */
int virtual_machine(){
    
    if (interpreter() != 0)
        return -1;
    
    if(stack_validator() == 0)
        printf("Answer: %s\n", answer);
    else 
        return -1;
    return 0;
    
}

