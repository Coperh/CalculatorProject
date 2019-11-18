#include <stdio.h>

void code_generator() {
	printf("Generating Code\n");
}


/*
-------------------- NOT COMPLETED YET. --------------------
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100

bool NumberValidator(char *number) {
    unsigned char decimalCount = 0;
    int i = 0;

  while (number[i] != '\0') {
    // if decimal count
    if (number[i] == '.') {
      decimalCount++;
    }
    if (decimalCount > 1) {
    return true;
    }
    i++;
  }
  return true;
}
int main( int argc, char** argv ){

    const char *delimiter_characters = " ";
    const char *filename = "postfix.txt";

    FILE *input_file, *output_file;

	input_file = fopen(filename, "r");
	output_file = fopen("instructions.txt", "w");

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

                printf("%s\n", last_token );

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
                        if(NumberValidator(last_token)){
                            fprintf(output_file, "LOADFLT %s\n", last_token);
                        }
                        else
			    fprintf(output_file, "LOADINT %s\n", last_token);
                }
				
                last_token = strtok(NULL, delimiter_characters );
            }

            if(ferror(input_file) ){
                perror( "The following error occurred" );
            }

            fclose( input_file );
        }
    }
    return 0;
}
