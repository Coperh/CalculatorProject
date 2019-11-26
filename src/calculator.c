/*
 * Calculator
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * Executes the components of the calculate to produce a result
 */


#include <stdio.h>
#include "./headers/tokenizer.h"
#include "./headers/infix2postfix.h"
#include "./headers/code_generator.h"
#include "./headers/virtual_machine.h"


int main(){
  printf("Running Calculator\n");

  if(tokenizer() < 0){
      printf("Invalid Sum\n");
      return -1;}

  infix2postfix();
  code_generator();
  virtual_machine();

  return 0;
}
