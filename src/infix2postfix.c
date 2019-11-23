
/*
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
precedence, order of operation: 1: brackets 2: exponents 3: * and / 4: + and -
…..3.1 If the precedence of the scanned operator is greater than the precedence 
	   of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
…..3.2 Else, Pop all the operators from the stack which are greater than or equal to 
	   in precedence than that of the scanned operator. After doing that Push the scanned 
	   operator to the stack. (If you encounter parenthesis while popping then stop there and 
	   push the scanned operator in the stack.)
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is 
   encountered, and discard both the parenthesis.
6. Repeat steps 2-6 until infix expression is scanned.
7. Print the output
8. Pop and output from the stack until it is not empty.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char stack[20];
int top = -1;
void push(char x) //push a token to the stack
{
    stack[++top] = x;
}
char pop() //returns the token at the top of the stack
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
/*
Determines the precedence of an operator
*/
int precedence(char x)
{
    if(x == '(')
        return 1;
    if(x == '+' || x == '-')
        return 2;
    if(x == '*' || x == '/')
        return 3;
}
/*
Main function to take input from a txt file and
convert it from infix to postfix notation,
writing the output to another txt file.
*/
int infix2postfix()
{
    char exp[20];
    char *e, x;
	FILE *fPointer; //file pointer for input txt file
	FILE *fWrite; //file pointer for output txt file
	fPointer = fopen("Tokens.txt", "r"); //pointer to read from input file
	fWrite = fopen("Postfix.txt", "w"); //pointer to write to output file
	while (fgets(exp, 20, fPointer) != NULL) //scan line token by token until null pointer
		e = exp;
		while(*e != '\0')
		{	
			if(isspace(*e) //ignore spaces, do not push to stack
				;
			else if((isdigit(*e) || *e == '.') && (isdigit(*(e+1)) || *(e+1) == '.')) //allow for > single digit numbers
			{
				fprintf(fWrite, "%c", *e);
				
			}
			else if(isdigit(*e) || *e == '.') //allow for '.', floating point numbers
				fprintf(fWrite, "%c ", *e);
			else if(*e == '(') //opening bracket immediately pushed to stack
				push(*e);
			else if(*e == ')') //correctly format the operands that come before closing bracket
			{
				while((x = pop()) != '(')
					fprintf(fWrite,"%c ", x);
			}
			else //compare the precedence of current token and token on top of the stack
			{
				while(precedence(stack[top]) >= precedence(*e))
					fprintf(fWrite,"%c ",pop());
				push(*e);
			}
			e++; //move the pointer
    }
    while(top != -1) //pop remaining tokens off the stack
    {
		fprintf(fWrite,"%c ",pop());
    }
    fclose(fPointer);
    fclose(fWrite);
    return 0;
    
}
