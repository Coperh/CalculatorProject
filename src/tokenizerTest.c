/*
 * Test cases for the tokenizer
 * Tests requirments A.2 - A.4 and B.1 - B.4
 * Tokenizer does not input from a file and therefore does not require A.1
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include <ctap.h>
#include "./headers/tokenizer.h"

#define BUFFER_SIZE 100

TESTS{
    
    
    // Requirement B.1 Find the start and end of a string of numbers
    // Assumed true if all other tests pass
    
    // Requirement B.2 : detect valid and invalid characters
    // Tests CharacterValidator with all valid character and some invalid characters
    char validChars[] = {'+','-','*','/','(',')'};
    char invalidChars[] = {'\\','>','a','c'};
    for (int i = 0; i < sizeof(validChars);i++){
        ok(CharacterValidator(validChars[i]), "< %c > is a valid character",validChars[i]);
    }
    for (int i = 0; i < sizeof(invalidChars);i++){
        ok(!CharacterValidator(invalidChars[i]), "< %c > is not a valid character", invalidChars[i]);
    }
    
    // Requirement B.4 : detect float and integer values
    // integers, all input assumed to be numeric(verified in scanner)
    char *validInts[] = {"123","3","123456"};
    for (int i = 0; i < sizeof(validInts)/sizeof(validInts[0]);i++){
        ok(NumberValidator(validInts[i]), "<%s> is a valid integer", validInts[i]);
    }
    // valid floats
    char *validFloats[] = {"1.23","3.0","123.456",".75"};
    for (int i = 0; i < sizeof(validFloats)/sizeof(validFloats[0]);i++){
        ok(NumberValidator(validFloats[i]), "<%s> is a valid float", validFloats[i]);
    }
    // invalid float
    char *invalidFloats[] = {"1.2.3","3.0.","123..456",".75.","."};
    for (int i = 0; i < sizeof(invalidFloats)/sizeof(invalidFloats[0]);i++){
        ok(!NumberValidator(invalidFloats[i]), "<%s> is not a valid float", invalidFloats[i]);
    }
    
    char filename[] = "Tokens.txt";
    char buffer[BUFFER_SIZE];
    FILE *output;
    
    // Scanner
    // Requirement A.2 Provide an output
    char in[] = "1+2";
    char out[] = "1 + 2 ";
    Scanner(in);
    output = fopen(filename, "r");
    fgets(buffer, BUFFER_SIZE , output);
    is( buffer, out, "<%s> == <%s> Valid file output", buffer,out);
    fclose(output);
    
    // Requirement A.3 Handle blank (or no input) & Requirement A.4 Handle Errors
    // will not compile with no input
    ok(!Scanner(""), "Returns error on blank input");
    
    
    char *scanner_input[] = {"1+3", "10 + 11 + 12","10.0*563/(10*3)", "ab","10.0.0+3.03"};
    char * scanner_output[] = {"1 + 3 ", "10 + 11 + 12 ","10.0 * 563 / ( 10 * 3 ) ","false","false"};
    
    // Requirement A.4 Handle Errors & General input/output testing
    for(int i = 0; i < sizeof(scanner_input)/sizeof(scanner_input[0]); i++){
        // run scanner
        if (Scanner(scanner_input[i])){
            // read and verify output from output file
            output = fopen(filename, "r");
            fgets(buffer, BUFFER_SIZE , output);
            is( buffer, scanner_output[i], "<%s> == <%s>", buffer,scanner_output[i]);
            fclose(output);
        }
            
        else
            is("false", scanner_output[i], "Input <%s> is invalid",scanner_input[i]);
    }
    
        
    
    
}
