%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    extern void yyerror(const char *);

%}

%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT

DIGIT                               [0-9]
IDENTIFIER_NONDIGIT                 [a-zA-z]|"_"
ESCAPE_SEQUENCE                     "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"  
IDENTIFIER                          {IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

ZERO                                "0"
EXPONENTIAL_NOTATION                "e"|"E"
SIGN                                "+"|"-"
NONZERO_DIGIT                       [1-9]
DIGIT_SEQUENCE                      {DIGIT}+

INTEGER_CONSTANT	                {NONZERO_DIGIT}{DIGIT}*|{ZERO}

EXPONENT_PART                       {EXPONENTIAL_NOTATION}({SIGN}?){DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT                 {DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.

FLOATING_CONSTANT                   {FRACTIONAL_CONSTANT}({EXPONENT_PART}?)|{DIGIT_SEQUENCE}{EXPONENT_PART}

ENUMERATION_CONSTANT                {IDENTIFIER}

C_CHAR                              [^\'\n\\']|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE                     {C_CHAR}+
CHARACTER_CONSTANT                  \'{C_CHAR_SEQUENCE}\'

S_CHAR                              {ESCAPE_SEQUENCE}|[^("\""|"\\"|"\n")]
S_CHAR_SEQUENCE                     {S_CHAR}+
STRING_LITERAL                      \"({S_CHAR_SEQUENCE}?)\"
WHITESPACE                          [ \t\r]

%%

"auto"                      { return AUTO; }
"break"                     { return BREAK; }
"case"                      { return CASE; }
"char"                      { return CHAR; }
"const"                     { return CONST; }
"continue"                  { return CONTINUE; }
"default"                   { return DEFAULT; }
"do"                        { return DO; }
"double"                    { return DOUBLE; }
"else"                      { return ELSE; }
"enum"                      { return ENUM; }
"extern"                    { return EXTERN; }
"float"                     { return FLOAT; }
"for"                       { return FOR; }
"goto"                      { return GOTO; }
"if"                        { return IF; }
"inline"                    { return INLINE; }
"int"                       { return INT; }
"long"                      { return LONG; }
"register"                  { return REGISTER; }
"restrict"                  { return RESTRICT; }
"return"                    { return RETURN; }
"short"                     { return SHORT; }
"signed"                    { return SIGNED; }
"sizeof"                    { return SIZEOF; }
"static"                    { return STATIC; }
"struct"                    { return STRUCT; }
"switch"                    { return SWITCH; }
"typedef"                   { return TYPEDEF; }
"union"                     { return UNION; }
"unsigned"                  { return UNSIGNED; }
"void"                      { return VOID; }
"volatile"                  { return VOLATILE; }
"while"                     { return WHILE; }
"_Bool"                     { return BOOL; }
"_Complex"                  { return COMPLEX; }
"_Imaginary"                { return IMAGINARY; }


{IDENTIFIER}                { yylval.idVal = strdup(yytext); return IDENTIFIER; }
{INTEGER_CONSTANT}          { yylval.iVal = atoi(yytext); return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}         { yylval.fVal = atof(yytext); return FLOATING_CONSTANT; }
{CHARACTER_CONSTANT}        { yylval.cVal = strdup(yytext); return CHARACTER_CONSTANT; }
{STRING_LITERAL}            { yylval.sVal = strdup(yytext); return STRING_LITERAL; }

"="                         { return EQ; }
":"                         { return COLON; }
";"                         { return SEMI_COLON; }
"?"                         { return QUESTION_MARK; }
"++"                        { return INC_OP; }
"->"                        { return PTR_OP; }
"<<"                        { return LEFT_OP; }
">>"                        { return RIGHT_OP; }
"<"                         { return LESS_THAN; }
">"                         { return GREATER_THAN; }
"<="                        { return LTE_OP; }
">="                        { return GTE_OP; }
"..."                       { return ELLIPSIS; }
"*="                        { return MUL_ASSIGN; }
"/="                        { return DIV_ASSIGN; }
"%="                        { return MOD_ASSIGN; }
"+="                        { return ADD_ASSIGN; }
"-="                        { return SUB_ASSIGN; }
"<<="                       { return LEFT_ASSIGN; }
"--"                        { return DEC_OP; }
"=="                        { return EQ_OP; }
"&&"                        { return AND_OP; }
"||"                        { return OR_OP; }
">>="                       { return RIGHT_ASSIGN; }
"!="                        { return NE_OP; }
"&="                        { return AND_ASSIGN; }
"|="                        { return OR_ASSIGN; }
"^="                        { return XOR_ASSIGN; }
"("                         { return PARENTHESIS_OPEN; }
")"                         { return PARENTHESIS_CLOSE; }
"{"                         { return CURLY_BRACE_OPEN; }
"}"                         { return CURLY_BRACE_CLOSE; }
"["                         { return SQR_BRACE_OPEN; }
"]"                         { return SQR_BRACE_CLOSE; }
"."                         { return DOT; }
"&"                         { return BITWISEAND; }
"|"                         { return BITWISEOR; }
"^"                         { return BITWISEXOR; }
"*"                         { return STAR; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"~"                         { return NOT; }
"!"                         { return EXCLAMATION; }
"/"                         { return DIVIDE; }
"%"                         { return PERCENTAGE; }
","                         { return COMMA; }
"#"                         { return HASH; }

"/*"                        { BEGIN(MULTI_LINE_COMMENT); }
<MULTI_LINE_COMMENT>"*/"    { BEGIN(INITIAL); }
<MULTI_LINE_COMMENT>.       { }
<MULTI_LINE_COMMENT>"\n"    { yylineno++; printf("\n----------------- Parsing Line No : %d -----------------\n", yylineno); }

"//"                        { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>"\n"   { BEGIN(INITIAL); yylineno++;printf("\n----------------- Parsing Line No : %d -----------------\n", yylineno); }
<SINGLE_LINE_COMMENT>.      { }
\n                          { yylineno++; printf("\n----------------- Parsing Line No : %d -----------------\n", yylineno); }
{WHITESPACE}                { }
.                           { printf("ERROR [Line %d] : Invalid Token %s\n",yylineno,yytext); return INVALID_TOKEN; }

%%

int yywrap(void)
{
    return 1;
}
