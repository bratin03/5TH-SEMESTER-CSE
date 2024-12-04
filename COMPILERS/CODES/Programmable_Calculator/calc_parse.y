%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
extern int yylex();
void yyerror(char *);
int symtab[52];  // Symbol table to store variables
%}

%union {
    int val;
    char id;
}

%token <val> NUM  // Define a token for numbers
%token <id> ID    // Define a token for identifiers (variable names)
%type <val> E     // Define the type for expressions

%left '+' '-'     // Define left-associative operators: + and -
%left '*' '/'     // Define left-associative operators: * and /
%nonassoc UMINUS  // Define non-associative operator: unary minus

%start Line       // The starting symbol for the grammar

%%

Line : Line Statement '\n'
    | Statement '\n'
    ;   

Statement : ID '=' E {
        if ($1 >= 'a' && $1 <= 'z')  // Check if it's a lowercase variable
            symtab[$1 - 'a'] = $3;
        else
            symtab[$1 - 'A' + 26] = $3;
    }
    | ID { 
        printf("%c = ", $1);  // Print the variable name
        if ($1 >= 'a' && $1 <= 'z')  // Check if it's a lowercase variable
            printf("%d\n", symtab[$1 - 'a']);
        else
            printf("%d\n", symtab[$1 - 'A' + 26]);
    }
    ;

E : E '+' E { $$ = $1 + $3; }
    | E '-' E { $$ = $1 - $3; }
    | E '*' E { $$ = $1 * $3; }
    | E '/' E { $$ = $1 / $3; }
    | '-' E %prec UMINUS { $$ = -$2; }  // Handle unary minus
    | '(' E ')' { $$ = $2; }  // Handle parentheses
    | NUM { $$ = $1; }  // Numeric value
    | ID {
        if ($1 >= 'a' && $1 <= 'z')  // Check if it's a lowercase variable
            $$ = symtab[$1 - 'a'];
        else
            $$ = symtab[$1 - 'A' + 26];
    }
    ;
%%

int main() {
    memset(symtab, 0, sizeof(symtab));  // Initialize the symbol table
    yyparse();  // Start the parsing process
    return 0;
}

void yyerror(char *s) {
    printf("%s\n", s);
    exit(1);
}
