%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "y.tab.h"  // Include the generated Bison header file for token definitions
extern void yyerror(char *s);  // Declare the error-handling function
%}

%%

[0-9]+ {
    yylval.val = atoi(yytext);  // Convert the matched text to an integer and store it in yylval
    return NUM;  // Return the NUM token
}

[ \t]   ;  // Ignore whitespace and tabs

[a-zA-Z] {
    yylval.id = yytext[0];  // Store the first character of the matched text in yylval
    return ID;  // Return the ID token
}

\n|. { return yytext[0]; }  // Return any character not matched as itself

%%

int yywrap(void) {
    return 1;  // Indicates the end of input to the lexer
}
