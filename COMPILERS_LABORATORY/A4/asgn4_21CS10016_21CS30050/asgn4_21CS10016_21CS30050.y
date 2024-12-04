%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex();
    void yyerror(char *);
    void yyinfo(char *);
    extern int yylineno;
    extern char* yytext;
%}

%union{
    int iVal;
    float fVal;
    char *cVal;
    char *sVal;
    char *idVal;
}

%token EXTERN 
%token STATIC 
%token AUTO 
%token REGISTER
%token VOID 
%token CHAR 
%token SHORT 
%token INT 
%token LONG 
%token FLOAT 
%token DOUBLE 
%token SIGNED 
%token UNSIGNED 
%token BOOL 
%token COMPLEX 
%token IMAGINARY
%token CONST 
%token ENUM 
%token INLINE 
%token RESTRICT 
%token VOLATILE
%token IF 
%token ELSE 
%token SWITCH  
%token CASE 
%token DEFAULT 
%token WHILE 
%token CONTINUE 
%token DO 
%token GOTO 
%token FOR 
%token RETURN 
%token BREAK
%token INC_OP 
%token DEC_OP 
%token PTR_OP 
%token EQ
%token CURLY_BRACE_OPEN 
%token CURLY_BRACE_CLOSE 
%token PARENTHESIS_OPEN 
%token PARENTHESIS_CLOSE 
%token SQR_BRACE_OPEN 
%token SQR_BRACE_CLOSE
%token COLON SEMI_COLON 
%token ELLIPSIS 
%token QUESTION_MARK
%token SIZEOF
%token LEFT_OP 
%token RIGHT_OP 
%token EQ_OP 
%token NE_OP 
%token LTE_OP 
%token GTE_OP
%token AND_OP 
%token OR_OP 
%token ADD_ASSIGN 
%token SUB_ASSIGN 
%token MUL_ASSIGN 
%token DIV_ASSIGN 
%token MOD_ASSIGN 
%token RIGHT_ASSIGN 
%token LEFT_ASSIGN 
%token OR_ASSIGN 
%token AND_ASSIGN 
%token XOR_ASSIGN
%token LESS_THAN 
%token GREATER_THAN 
%token DOT 
%token BITWISEAND 
%token BITWISEOR 
%token BITWISEXOR 
%token STAR 
%token PLUS 
%token MINUS 
%token NOT 
%token EXCLAMATION 
%token DIVIDE 
%token PERCENTAGE 
%token COMMA 
%token HASH
%token STRUCT 
%token TYPEDEF 
%token UNION

%nonassoc PARENTHESIS_CLOSE
%nonassoc ELSE


%token <sVal> IDENTIFIER
%token <iVal> INTEGER_CONSTANT
%token <fVal> FLOATING_CONSTANT
%token <cVal> CHARACTER_CONSTANT
%token <sVal> STRING_LITERAL

%token INVALID_TOKEN 

%start translation_unit

%%

// Expressions 

primary_expression: 
      IDENTIFIER
        { 
            yyinfo("primary-expression -> identifier");
            printf("IDENTIFIER = %s\n", $1); 
        }
    | CHARACTER_CONSTANT
        { 
            yyinfo("primary-expression -> character-constant");
            printf("CHARACTER_CONSTANT = %s\n", $1); 
        }
    | INTEGER_CONSTANT
        {
            yyinfo("primary-expression -> integer-constant"); 
            printf("INTEGER_CONSTANT = %d\n", $1); 
        }
    | FLOATING_CONSTANT
        {
            yyinfo("primary-expression -> float-constant");
            printf("FLOATING_CONSTANT = %f\n", $1);  
        }
    | STRING_LITERAL
        { 
            yyinfo("primary-expression -> string-literal");
            printf("STRING_LITERAL = %s\n", $1); 
        }
    | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
        { yyinfo("primary-expression -> (expression)"); }
    ;

