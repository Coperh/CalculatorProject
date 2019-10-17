#include <stdio.h>
#include <stdbool.h>


char buffer[100];
const char valid[] = "+-*/() ";



/*
    Scans input for numbers and characters
*/
void Scanner(char input[100]) {}



/*
    Test if a number input is valid int, float or neither.
    all input is confirmed numeric
    
    number: pointer to the number
    size: digits in the number
    
    */
bool NumberValidator(char *number, int size) {
    unsigned char decimalCount = 0;

    for (int i = 0; i < size; i++) {
        // if decimal count
        if (number[i] == '.') {
            decimalCount++;
        }
        if (decimalCount > 1) {
            return false;
        }
        //printf("%d", decimalCount);
    }   
    return true;
}



/*
    Tests if a chracter input is valid or not
*/
bool CharacterValidator(char character) {
    // Check if character is in the list of valid characters
    for (int i = 0; i < sizeof(valid); i++) {
        // if strings are the same (returns 0)
        if (character == valid[i]) {
            return true;
        }
    }
    // if character not in valid list
    return false;
}



/*
    Tokenizer main program
*/
void tokenizer() {

    //fgets(buffer, sizeof(buffer), stdin);
    //Scanner(buffer);
    
}
