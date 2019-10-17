#include <stdio.h>
#include "tokenizer.h"
#include "infix2postfix.h"
#include "code_generator.h"
#include "virtual_machine.h"



int main(){
    printf("Running Calculator\n");
    tokenizer();
	infix2postfix();
	code_generator();
	virtual_machine();

	// wait so program does not close automatically
	gets();

    return 0;
}