postfix_expression:
      primary_expression
        { yyinfo("postfix-expression -> primary-expression"); }
    | postfix_expression SQR_BRACE_OPEN expression SQR_BRACE_CLOSE
        { yyinfo("postfix-expression -> postfix-expression[expression]"); }
    | postfix_expression PARENTHESIS_OPEN PARENTHESIS_CLOSE
        { yyinfo("postfix-expression -> postfix-expression()"); }
    | postfix_expression PARENTHESIS_OPEN argument_expression_list PARENTHESIS_CLOSE
        { yyinfo("postfix-expression -> postfix-expression(argument-expression-list)"); }
    | postfix_expression DOT IDENTIFIER
        { 
            yyinfo("postfix-expression -> postfix-expression.identifier");
            printf("IDENTIFIER = %s\n", $3);  
        }
    | postfix_expression PTR_OP IDENTIFIER
        { 
            yyinfo("postfix-expression -> postfix-expression->identifier"); 
            printf("IDENTIFIER = %s\n", $3); 
        }
    | postfix_expression INC_OP
        { yyinfo("postfix-expression -> postfix-expression++"); }
    | postfix_expression DEC_OP
        { yyinfo("postfix-expression -> postfix-expression--"); }
    | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        { yyinfo("postfix-expression -> (type-name){initializer-list}"); }
    | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        { yyinfo("postfix expression -> (type-name){initializer-list,}"); }
    ;

argument_expression_list:
      assignment_expression
        { yyinfo("argument-expression-list -> assignment-expression"); }
    | argument_expression_list COMMA assignment_expression
        { yyinfo("argument-expression-list -> argument-expression-list,assignment-expression"); }
    ;

unary_expression:
      postfix_expression
        { yyinfo("unary-expression -> postfix-expression"); }
    | INC_OP unary_expression
        { yyinfo("unary-expression -> ++unary-expression"); }
    | DEC_OP unary_expression
        { yyinfo("unary-expression -> --unary-expression"); }
    | unary_operator cast_expression
        { yyinfo("unary-expression -> unary-operator cast-expression"); }
    | SIZEOF unary_expression
        { yyinfo("unary-expression -> sizeof unary-expression"); }
    | SIZEOF PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE
        { yyinfo("unary-expression -> sizeof (type_name)"); }
    ;

unary_operator:
      BITWISEAND
        { yyinfo("unary-operator -> &"); }
    | STAR
        { yyinfo("unary-operator -> *"); }
    | PLUS  
        { yyinfo("unary-operator -> +"); }
    | MINUS
        { yyinfo("unary-operator -> -"); }
    | NOT
        { yyinfo("unary-operator -> ~"); }
    | EXCLAMATION
        { yyinfo("unary-operator -> !"); }
    ;

cast_expression:
      unary_expression
        { yyinfo("cast-expression -> unary-expression"); }
    | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE cast_expression
        { yyinfo("cast-expression -> (type-name) cast-expression"); }
    ;

multiplicative_expression:
      cast_expression
        { yyinfo("multiplicative-expression -> cast-expression"); }
    | multiplicative_expression STAR cast_expression
        { yyinfo("multiplicative-expression -> multiplicative-expression * cast-expression"); }
    | multiplicative_expression DIVIDE cast_expression
        { yyinfo("multiplicative-expression -> multiplicative-expression / cast-expression"); }
    | multiplicative_expression PERCENTAGE cast_expression
        { yyinfo("multiplicative-expression -> multiplicative-expression % cast-expression"); }
    ;

additive_expression:
      multiplicative_expression
        { yyinfo("additive-expression -> multiplicative-expression"); }
    | additive_expression PLUS multiplicative_expression
        { yyinfo("additive-expression -> additive-expression + multiplicative-expression"); }
    | additive_expression MINUS multiplicative_expression
        { yyinfo("additive-expression -> additive-expression - multiplicative-expression"); }
    ;

shift_expression:
      additive_expression
        { yyinfo("shift-expression -> additive-expression"); }
    | shift_expression LEFT_OP additive_expression
        { yyinfo("shift-expression -> shift-expression << additive-expression"); }
    | shift_expression RIGHT_OP additive_expression
        { yyinfo("shift-expression -> shift-expression >> additive-expression"); }
    ;

