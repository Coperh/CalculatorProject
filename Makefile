


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

test: tokenizerTest.t infix2postfixTest.t codegenTest.t vmTest.t calculatorTest.t
	prove ./tokenizerTest.t
	
	prove ./infix2postfixTest.t
	
	prove ./codegenTest.t
	
	prove ./vmTest.t
	
	prove ./calculatorTest.t


tokenizerTest.t: tokenizer.o
	gcc -o tokenizerTest.t tokenizer.o ./src/tokenizerTest.c
	
infix2postfixTest.t: infix2postfix.o
	gcc -o infix2postfixTest.t infix2postfix.o ./src/infix2postfixTest.c

codegenTest.t: code_generator.o
	gcc -o codegenTest.t code_generator.o ./src/codegenTest.c

vmTest.t: virtual_machine.o
	gcc -o vmTest.t virtual_machine.o ./src/virtual_machineTest.c
	
calculatorTest.t: tokenizer.o infix2postfix.o code_generator.o virtual_machine.o
	gcc -o calculatorTest.t ./src/calculatorTest.c tokenizer.o infix2postfix.o code_generator.o virtual_machine.o


clean:
	rm -f *.o *.t *.txt calculator
