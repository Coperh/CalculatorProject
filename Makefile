


Calculator:  tokenizer.o infix2postfix.o code_generator.o virtual_machine.o
	gcc -c ./src/calculator.c
	gcc -o calculator calculator.o tokenizer.o infix2postfix.o code_generator.o virtual_machine.o

tokenizer.o:
	gcc -c ./src/tokenizer.c

infix2postfix.o:
	gcc -c  ./src/infix2postfix.c

code_generator.o:
	gcc -c  ./src/code_generator.c

virtual_machine.o:
	gcc -c ./src/virtual_machine.c

clear:
	rm *.o calcuator