relational_expression:
    shift_expression
        { yyinfo("relational-expression -> shift-expression"); }
    | relational_expression LESS_THAN shift_expression
        { yyinfo("relational-expression -> relational-expression < shift-expression"); }
    | relational_expression GREATER_THAN shift_expression
        { yyinfo("relational-expression -> relational-expression > shift-expression"); }
    | relational_expression GTE_OP shift_expression
        { yyinfo("relational-expression -> relational-expression >= shift-expression"); }
    | relational_expression LTE_OP shift_expression
        { yyinfo("relational-expression -> relational-expression <= shift-expression"); }

equality_expression:
      relational_expression
        { yyinfo("equality-expression -> relational-expression"); }
    | equality_expression EQ_OP relational_expression
        { yyinfo("equality-expression -> equality-expression == relational-expression"); }
    | equality_expression NE_OP relational_expression
        { yyinfo("equality-expression -> equality-expression != relational-expression"); }
    ;

and_expression:
    equality_expression
        { yyinfo("and-expression -> equality-expression"); }
    | and_expression BITWISEAND equality_expression
        { yyinfo("and-expression -> and-expression & equality-expression"); }
    ;

exclusive_or_expression:
    and_expression
        { yyinfo("exclusive-or-expression -> and-expression"); }
    | exclusive_or_expression BITWISEXOR and_expression
        { yyinfo("exclusive-or-expression -> exclusive-or-expression ^ and-expression"); }
    ;

inclusive_or_expression:
    exclusive_or_expression
        { yyinfo("inclusive-or-expression -> exclusive-or-expression"); }
    | inclusive_or_expression BITWISEOR exclusive_or_expression
        { yyinfo("inclusive-or-expression -> inclusive-or-expression | exclusive-or-expression"); }
    ;

logical_and_expression:
    inclusive_or_expression
        { yyinfo("logical and expression -> inclusive or expression"); }
    | logical_and_expression AND_OP inclusive_or_expression
        { yyinfo("logical and expression -> logical and expression && inclusive or expression"); }
    ;

logical_or_expression:
    logical_and_expression
        { yyinfo("logical-or-expression -> logical-and-expression"); }
    | logical_or_expression OR_OP logical_and_expression
        { yyinfo("logical-or-expression -> logical-or-expression || logical-and-expression"); }

conditional_expression:
    logical_or_expression
        { yyinfo("conditional-expression -> logical-or-expression"); }
    | logical_or_expression QUESTION_MARK expression COLON conditional_expression
        { yyinfo("conditional-expression -> logical-or-expression ? expression : conditional-expression"); }
    ;

assignment_expression:
    conditional_expression
        { yyinfo("assignment-expression -> conditional-expression"); }
    | unary_expression assignment_operator assignment_expression
        { yyinfo("assignment-expression -> unary-expression assign-operator assignment-expression"); }
    ;

assignment_operator:
    EQ
        { yyinfo("assignment-operator -> ="); }
    | MUL_ASSIGN
        { yyinfo("assignment-operator -> *="); }
    | DIV_ASSIGN
        { yyinfo("assignment-operator -> /="); }
    | MOD_ASSIGN
        { yyinfo("assignment-operator -> %="); }
    | ADD_ASSIGN
        { yyinfo("assignment-operator -> +="); }
    | SUB_ASSIGN
        { yyinfo("assignment-operator -> -="); }
    | LEFT_ASSIGN
        { yyinfo("assignment-operator -> <<="); }
    | RIGHT_ASSIGN
        { yyinfo("assignment-operator -> >>="); }
    | AND_ASSIGN
        { yyinfo("assignment-operator -> &="); }
    | XOR_ASSIGN
        { yyinfo("assignment-operator -> ^="); }
    | OR_ASSIGN
        { yyinfo("assignment-operator -> |="); }
    ;

