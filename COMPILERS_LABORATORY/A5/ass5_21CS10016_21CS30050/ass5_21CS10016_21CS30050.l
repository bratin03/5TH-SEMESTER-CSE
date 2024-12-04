/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

%{
    // Include necessary header files
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <bits/stdc++.h>

    // Include custom header files
    #include "ass5_21CS10016_21CS30050_translator.h"
    #include "ass5_21CS10016_21CS30050.tab.h"

    // Declare external variables
    extern int lineno;      // Line number in the source code
    extern YYSTYPE yylval;  // Value associated with a token
%}

%x MULTI_LINE_COMMENT
%x SINGLE_LINE_COMMENT

DIGIT                   [0-9]
IDENTIFIER_NONDIGIT     [a-zA-Z]|"_"
ESCAPE_SEQUENCE         "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
KEYWORD                 "auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"_Bool"|"continue"|"if"|"static"|"_Complex"|"default"|"inline"|"struct"|"_Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"
IDENTIFIER              {IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

NONZERO_DIGIT           [1-9]
INTEGER_CONSTANT        ({NONZERO_DIGIT}{DIGIT}*)|[0]+

SIGN                    [+-]
DIGIT_SEQUENCE          {DIGIT}+
EXPONENT_PART           [Ee]({SIGN}?){DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT     (({DIGIT_SEQUENCE}?)("."){DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}("."))
FLOATING_CONSTANT       ({FRACTIONAL_CONSTANT}({EXPONENT_PART}?))|({DIGIT_SEQUENCE}{EXPONENT_PART})

C_CHAR                  [^\\\'\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE         {C_CHAR}+
CHARACTER_CONSTANT      \'{C_CHAR_SEQUENCE}\'

S_CHAR                  [^\\\"\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE         {S_CHAR}+
STRING_LITERAL          \"{S_CHAR_SEQUENCE}?\"

PUNCTUATOR              "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"


ENUMERATION_CONSTANT   {IDENTIFIER}

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
"("                         { return PARENTHESIS_OPEN; }
")"                         { return PARENTHESIS_CLOSE; }
"{"                         { return CURLY_BRACE_OPEN; }
"}"                         { return CURLY_BRACE_CLOSE; }
"["                         { return SQR_BRACE_OPEN; }
"]"                         { return SQR_BRACE_CLOSE; }
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



{IDENTIFIER}                { yylval.sym_ptr = ST->lookup(yytext); return IDENTIFIER; }
{FLOATING_CONSTANT}         { yylval.fVal = atof(yytext); return FLOATING_CONSTANT; }
{INTEGER_CONSTANT}          { yylval.iVal = atoi(yytext); return INTEGER_CONSTANT; }
{CHARACTER_CONSTANT}        { yylval.cVal = yytext; return CHARACTER_CONSTANT; }
"\n"                        { lineno++; }
{STRING_LITERAL}            { yylval.cVal = yytext; return STRING_LITERAL; }







"/*"                        { BEGIN(MULTI_LINE_COMMENT); }
<MULTI_LINE_COMMENT>"*/"    { BEGIN(INITIAL); }
<MULTI_LINE_COMMENT>.       { }
<MULTI_LINE_COMMENT>"\n"    { lineno++; }

"//"                        { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>"\n"   { BEGIN(INITIAL); lineno++; }
<SINGLE_LINE_COMMENT>.      { }

[ \t]           { }
.                           { }

%%

int yywrap(void)
{
    return 1; // Indicate the end of input to the lexer
}
