#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


char buffer[100];
const char valid[] = "+-*/() ";


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
  Scans input for numbers and characters
*/
void Scanner(char input[100]) {
  FILE *ouput = fopen("Tokens.txt","w");
  int i = 0;

  // for every character in input
  while(input[i] !='\0' && input[i] !='\n'){
    char c = input[i];

    // if c is a number
    if(isdigit(c)){

      bool sameNumber = true;
      int j = i;
      // while it is the same number
      while(sameNumber){
        // if the next number is a digit, or .
        if(isdigit(input[j+1]) || input[j+1] == '.'){
          j++;
        }
        else{
          sameNumber = false;
        }
      }

      // index 0 - len and null pointer
      int len = j - i + 2;
      printf("%d ", len);
      char number[len];

      // create new string
      for (int k=0; k < len; k++){
        // if last char, add null pointer
        if (k == len-1){
          number[k] = '\0';
        }
        else{
          number[k] = input[i+k];
        }
      }
      printf("%s\n",number );
      // get next number
      i = i + len;
    }

    else if( c == ' ' ){i++;
    }
    else {
      CharacterValidator(c);
      printf("%c\n",c );
      i++;
    }
  }
}


/*
  Tokenizer main program
*/
void tokenizer() {

  fgets(buffer, sizeof(buffer), stdin);
  Scanner(buffer);

}