expression:
    assignment_expression
        { yyinfo("expression -> assignment-expression"); }
    | expression COMMA assignment_expression
        { yyinfo("expression -> expression , assignment-expression"); }
    ;

expression_opt:
    expression
        { yyinfo("expression-opt -> expression"); }
    | 
        { yyinfo("expression-opt -> epsilon"); }
    ;

constant_expression:
    conditional_expression
        { yyinfo("constant-expression -> conditional-expression"); }
    ;

// Declarations

declaration:
    declaration_specifiers init_declarator_list_opt SEMI_COLON
        { yyinfo("declaration -> declaration-specifiers init-declarator-list_opt"); }
    ;

init_declarator_list_opt:
    init_declarator_list
        { yyinfo("init-declarator-list_opt -> init-declarator-list"); }
    |
        { yyinfo("init-declarator-list-opt -> epsilon"); }
    ;

declaration_specifiers_opt:
    declaration_specifiers
        { yyinfo("declaration-specifiers-opt -> declaration-specifiers"); }
    |
        { yyinfo("declaration-specifiers-opt -> epsilon"); }
    ;

declaration_specifiers:
    storage_class_specifier declaration_specifiers_opt
        { yyinfo("declaration-specifiers -> storage_class-specifier declaration-specifiers-opt"); }
    | type_specifier declaration_specifiers_opt
        { yyinfo("declaration-specifiers -> type-specifier declaration-specifiers-opt"); }
    | type_qualifier declaration_specifiers_opt
        { yyinfo("declaration-specifiers -> type-qualifier declaration-specifiers-opt"); }
    | function_specifier declaration_specifiers_opt
        { yyinfo("declaration-specifiers -> function-specifier declaration-specifiers-opt"); }
    ;

init_declarator_list:
    init_declarator
        { yyinfo("init-declarator-list -> init-declarator"); }
    | init_declarator_list COMMA init_declarator
        { yyinfo("init-declarator-list -> init-declarator-list , init-declarator"); }
    ;

init_declarator:
    declarator
        { yyinfo("init-declarator -> declarator"); }
    | declarator EQ initializer
        { yyinfo("init-declarator -> declarator = initializer"); }
    ;

storage_class_specifier:
    EXTERN
        { yyinfo("storage-class-specifier -> extern"); }
    | STATIC
        { yyinfo("storage-class-specifier -> static"); }
    | AUTO
        { yyinfo("storage-class-specifier -> auto"); }
    | REGISTER
        { yyinfo("storage-class-specifier -> register"); }
    ;

type_specifier:
    VOID
        { yyinfo("type-specifier -> void"); }
    | CHAR
        { yyinfo("type-specifier -> char"); }
    | SHORT
        { yyinfo("type-specifier -> short"); }
    | INT
        { yyinfo("type-specifier -> int"); }
    | LONG
        { yyinfo("type-specifier -> long"); }
    | FLOAT
        { yyinfo("type-specifier -> float"); }
    | DOUBLE
        { yyinfo("type-specifier -> double"); }
    | SIGNED
        { yyinfo("type-specifier -> signed"); }
    | UNSIGNED
        { yyinfo("type-specifier -> unsigned"); }
    | BOOL
        { yyinfo("type-specifier -> _Bool"); }
    | COMPLEX
        { yyinfo("type-specifier -> _Complex"); }
    | IMAGINARY
        { yyinfo("type-specifier -> _Imaginary"); }
    | enum_specifier
        { yyinfo("type-specifier -> enum-specifier"); }
    ;    

specifier_qualifier_list_opt:
    specifier_qualifier_list
        { yyinfo("specifier-qualifier-list_opt -> specifier-qualifier-list"); }
    |
        { yyinfo("specifier-qualifier-list_opt -> epsilon"); }
    ;

specifier_qualifier_list:
    type_specifier specifier_qualifier_list_opt
        { yyinfo("specifier-qualifier-list -> type-specifier specifier-qualifier-list_opt"); }
    | type_qualifier specifier_qualifier_list_opt
        { yyinfo("specifier-qualifier-list -> type-qualifier specifier-qualifier-list_opt"); }
    ;

