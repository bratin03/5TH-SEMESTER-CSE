/*
    Assignment - 3
    21CS10016 - Bratin Mondal
    21CS30050 - Somya Kumar
*/

#include <stdio.h>

// Token types defined using preprocessor macros
#define KEYWORD 1              /* Token type for keywords */
#define IDENTIFIER 2           /* Token type for identifiers */
#define INTEGER_CONSTANT 3     /* Token type for integer constants */
#define FLOATING_CONSTANT 4    /* Token type for floating-point constants */
#define ENUMERATION_CONSTANT 5 /* Token type for enumeration constants */
#define CHARACTER_CONSTANT 6   /* Token type for character constants */
#define STRING_LITERAL 7       /* Token type for string literals */
#define PUNCTUATOR 8           /* Token type for punctuators */
#define MULTI_LINE_COMMENT 9   /* Token type for multi-line comments */
#define SINGLE_LINE_COMMENT 10 /* Token type for single-line comments */
#define UNDEFINED 11           /* Token type for undefined or unrecognized input */

// External functions and variables provided by the lexer (Flex)
extern int yylex();
extern char *yytext;

int main()
{
    int token_val;

    // Loop to continuously get tokens from the lexer
    while (token_val = yylex())
    {
        // Switch case to identify and print the token type and value
        switch (token_val)
        {
        case KEYWORD:
            printf("<KEYWORD, %d, %s>\n", token_val, yytext);
            break;
        case IDENTIFIER:
            printf("<IDENTIFIER, %d, %s>\n", token_val, yytext);
            break;
        case INTEGER_CONSTANT:
            printf("<INTEGER_CONSTANT, %d, %s>\n", token_val, yytext);
            break;
        case FLOATING_CONSTANT:
            printf("<FLOAT_CONSTANT, %d, %s>\n", token_val, yytext);
            break;
        case CHARACTER_CONSTANT:
            printf("<CHARACTER_CONSTANT, %d, %s>\n", token_val, yytext);
            break;
        case STRING_LITERAL:
            printf("<STRING_LITERAL, %d, %s>\n", token_val, yytext);
            break;
        case PUNCTUATOR:
            printf("<PUNCTUATOR, %d, %s>\n", token_val, yytext);
            break;
        case MULTI_LINE_COMMENT:
            printf("<MULTI_LINE_COMMENT, %d>\n", token_val);
            break;
        case SINGLE_LINE_COMMENT:
            printf("<SINGLE_LINE_COMMENT, %d>\n", token_val);
            break;
        default:
            printf("<INVALID_TOKEN, %d, %s>\n", token_val, yytext);
            break;
        }
    }

    return 0;
}
