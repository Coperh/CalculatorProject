#include <ctap.h>
#include <stdio.h>
#include <string.h>
#include "codegenerator.c"

#define BUFFER_SIZE 100

TESTS{

  //Requirement D.1 Identify Operators
  char Operators[] = {'+', '-', '*', '/'};
  char *operatorInstr[] = {"ADD", "SUB", "MUL", "DIV"};
  for(int i = 0; i < sizeof(Operators); i++){
    ok(OperatorValidator(Operators[i]), "The operator '%c' outputs the instruction '%s'", Operators[i], operatorInstr[i]);
  }

  //Requirement D.2 Identify Integers
  char *intTest[] = {"1", "12", "123456"};
  for(int i = 0; i < sizeof(intTest); i++){
    ok(NumberValidator(intTest[i]), "The integer '%s' outputs the instruction 'LOADINT %s' ", intTest[i], intTest[i]);
  }

  //Requirement D.2 Identify Floats
  char *floatTest[] = {"1.1", "1.23456", "123.456"};
  for(int i = 0; i < sizeof(floatTest); i++){
    ok(NumberValidator(floatTest[i]),"The float '%s' outputs the instruction 'LOADFLT %s'", floatTest[i], floatTest[i]);
  }

  char filename[] = "codeGen.txt";
  char buffer[BUFFER_SIZE];
  FILE *output;

  // Scanner
  // Requirement A.2 Provide an output
  char in[] = "1+2";
  char out[] = "1 + 2 ";
  Scanner(in);
  output = fopen(filename, "w");
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