identifier_opt:
    IDENTIFIER  
        { 
            yyinfo("identifier-opt -> identifier");
            printf("IDENTIFIER = %s\n", $1);  
        }
    |
        { yyinfo("identifier-opt -> epsilon"); }
    ;

enum_specifier:
    ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list CURLY_BRACE_CLOSE
        { yyinfo("enum-specifier -> enum-identifier_opt { enumerator_list }"); }
    | ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list COMMA CURLY_BRACE_CLOSE
        { yyinfo("enum-specifier -> enum-identifier_opt { enumerator_list , }"); }
    | ENUM IDENTIFIER
        { 
            yyinfo("enum-specifier -> enum-identifier"); 
            printf("IDENTIFIER = %s\n", $2); 
        }
    ;

enumerator_list:
    enumerator
        { yyinfo("enumerator-list -> enumerator"); }
    | enumerator_list COMMA enumerator
        { yyinfo("enumerator-list -> enumerator-list , enumerator"); }
    ;

enumerator:
    IDENTIFIER
        { 
            yyinfo("enumerator -> enumeration-constant"); 
            printf("IDENTIFIER = %s\n", $1);
        }
    | IDENTIFIER EQ constant_expression
        { 
            yyinfo("enumerator -> enumeration-constant = constant expression");
            printf("IDENTIFIER = %s\n", $1);
        }
    ;

type_qualifier:
    CONST
        { yyinfo("type-qualifier -> const"); }
    | RESTRICT
        { yyinfo("type-qualifier -> restrict"); }
    | VOLATILE
        { yyinfo("type-qualifier -> volatile"); }
    ;

function_specifier:
    INLINE
        { yyinfo("function-specifier -> inline"); }
    ;

pointer_opt:
    pointer
        { yyinfo("pointer-opt -> pointer"); }
    |
        { yyinfo("pointer-opt -> epsilon"); }
    ;

declarator:
    pointer_opt direct_declarator
        { yyinfo("declarator -> pointer-opt direct-declarator"); }
    ;

assignment_expression_opt:
    assignment_expression
        { yyinfo("assignment-expression_opt -> assignment-expression"); }
    |
        { yyinfo("assignment-expression_opt -> epsilon"); }
    ;


identifier_list_opt:
    identifier_list
        { yyinfo("identifier-list_opt -> identifier-list"); }
    | 
        { yyinfo("identifier-list_opt -> epsilon"); }
    ;

direct_declarator:
    IDENTIFIER
        { 
            yyinfo("direct-declarator -> identifier"); 
            printf("IDENTIFIER = %s\n", $1);
        }
    | PARENTHESIS_OPEN declarator PARENTHESIS_CLOSE
        { yyinfo("direct-declarator -> (declarator)"); }
    | direct_declarator SQR_BRACE_OPEN type_qualifier_list_opt assignment_expression_opt SQR_BRACE_CLOSE
        { yyinfo("direct-declarator -> direct-declarator [type-qualifier-list_opt assignment-expression_opt]"); }
    | direct_declarator SQR_BRACE_OPEN STATIC type_qualifier_list_opt assignment_expression SQR_BRACE_CLOSE
        { yyinfo("direct-declarator -> direct-declarator [static type-qualifier-list_opt assignment-expression]"); }
    | direct_declarator SQR_BRACE_OPEN type_qualifier_list STATIC assignment_expression SQR_BRACE_CLOSE
        { yyinfo("direct-declarator -> direct-declarator [type-qualifier-list_opt static assignment-expression]"); }
    | direct_declarator SQR_BRACE_OPEN type_qualifier_list_opt STAR SQR_BRACE_CLOSE
        { yyinfo("direct-declarator -> direct-declarator [type-qualifier-list_opt *]"); }
    | direct_declarator PARENTHESIS_OPEN parameter_type_list PARENTHESIS_CLOSE
        { yyinfo("direct-declarator -> direct-declarator (parameter-type-list)"); }
    | direct_declarator PARENTHESIS_OPEN identifier_list_opt PARENTHESIS_CLOSE
        { yyinfo("direct-declarator -> direct-declarator (identifier-list_opt)"); }
    ;

