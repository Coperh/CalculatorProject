#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <stdbool.h>

int tokenizer();
bool NumberValidator(char *number);
bool CharacterValidator(char character);
bool Scanner(char input[100]);

#endif // TOKENIZER_H
