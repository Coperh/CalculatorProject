#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

int virtual_machine();

int interpreter();

int stack_execute(int command);

int stack_add(double number);

int stack_validator();

void get_answer(char* strOut, unsigned int strSize);
#endif // VIRTUAL_MACHINE_h
