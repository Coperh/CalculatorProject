#include <ctap.h>
#include <stdio.h>
#include <string.h>
#include "./headers/code_generator.c"

#define BUFFER_SIZE 100

//Requirement D.1 Identify Operators
//Requirement D.2 Generate Integer or floating point load instruction
TESTS{

  //Requirement D.1 Identify Operators
  char Operators[] = {'+', '-', '*', '/'};
  char *operatorInstr[] = {"ADD", "SUB", "MUL", "DIV"};
  for(int i = 0; i < sizeof(Operators); i++){
    ok(Operators[i], "The operator '%c' outputs the instruction '%s'", Operators[i], operatorInstr[i]);
  }

  //Requirement D.2 Identify Integers
  char *intTest[] = {"1", "12", "123456"};
  for(int i = 0; i < sizeof(intTest); i++){
    ok(intTest[i], "The integer '%s' outputs the instruction 'LOADINT %s' ", intTest[i], intTest[i]);
  }

  //Requirement D.2 Identify Floats
  char *floatTest[] = {"1.1", "1.23456", "123.456"};
  for(int i = 0; i < sizeof(floatTest); i++){
    ok(floatTest[i],"The float '%s' outputs the instruction 'LOADFLT %s'", floatTest[i], floatTest[i]);
  }
}
