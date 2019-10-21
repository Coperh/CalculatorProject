

calculator: ./src/calculator.c tokenizer.o infix2postfix.o code_generator.o virtual_machine.o
	gcc -o calculator ./src/calculator.c


tokenizer.o: ./src/tokenizer.c
	gcc -o tokenizer.o ./src/tokenizer.c
	
infix2postfix.o: ./src/infix2postfix.c
	gcc -o infix2postfix.o ./src/infix2postfix.c

code_generator.o: ./src/code_generator.c
	gcc -o code_generator.o ./src/code_generator.c

virtual_machine.o: ./src/virtual_machine.c
	gcc -o virtual_machine.o ./src/virtual_machine.c
