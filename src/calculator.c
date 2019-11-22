#include <stdio.h>
#include "./headers/tokenizer.h"
#include "./headers/infix2postfix.h"
#include "./headers/code_generator.h"
#include "./headers/virtual_machine.h"



int main(){
  printf("Running Calculator\n");

  if(tokenizer() < 0){
      printf("boop");
      return -1;}
  infix2postfix();
  code_generator();
  virtual_machine();

  return 0;
}
