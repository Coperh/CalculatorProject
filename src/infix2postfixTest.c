#include <stdio.h>
#include <stdlib.h>
#include <ctap.h>
#include "./headers/infix2postfix.h"

//requirement C.1: Produce correct order of operations
//requirement C.2: Handle parentheses
TESTS{

	char buffer[100];
	FILE *fp;
	FILE *outfp;
	char *input[] = {"1 + 3", "10 + 11 + 12","2 * ( 10 + 1.25 )""};
	char *output[] = {"1 3 + ", "10 11 + 12 + ", "2 10 1.25 + * "};
	fp = fopen("Tokens.txt", "w");

	for (int i = 0; i < sizeof(input);i++){
		fputs(input[i], fp);
		infix2postfix();
		outfp = fopen("Postfix.txt", "r");
		fgets(buffer, 100, outfp);
		is( buffer, output[i], "<%s> == <%s>", buffer,output[i]);
	}
	fclose(fp);
	fclose(outfp);
}

