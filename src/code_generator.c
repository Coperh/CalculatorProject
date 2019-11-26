/*
 * Code Generator
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * 
 * Converts postfix into instructions that can be executed
 * by the virtual machine
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100

/*
 * Dectects if a number is a float, int or invalid
 * 
 * number: the number being tested
 */
int NumberDetector(char *number) {
    unsigned char decimalCount = 0;
    int i = 0;
    //while there is another character
    while (number[i] != '\0') {
    // if decimal, count    
    if (number[i] == '.') 
      decimalCount++;
    // if the character is not a digit
    else if( !isdigit(number[i]))
        return -1;
    i++;
    }
    if (decimalCount >= 1) //if there are 1 or more dots, its a float
        return 0;
    return 1;
}

//Code Generator main
int code_generator( int argc, char** argv ){

    const char *delimiter_characters = " "; //if there is a blank space 
    const char *filename = "Postfix.txt"; //input file name

    FILE *input_file, *output_file;

    input_file = fopen(filename, "r"); //reads input from "Postfix.txt" file
    output_file = fopen("Instructions.txt", "w"); //write output to "Instructions.txt" file

    char buffer[ BUFFER_SIZE ]; // Buffer size is define above 
    char *last_token;

    if(input_file == NULL){
        fprintf( stderr, "Unable to open file %s\n", filename ); // If the file can't be opened, it prints out an error statement
        return -1;
    }
    else{
        // Read each line into the buffer
        while(fgets(buffer, BUFFER_SIZE, input_file) != NULL ){

            // Gets each token as a string and prints it
            last_token = strtok( buffer, delimiter_characters );
            while( last_token != NULL ){

                switch(last_token[0]){
                    case '+':
                        fprintf(output_file,"ADD\n"); // Prints out the instruction for the operator '+'
                        break;

                    case '-':
                        fprintf(output_file, "SUB\n"); // Prints out the instructions for the operator '-'
                        break;

                    case '*':
                        fprintf(output_file,"MUL\n"); // Prints out the instructions for the operator '*'
                        break;

                    case '/':
                        fprintf(output_file, "DIV\n"); // Prints out the instructions for the operator '/'
                        break;

                    default:
                        if (last_token[0] == '\n'){ 
                            break; // If there is a new line break out of switch 
                        }
                        if(NumberDetector(last_token) == 0){
                            fprintf(output_file, "LOADFLOAT %s\n", last_token); // Print out the instructions for a float token
			}
                        else if(NumberDetector(last_token) == 1){
                            fprintf(output_file, "LOADINT %s\n", last_token); // Prints out the instructions for an int token
			}
                        else{
                            printf("Invlaid input\n"); // If there is an invalid input, return -1
                            return -1;
                        }
                }
                last_token = strtok(NULL, delimiter_characters );
            }
            if(ferror(input_file) ){
                perror( "The following error occurred" ); 
            }
        }
    }
    fclose( input_file ); // closes input file
    fclose( output_file ); // closes output file
	
    return 0;
}
