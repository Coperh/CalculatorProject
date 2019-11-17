
/*
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
precedence, order of operation: 1: brackets 2: exponents 3: * and / 4: + and -
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
…..3.2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis.
6. Repeat steps 2-6 until infix expression is scanned.
7. Print the output
8. Pop and output from the stack until it is not empty.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
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
    if (x == ' ')
	return -1;
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
/*
Main function to take input from a txt file and
convert it from infix to postfix notation,
writing the output to another txt file.
*/
main()
{
    char exp[20];
    char *e, x;
	FILE *fPointer;
	FILE *fWrite;
	fPointer = fopen("input.txt", "r"); //pointer to read from input file
	fWrite = fopen("output.txt", "w"); //pointer to write to output file
	while (fgets(exp, 20, fPointer) != NULL) //scan line token by token until null pointer
		e = exp;
		while(*e != '\0')
		{	
			if(isdigit(*e))
				fprintf(fWrite, "%c", *e);
			else if(*e == ' ')
				continue;
			else if(*e == '(')
				push(*e);
			else if(*e == ')')
			{
				while((x = pop()) != '(')
					fprintf(fWrite,"%c", x);
			}
			else
			{
				while(precedence(stack[top]) >= precedence(*e))
					fprintf(fWrite,"%c",pop());
				push(*e);
			}
			e++;
    }
    while(top != -1)
    {
		fprintf(fWrite,"%c",pop());
    }
    fclose(fPointer);
    return 0;
    
}
