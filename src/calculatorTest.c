/*
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * Test all components working together
 * Verifies Requirement A.5: Adhere to predefined interfaces
 * Verifies Requirement C.1: Producer correct order or operations
 */

#include "./headers/tokenizer.h"
#include "./headers/infix2postfix.h"
#include "./headers/code_generator.h"
#include "./headers/virtual_machine.h"
#include <ctap.h>

TESTS{
    char buffer[100];
    
    char * input[] = {"10+10","140/2","70-65","4*4","10*(3+4)","10/3", "10/4","(10+3)*(5631-6631)", "(1+(1+(1+(1+(1+(1+(1+(1+(1+1)))))))))", "((10*7)-(18+3))+20"};
    char * output[] = {"20","70","5","16","70","3.333333","2.500000","-13000","10","69"};
    
    for (int i = 0; i < sizeof(input)/sizeof(input[0]) ;i++){
        
        Scanner(input[i]);
        infix2postfix();
        code_generator();
        virtual_machine();
        get_answer(buffer, 100);
        is(buffer, output[i], "%s produces output %s",input[i],output[i]);
        }
}