pointer:
    STAR type_qualifier_list_opt
        { yyinfo("pointer -> * type-qualifier-list_opt"); }
    | STAR type_qualifier_list_opt pointer
        { yyinfo("pointer -> * type-qualifier-list_opt pointer"); }
    ;

type_qualifier_list:
    type_qualifier
        { yyinfo("type-qualifier-list -> type-qualifier"); }
    | type_qualifier_list type_qualifier
        { yyinfo("type-qualifier-list -> type-qualifier-list type-qualifier"); }
    ;

type_qualifier_list_opt:
    type_qualifier_list
        { yyinfo("type-qualifier-list_opt -> type-qualifier-list"); }
    | 
        { yyinfo("type-qualifier-list_opt -> epsilon"); }
    ;

parameter_type_list:
    parameter_list
        { yyinfo("parameter-type-list -> parameter-list"); }
    | parameter_list COMMA ELLIPSIS
        { yyinfo("parameter-type-list -> parameter-list , ..."); }
    ;

parameter_list:
    parameter_declaration
        { yyinfo("parameter-list -> parameter-declaration"); }
    | parameter_list COMMA parameter_declaration
        { yyinfo("parameter-list -> parameter-list , parameter-declaration"); }
    ;

parameter_declaration:
    declaration_specifiers declarator
        { yyinfo("parameter-declaration -> declaration-specifiers declarator"); }
    | declaration_specifiers
        { yyinfo("parameter-declaration -> declaration-specifiers"); }
    ;

identifier_list:
    IDENTIFIER
        { 
            yyinfo("identifier-list -> identifier"); 
            printf("IDENTIFIER = %s\n", $1);
        }
    | identifier_list COMMA IDENTIFIER
        { 
            yyinfo("identifier-list -> identifier-list , IDENTIFIER");
            printf("IDENTIFIER = %s\n", $3);
        }
    ;

type_name:
    specifier_qualifier_list
        { yyinfo("type-name -> specifier-qualifier-list"); }
    ;

initializer:
    assignment_expression
        { yyinfo("initializer -> assignment-expression"); }
    | CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
        { yyinfo("initializer -> {initializer-list}"); }
    | CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
        { yyinfo("initializer -> {initializer-list , }"); }
    ;

initializer_list:
    designation_opt initializer
        { yyinfo("initializer-list -> designation_opt initializer"); }
    | initializer_list COMMA designation_opt initializer
        { yyinfo("initializer-list -> initializer-list , designation_opt initializer"); }
    ;

designation_opt:
    designation
        { yyinfo("designation-opt -> designation"); }
    | 
        { yyinfo("designation-opt -> epsilon"); }
    ;

designation:
    designator_list EQ
        { yyinfo("designation -> designator-list ="); }
    ;

designator_list:
    designator
        { yyinfo("designator-list -> designator"); }
    | designator_list designator
        { yyinfo("designator-list -> designator-list designator"); }
    ;

designator:
    SQR_BRACE_OPEN constant_expression SQR_BRACE_CLOSE
        { yyinfo("designator -> [constant-expression]"); }
    | DOT IDENTIFIER
        { 
            yyinfo("designator -> .identifier");
            printf("IDENTIFIER = %s\n", $2);    
        }
    ;

// Statements

statement:
    labeled_statement
        { yyinfo("statement -> labeled-statement"); }
    | compound_statement
        { yyinfo("statement -> compound-statement"); }
    | expression_statement
        { yyinfo("statement -> expression-statement"); }
    | selection_statement
        { yyinfo("statement -> selection-statement"); }
    | iteration_statement
        { yyinfo("statement -> iteration-statement"); }
    | jump_statement
        { yyinfo("statement -> jump-statement"); }
    ;

