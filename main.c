#include <stdio.h>
#include "tokenizer.h"
#include "infix2postfix.h"
#include "code_generator.h"
#include "virtual_machine.h"



int main(){
  printf("Running Calculator\n");

  if (tokenizer() < 0){
    printf("Could not tokenize\n");
    return -1;
  }
	infix2postfix();
	code_generator();
	virtual_machine();

  return 0;
}
