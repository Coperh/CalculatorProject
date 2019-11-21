#include <ctap.h>
#include "./headers/tokenizer.h"


TESTS{
    
    
    // Requirement B.2 : detect valid and invalid characters
    char validChars[] = {'+','-','*','/','(',')'};
    char invalidChars[] = {'\\','>','a','c'};
    for (int i = 0; i < sizeof(validChars);i++){
        ok(CharacterValidator(validChars[i]), "%c is a valid character",validChars[i]);
    }
    for (int i = 0; i < sizeof(invalidChars);i++){
        ok(!CharacterValidator(invalidChars[i]), "%c is not a valid character", invalidChars[i]);
    }
    
    // Requirement B.4 : detect float and integer values
    // integers, all input assumed to be numeric(verified in scanner)
    char *validInts[] = {"123","3","123456"};
    for (int i = 0; i < sizeof(validInts)/sizeof(validInts[0]);i++){
        ok(NumberValidator(validInts[i]), "%s is a valid integer", validInts[i]);
    }
    // valid floats
    char *validFloats[] = {"1.23","3.0","123.456",".75"};
    for (int i = 0; i < sizeof(validFloats)/sizeof(validFloats[0]);i++){
        ok(NumberValidator(validFloats[i]), "%s is a valid float", validFloats[i]);
    }
    // invalid float
    char *invalidFloats[] = {"1.2.3","3.0.","123..456",".75.","."};
    for (int i = 0; i < sizeof(invalidFloats)/sizeof(invalidFloats[0]);i++){
        ok(!NumberValidator(invalidFloats[i]), "%s is not a valid float", invalidFloats[i]);
    }
    
    
    
}
