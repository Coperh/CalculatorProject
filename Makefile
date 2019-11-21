


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

test: tokenizerTest.t
	prove -v ./*.t


tokenizerTest.t: tokenizer.o
	gcc -o tokenizerTest.t tokenizer.o ./src/tokenizerTest.c



clear:
	rm -f *.o *.t calculator
