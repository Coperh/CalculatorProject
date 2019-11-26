#include <ctap.h>
#include <stdio.h>
#include <string.h>
#include "headers/virtual_machine.h"

#define BUFFER_SIZE 100
/*
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * Test cases for the virtual_machine
 * Tests Requirements A.1 - A.4 and E.1-E.5
 * Virtual machine does not provide an output, therefore no A.2
 */#include <stdio.h>

TESTS{
    // Requirement A.1: Read an input file
    // shown by all tests
    char in_name[]  = "Instructions.txt";
    FILE *input;
    char buffer[BUFFER_SIZE];  
    
    // Requirement E.1: Detect invalid instruction
    input = fopen(in_name, "w");
    fprintf(input, "inavlid\n");
    fclose(input);
    
    ok(interpreter() == -1, "Returns error with invalid instruction");
    
    // Requirement E.2: Detect impossible instructions e.g dividing by zero
    input = fopen(in_name, "w");
    fprintf(input, "LOADINT 5\nLOADINT 0\nDIV\n");
    fclose(input);
    ok(interpreter() == -1, "Returns error on division by Zero");
    
    
    // Requirement E.3: Operations with both integers and float point numbers
    // float and int input, int output
    input = fopen(in_name, "w");
    fprintf(input, "LOADFLOAT 5.7\nLOADINT 10\nMUL\n");
    fclose(input);
    virtual_machine();
    get_answer(buffer,BUFFER_SIZE);
    is(buffer,"57", "Handles both floats and integers");
    
    // float and int input, float output
    input = fopen(in_name, "w");
    fprintf(input, "LOADINT 77\nLOADFLOAT 1.25\nSUB\n");
    fclose(input);
    virtual_machine();
    get_answer(buffer,BUFFER_SIZE);
    is(buffer,"75.750000", "Handles both floats and integers");
    
    
    // Requirement A.3: Handle errors and exceptions
    // Requirement E.4: Handle Missing instructions or numbers
    input = fopen(in_name, "w");
    fprintf(input, "SUB\n");
    fclose(input);
    ok(virtual_machine()==-1, "Returns error if too many instruction/Not enough numbers");
    
    // Requirement E.5: Detect empty stack or stack with more than one element on output
    input = fopen(in_name, "w");
    fprintf(input, "LOADINT 10\nLOADINT 15\n");
    fclose(input);
    ok(virtual_machine()==-1, "Error is more than one element on stack");
    
    // REquirement A.4: Handle blank or no input
    input = fopen(in_name, "w");
    fclose(input);
    ok(virtual_machine()==-1, "Returns error with blank input file");
    
    // remove file
    remove(in_name);
    ok(virtual_machine()==-1, "Returns error with blank input file");
    
    
}