labeled_statement:
    IDENTIFIER COLON statement
        { 
            yyinfo("labeled-statement -> identifier : statement");
            printf("IDENTIFIER = %s\n", $1); 
        }
    | CASE constant_expression COLON statement
        { yyinfo("labeled-statement -> case constant-expression : statement"); }
    | DEFAULT COLON statement
        { yyinfo("labeled-statement -> default : statement"); }
    ;

compound_statement:
    CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE
        { yyinfo("compound-statement -> {block-item-list_opt}"); }
    ;

block_item_list:
    block_item
        { yyinfo("block-item-list -> block-item"); }
    | block_item_list block_item
        { yyinfo("block-item-list -> block-item-list block-item"); }
    ;

block_item_list_opt:
    block_item_list
        { yyinfo("block-item-list_opt -> block-item-list"); }
    | 
        { yyinfo("block-item-list_opt -> epsilon"); }
    ;

block_item:
    declaration
        { yyinfo("block-item -> declaration"); }
    | statement
        { yyinfo("block-item -> statement"); }
    ;

expression_statement:
    expression_opt SEMI_COLON
        { yyinfo("expression-statement -> expression_opt ;"); }
    ;

selection_statement:
    IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
        { yyinfo("selection-statement -> if (expression) statement"); }
    | IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement ELSE statement
        { yyinfo("selection-statement -> if (expression) statement else statement"); }
    | SWITCH PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
        { yyinfo("selection-statement -> switch (expression) statement"); }
    ;

iteration_statement:
    WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
        { yyinfo("iteration-statement -> while ( expression ) statement"); }
    | DO statement WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE SEMI_COLON
        { yyinfo("iteration-statement -> do statement while ( expression ) ;"); }
    | FOR PARENTHESIS_OPEN expression_opt SEMI_COLON expression_opt SEMI_COLON expression_opt PARENTHESIS_CLOSE statement
        { yyinfo("iteration-statement -> for ( expression_opt ; expression_opt ; expression_opt ) statement"); }
    | FOR PARENTHESIS_OPEN declaration expression_opt SEMI_COLON expression_opt PARENTHESIS_CLOSE statement
        { yyinfo("iteration-statement -> for ( declaration expression_opt ; expression_opt ) statement"); }
    ;

jump_statement:
    GOTO IDENTIFIER SEMI_COLON
        {
            yyinfo("jump-statement -> goto identifier;"); 
            printf("IDENTIFIER = %s\n", $2);
        }
    | CONTINUE SEMI_COLON
        { yyinfo("jump-statement -> continue;"); }
    | BREAK SEMI_COLON
        { yyinfo("jump-statement -> break;"); }
    | RETURN expression_opt SEMI_COLON
        { yyinfo("jump-statement -> return expression_opt;"); }
    ;

// External definitions

translation_unit:
    external_declaration
        { yyinfo("translation-unit -> external-declaration"); }
    | translation_unit external_declaration
        { yyinfo("translation-unit -> translation-unit external-declaration"); }
    ;

external_declaration:
    function_definition
        { yyinfo("external-declaration -> function-definition"); }
    | declaration
        { yyinfo("external-declaration -> declaration"); }
    ;

function_definition:
    declaration_specifiers declarator declaration_list_opt compound_statement
        { yyinfo("function-definition -> declaration-specifiers declarator declaration-list_opt compound-statement"); }
    ;

declaration_list_opt:
    declaration_list
        { yyinfo("declaration-list-opt -> declaration-list"); }
    | 
        { yyinfo("declaration-list-opt -> epsilon"); }
    ;

declaration_list:
    declaration
        { yyinfo("declaration-list -> declaration"); }
    | declaration_list declaration
        { yyinfo("declaration-list -> declaratio-list declaration"); }
    ;

%%

void yyerror(char* s) {
    printf("\nError occured at < Line %d > : %s, Parsing Failed : %s\n\n", yylineno, s, yytext);
}

void yyinfo(char* s) {
    printf("INFO < Line %d > : %s\n", yylineno, s);
}