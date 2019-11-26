/*
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * Test cases for the code_generator
 * Tests requirments A.1 - A.4 and D.1 & D.2
 */

#include <ctap.h>
#include <stdio.h>
#include <string.h>
#include "./headers/code_generator.h"
#define BUFFER_SIZE 100


TESTS{
    
    
    char in_name[] = "Postfix.txt";
    char out_name[]  = "Instructions.txt";
    FILE *input;
    FILE *output;
    char buffer[BUFFER_SIZE];    
    
    
    // Requirement A.3: Handle blank or no input   
    remove(in_name);
    ok(code_generator() == -1,"No input file returns error");
    
    
    input = fopen(in_name,"w");
    fclose(input);
    ok(code_generator() == 0,"Runs and terminates with blank input");
    
    
    // Requirement D.1: Identify opeartators
    // Requirement A.1: Read input file
    // Requirement A.2: Output to file
    char * operators[] = {"+ ","- ","* ","/ "};
    char * code_out[] = {"ADD\n","SUB\n","MUL\n","DIV\n"};
    
    
    for (int i = 0; i < sizeof(operators)/sizeof(operators[0]); i++){
        // write to inputfile
        input = fopen(in_name,"w");
        fprintf(input,"%s",operators[i]);
        fclose(input);
        // run code_generator
        code_generator();
        // read output file
        output = fopen(out_name,"r");
        fgets(buffer, BUFFER_SIZE , output);
        is(buffer, code_out[i]," %s outputs %s",operators[i],buffer);
        fclose(output);
    }
    
    char * invalid_ops[] = {"a ","b ","( ","] "};
    // Requirement A.4: Handle errors
    for (int i = 0; i < sizeof(invalid_ops)/sizeof(invalid_ops[0]); i++){
        // write to inputfile
        input = fopen(in_name,"w");
        fprintf(input,"%s",invalid_ops[i]);
        fclose(input);
        // run code_generator
        ok(code_generator() != 0, "Invlid input %s",invalid_ops[i]) ;
    }
    
    
    
    // Requirement D.2: Identify Integers
    char *intTest[] = {"1", "12", "123456"};
    for(int i = 0; i < sizeof(intTest)/sizeof(intTest[0]); i++){
        ok( NumberDetector(intTest[i]) == 1, "The integer '%s' outputs the instruction 'LOADINT %s' ", intTest[i], intTest[i]);
    }

    // Requirement D.2: Identify Floats
    char *floatTest[] = {"1.1", "1.23456", "123.456"};
    for(int i = 0; i < sizeof(floatTest)/sizeof(floatTest[0]); i++){
        ok( NumberDetector(floatTest[i]) == 0,"The float '%s' outputs the instruction 'LOADFLOAT %s'", floatTest[i], floatTest[i]);
    }
}
