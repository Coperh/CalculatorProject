#include <stdio.h>
#include <stdlib.h>
#include <ctap.h>
#include "./headers/infix2postfix.h"

/*
 * Authors: Conor Holden, Jack McCabe, William Yang, Xi Chen
 * requirement C.1: Produce correct order of operations
 * requirement C.2: Handle parentheses
 */

TESTS{
    ok(1 == 1, "test");
    
	char buffer[100];
	FILE *fp;
	FILE *outfp;
	char *input[] = {"1 + 3", "10 + 11 + 12","2 * ( 10 + 1.25 )"};
	char *output[] = {"1 3 + ", "10 11 + 12 + ", "2 10 1.25 + * "};

    
	for (int i = 0; i < sizeof(input)/sizeof(input[0]);i++){
        int i = 0;
        fp = fopen("Tokens.txt", "w");
        fputs(input[i], fp);
        fclose(fp);
        infix2postfix();
        outfp = fopen("Postfix.txt", "r");
        fgets(buffer, 100, outfp);
        is( buffer, output[i], "<%s> == <%s>", buffer,output[i]);
        fclose(outfp);
	}
    
}

