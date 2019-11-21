#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


char buffer[100];
const char valid[] = "+-*/()";
const char outputFile[] = "Tokens.txt";


/*
  Test if a number input is valid int, float or neither.
  all input is confirmed numeric

  number: pointer to the number string
  */
bool NumberValidator(char *number) {
  unsigned char decimalCount = 0;

  int i = 0;
  while (number[i] != '\0') {
    // if decimal count
    if (number[i] == '.') {
      decimalCount++;
    }
    if (decimalCount > 1) {
    return false;
    }
    i++;
  }
  if(decimalCount >=  1 && i <= 2)
      return false;
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
  Scans input for indivual token numbers and characters
*/
bool Scanner(char input[100]) {
    
    if(input[0] == '\n' || input[0] == '\0'){
        printf("No input\n");
        return false;
      
    }
  // open output file
  FILE *output = fopen(outputFile,"w");
  // clear file for empty input

  int i = 0; // intialize index
  // while charcter is not the null pointer or newline
  while(input[i] !='\0' && input[i] !='\n'){
    // get next chracter
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

      // create new string
      char number[len];
      for (int k=0; k < len; k++){
        // if last char, add null pointer
        if (k == len-1){
          number[k] = '\0';
        }
        // else copy chracter from input
        else{
          number[k] = input[i+k];
        }
      }
      // if the number is not valid
      if (!NumberValidator(number)){
        printf("Invalid Number: %s \n", number);
        return false;
      }
      // output to file
      fprintf(output,"%s ",number );
      // get next index
      i = i + len-1;
    }
    // if space, ignore
    else if( c == ' ' ){i++;}

    else {
      // if chracter not valid
      if( !CharacterValidator(c)){
        printf("Invalid Character: %c\n", c);
        return false;
      }
      // output to file
      fprintf(output,"%c ",c );
      i++;
    }
  }
  fclose(output);
  return true;
}


/*
  Tokenizer main program
*/
int tokenizer() {
  // get input for calcuator
  fgets(buffer, sizeof(buffer), stdin);
  // scan input for tokens, if invalid token, return -1
  if(!Scanner(buffer)){
    return -1;
  }
  return 0;
}
