%{
    /* Definitions for token types */
    #define KEYWORD 1                 /* Token type for keywords */
    #define IDENTIFIER 2              /* Token type for identifiers */
    #define INTEGER_CONSTANT 3        /* Token type for integer constants */
    #define FLOATING_CONSTANT 4       /* Token type for floating-point constants */
    #define ENUMERATION_CONSTANT 5    /* Token type for enumeration constants */
    #define CHARACTER_CONSTANT 6      /* Token type for character constants */
    #define STRING_LITERAL 7          /* Token type for string literals */
    #define PUNCTUATOR 8              /* Token type for punctuators */
    #define MULTI_LINE_COMMENT 9      /* Token type for multi-line comments */
    #define SINGLE_LINE_COMMENT 10    /* Token type for single-line comments */
    #define UNDEFINED 11              /* Token type for undefined or unrecognized input */
%}

/* Regular expression patterns for various tokens */

/* Keywords */
KEYWORD                     "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imagina  ry"

/* Escape sequences */
ESCAPE_SEQUENCE             "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"

/* Punctuators */
PUNCTUATOR                  "["|"++"|"/"|"?"|"="|","|"]"|"("|"{"|"}"|"."|"->"|"*"|"+"|"-"|"~"|"!"|"%"|"<<"|">>"|"<"|">"|"<="|">="|":"|";"|"..."|"*="|"/="|"%="|"+="|"-="|"<<="|"#"|"--"|")"|"&"|"=="|"^"|"|"|"&&"|">>="|"!="|"&="|"^="|"||"|"|"

/* Single-line and multi-line comments */
SINGLE_LINE_COMMENT    	    "//"[^("\n")]*
MULTI_LINE_COMMENT		    "\/\*"[^\*]*\*+([^\/\*][^\*]*\*+)*"/"

/* Digit and identifier patterns */
DIGIT                       [0-9]
IDENTIFIER_NONDIGIT         [a-zA-z]|"_"
IDENTIFIER                  {IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

/* Numeric constants */
ZERO                        "0"
EXPONENTIAL_NOTATION        "e"|"E"
SIGN                        "+"|"-"
NONZERO_DIGIT [1-9]
DIGIT_SEQUENCE {DIGIT}+


INTEGER_CONSTANT	        {NONZERO_DIGIT}{DIGIT}*|{ZERO}

EXPONENT_PART               {EXPONENTIAL_NOTATION}({SIGN}?){DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT         {DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.

FLOATING_CONSTANT           {FRACTIONAL_CONSTANT}({EXPONENT_PART}?)|{DIGIT_SEQUENCE}{EXPONENT_PART}

/* Enumeration constant */
ENUMERATION_CONSTANT        {IDENTIFIER}

/* Character constants */
C_CHAR                      [^\'\n\\]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE             {C_CHAR}+

CHARACTER_CONSTANT          \'{C_CHAR_SEQUENCE}\'

/* String literals */
S_CHAR                      {ESCAPE_SEQUENCE}|[^("\""|"\\"|"\n")]
S_CHAR_SEQUENCE             {S_CHAR}+

STRING_LITERAL              \"({S_CHAR_SEQUENCE}?)\"

/* Whitespace */
WHITE_SPACE                 [ \n\t\v\f]



%%



{SINGLE_LINE_COMMENT}      { return SINGLE_LINE_COMMENT; }
{MULTI_LINE_COMMENT}       { return MULTI_LINE_COMMENT; }

{KEYWORD}                  { return KEYWORD; }
{IDENTIFIER}               { return IDENTIFIER; }

{INTEGER_CONSTANT}         { return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}        { return FLOATING_CONSTANT; }

{CHARACTER_CONSTANT}       { return CHARACTER_CONSTANT; }

{STRING_LITERAL}           { return STRING_LITERAL; }

{PUNCTUATOR}               { return PUNCTUATOR; }

{WHITE_SPACE}              { /* Do nothing */ }

.                          { return UNDEFINED; }

%%

