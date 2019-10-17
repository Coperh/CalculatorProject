#include <stdio.h>
#include <stdbool.h>
#include <string.h>



char buffer[100];
char valid[] = "+-*/() ";

/*
    Tokenizer main program
*/
void tokenizer(){

    fgets(buffer, sizeof(buffer), stdin);
    //Scanner(buffer);
    printf(buffer);
}

/*
    Scans input for numbers and characters

*/
void Scanner(char input[100]) {


	


}

/*
    Test if a number input is valid int, float or neither.
*/
bool NumberValidator(char* number) {

    return true;
}

/*
    Tests if a chracter input is valid or not
*/
bool CharacterValidator(char character) {
    // Check if character is in the list of valid characters
    for (int i = 0; i < sizeof(valid) / sizeof(valid[0]); i++) {
        // if strings are the same (returns 0)
        if (strcomp(character,valid[i])==0 ) {
            return true;
        }   
    }
    // if character not in valid list
    return false;   
}
