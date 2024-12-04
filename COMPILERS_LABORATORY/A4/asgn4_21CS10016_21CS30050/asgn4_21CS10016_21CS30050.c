/*
    Assignment - 3
    21CS10016 - Bratin Mondal
    21CS30050 - Somya Kumar
*/

// Include necessary header files for standard I/O, memory allocation, and string manipulation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare external functions yyparse() and yylex() which are typically defined in a lexer/parser generator like Bison/Flex.
extern int yyparse();
extern int yylex();

// The main function where program execution begins.
int main() 
{
    // Print a header to indicate that parsing is starting.
    printf("\n----------------- Parsing Line No : %d -----------------\n",1);
    
    // Call the yyparse() function to initiate the parsing process.
    yyparse();
    
    // Return 0 to indicate successful program execution.
    return 0;
}
