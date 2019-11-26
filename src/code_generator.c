#include <stdio.h>


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100

//Checks for float
//This part from tokenizer.c
bool NumberDetector(char *number) {
    unsigned char decimalCount = 0;
    int i = 0;

  while (number[i] != '\0') {
    // if decimal count
    if (number[i] == '.') {
      decimalCount++;
    }
    if (decimalCount >= 1) { //if there are 1 or more dots, it's a float
    return true;
    }
    i++;
  }
  return false;
}

bool OperatorValidator(char character) {
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

int code_generator( int argc, char** argv ){

    const char *delimiter_characters = " ";
    const char *filename = "Postfix.txt";

    FILE *input_file, *output_file;

	input_file = fopen(filename, "r");
	output_file = fopen("Instructions.txt", "w");

    char buffer[ BUFFER_SIZE ];
    char *last_token;

    if(input_file == NULL){
        fprintf( stderr, "Unable to open file %s\n", filename );
    }
	else{

        // Read each line into the buffer
        while(fgets(buffer, BUFFER_SIZE, input_file) != NULL ){

            // Gets each token as a string and prints it
            last_token = strtok( buffer, delimiter_characters );
            while( last_token != NULL ){


                switch(last_token[0]){
                    case '+':
                        fprintf(output_file,"ADD\n");
                        break;

                    case '-':
                        fprintf(output_file, "SUB\n");
                        break;

                    case '*':
                        fprintf(output_file,"MUL\n");
                        break;

                    case '/':
                        fprintf(output_file, "DIV\n");
                        break;

		               default:
												if (last_token[0] == '\n'){
													break;
												}
                        if(NumberDetector(last_token)){
                            fprintf(output_file, "LOADFLOAT %s\n", last_token);
                        }
                        else
			                fprintf(output_file, "LOADINT %s\n", last_token);
                }
                printf("%s\n", last_token );
                last_token = strtok(NULL, delimiter_characters );
            }
            if(ferror(input_file) ){
                perror( "The following error occurred" );
            }

        }
    }
		fclose( input_file );
		fclose( output_file );
    return 0;
}
