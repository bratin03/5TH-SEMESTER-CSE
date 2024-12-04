/*
Assignment Number 6

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

/*Declarations*/
%{
    // This is the beginning of the declarations section.
    // It includes some C++ standard libraries and header files.
    #include <bits/stdc++.h>
    #include <sstream>
    using namespace std;  // Using the standard C++ namespace.
    #include "ass6_21CS10016_21CS30050_translator.h"
    extern int yylex();  // Declaration of an external function yylex.
    void yyerror(string s);  // Declaration of a function yyerror.
    extern string variable_type;  // Declaration of an external string variable.
    extern vector<label> label_store;  // Declaration of an external vector.
    extern int lineno;  // Declaration of an external integer variable.
    extern vector<string> stringsToBePrinted;
    extern vector<string> floatsToBePrinted;
%}

%union {
    int iVal;        // integer value
    char* cVal;     // char value
    float fVal;    // float value
    char unaryOp;       // This union defines different types of tokens with associated data types.
    int param_no;     // number of parameters
    int instruction_no;   // instruction number: for backpatching
    symboltype* symbol_type;   // symbol type
    sym* sym_ptr;          // sym_ptr
    Expression* expr;   // Expression
    Statement* stat;    // Statement
    Array* A;           // Array type
}


%token BREAK RETURN CASE FOR WHILE GOTO SIZEOF CONTINUE IF DO SWITCH ELSE FLOAT SHORT CHAR BOOL IMAGINARY COMPLEX INT DOUBLE LONG VOID SIGNED AUTO UNSIGNED  ENUM UNION STRUCT TYPEDEF  CONST DEFAULT STATIC REGISTER RESTRICT VOLATILE EXTERN INLINE  SQR_BRACE_OPEN SQR_BRACE_CLOSE PARENTHESIS_OPEN PARENTHESIS_CLOSE CURLY_BRACE_OPEN CURLY_BRACE_CLOSE DOT QUESTION_MARK COLON SEMI_COLON COMMA HASH PLUS MINUS STAR DIVIDE PTR_OP INC_OP DEC_OP RIGHT_OP LEFT_OP LESS_THAN GREATER_THAN LTE_OP GTE_OP EQ_OP NE_OP BITWISEOR OR_OP BITWISEAND AND_OP BITWISEXOR NOT EXCLAMATION ELLIPSIS PERCENTAGE EQ ENUMERATION_CONST ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN 

// These are token definitions with associated data types.
%token <sym_ptr> IDENTIFIER
%token <iVal> INTEGER_CONSTANT
%token <cVal> CHARACTER_CONSTANT
%token <fVal> FLOATING_CONSTANT
%token <cVal> STRING_LITERAL

// This is the starting point of the grammar.
%start translation_unit

%right "then" ELSE  // Right-associative operator and ELSE token.

//unary operator
%type <unaryOp> unary_operator

//number of parameters
%type <param_no> argument_expression_list argument_expression_list_opt

//For Backpatching
%type <instruction_no> M

//symbol type
%type <symbol_type> pointer

//symbol
%type <sym_ptr> initializer
%type <sym_ptr> direct_declarator init_declarator declarator

//Expressions
%type <expr> expression constant primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression expression_statement

//Statements
%type <stat> statement compound_statement loop_statement selection_statement iteration_statement labeled_statement  jump_statement block_item block_item_list block_item_list_opt

//arrays
%type <A> postfix_expression unary_expression cast_expression

//Auxiliary non-terminals M and N

%type <stat> N

/*Rules*/
%%

constant:
    INTEGER_CONSTANT 
    { 
        // This rule defines how to handle integer constants.
        $$ = new Expression();  // Create a new Expression instance.
        string temp = INT2STRING($1);  // Convert the constant to a string.
        $$->loc = gentemp(new symboltype("int"), temp);  // Create a temporary variable.
        Q.emit("=", $$->loc->name, temp);  // Emit an assignment in the intermediate code.
    }
    | FLOATING_CONSTANT
    {                                                                         
        // This rule defines how to handle floating-point constants.
        $$ = new Expression();  // Create a new Expression instance.
        string temp = FLT2STRING($1);  // Convert the constant to a string.
        $$->loc = gentemp(new symboltype("float"), temp);  // Create a temporary variable.
        //Q.emit("=", $$->loc->name, temp);  // Emit an assignment in the intermediate code.
        Q.emit("equalfloat", $$->loc->name, to_string(floatsToBePrinted.size()));  
        floatsToBePrinted.push_back(temp);
          
    }
    | CHARACTER_CONSTANT
    {                                                                        
        // This rule defines how to handle character constants.
        $$ = new Expression();  // Create a new Expression instance.
        $$->loc = gentemp(new symboltype("char"), $1);  // Create a temporary variable.
        Q.emit("equalchar",$$->loc->name,string($1));
    }
    ;

primary_expression:
    IDENTIFIER
    {
        // This rule handles an identifier as a primary expression.
        // Create a new Expression instance and assign it to the result ($$).
        $$ = new Expression();
        // Store the identifier in the expression's 'loc' field.
        $$->loc = $1;
        // Mark the type as "not-boolean" for the primary expression.
        $$->type = "not-boolean";
    }
    | constant
    {
        // This case handles a constant as a primary expression.
        // Assign the constant to the result ($$).
        $$ = $1;
    }
    | STRING_LITERAL
    {
        // Create a new Expression object and a symboltype for a pointer
        $$ = new Expression();
        symboltype* temp = new symboltype("ptr");
        
        // Set the location of the new Expression to the generated temporary symbol
        $$->loc = gentemp(temp, $1);
        
        // Set the array type of the temporary symbol to "char"
        $$->loc->type->arrtype = new symboltype("char");

        // Emit a "equalstr" quadruple with the temporary symbol's name and the count of stringsToBePrinted
        Q.emit("equalstr", $$->loc->name, to_string(stringsToBePrinted.size()));          

        // Add the parsed STRING_LITERAL to the stringsToBePrinted vector
        stringsToBePrinted.push_back($1);
    }
    | PARENTHESIS_OPEN expression PARENTHESIS_CLOSE
    {                                                                        
        $$=$2;
    }
    ;


postfix_expression:
    primary_expression
    {
        // This rule deals with a primary expression in postfix.
        // Create a new Array instance and assign it to the result ($$).
        $$ = new Array();
        // Assign the primary expression's 'loc' to the Array's 'Array' field.
        $$->Array = $1->loc;
        // Copy the type of the primary expression to the Array's type.
        $$->type = $1->loc->type;
        // Set the location of the Array to the primary expression.
        $$->loc = $$->Array;
    }
    | postfix_expression SQR_BRACE_OPEN expression SQR_BRACE_CLOSE
    {
        // This rule handles postfix expressions with square brackets (arrays).
        // Create a new Array instance and assign it to the result ($$).
        $$ = new Array();
        // Set the type of the Array to the array type of the previous expression.
        $$->type = $1->type->arrtype;
        // Copy the 'Array' field from the previous expression to the new Array.
        $$->Array = $1->Array;
        // Generate a temporary location for the Array's location.
        $$->loc = gentemp(new symboltype("int"));
        // Set the Array type as 'arr'.
        $$->atype = "arr";

        // Recursive definition for arrays is crucial.
        if ($1->atype == "arr") {
            // Generate a temporary symbol for array size computation.
            sym* t = gentemp(new symboltype("int"));
            // Compute the size of the array type.
            int temp = computeSize($$->type);
            string str = INT2STRING(temp);
            // Emit code to multiply and add for array indexing.
            Q.emit("*", t->name, $3->loc->name, str);
            Q.emit("+", $$->loc->name, $1->loc->name, t->name);
        }
        else {
            // Compute the size of the array type.
            int temp = computeSize($$->type);
            string str = INT2STRING(temp);
            // Emit code to multiply for array indexing.
            Q.emit("*", $$->loc->name, $3->loc->name, str);
        }
    }
    | postfix_expression PARENTHESIS_OPEN argument_expression_list_opt PARENTHESIS_CLOSE
    {
        // This handles function calls with a variable number of arguments.
        // Create a new Array instance and assign it to the result ($$).
        $$ = new Array();
        // Generate a temporary location for the Array.
        $$->Array = gentemp($1->type);
        // Convert the number of arguments to a string.
        string str = INT2STRING($3);
        // Emit a function call with the arguments.
        Q.emit("call", $$->Array->name, $1->Array->name, str);
    }
    | postfix_expression DOT IDENTIFIER
    {
        // Handle the dot operator with an identifier (struct member access).
        // No action needed.
    }
    | postfix_expression PTR_OP IDENTIFIER
    {
        // Handle the pointer operator with an identifier (member access via pointer).
        // No action needed.
    }
    | postfix_expression INC_OP
    {
        // This handles the increment operator '++'.
        // Create a new Array instance and assign it to the result ($$).
        $$ = new Array();
        // Generate a temporary location for the Array.
        $$->Array = gentemp($1->Array->type);
        // Emit code to copy the previous expression to the result.
        Q.emit("=", $$->Array->name, $1->Array->name);
        // Emit code to increment the previous expression by 1.
        Q.emit("+", $1->Array->name, $1->Array->name, "1");
    }
    | postfix_expression DEC_OP
    {
        // This handles the decrement operator '--'.
        // Create a new Array instance and assign it to the result ($$).
        $$ = new Array();
        // Generate a temporary location for the Array.
        $$->Array = gentemp($1->Array->type);
        // Emit code to copy the previous expression to the result.
        Q.emit("=", $$->Array->name, $1->Array->name);
        // Emit code to decrement the previous expression by 1.
        Q.emit("-", $1->Array->name, $1->Array->name, "1");
    }
    | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
    {
        // Handle a cast expression with an initializer.
        // No action needed.
    }
    | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
    {
        // Handle a cast expression with an initializer list.
        // No action needed.
    }
    ;  

argument_expression_list:
    assignment_expression
    {
        // This rule handles a single assignment expression.
        $$ = 1; // Simple assignment
        // Emit code to pass the assignment expression as a parameter.
        Q.emit("param", $1->loc->name);
    }
    | argument_expression_list COMMA assignment_expression
    {
        // This handles a list of argument expressions separated by commas.
        $$ = $1 + 1; // Increment the argument count.
        // Emit code to pass the assignment expression as a parameter.
        Q.emit("param", $3->loc->name);
    }
    ;

argument_expression_list_opt:
    argument_expression_list
    {
        // This rule represents a non-empty argument expression list.
        $$ = $1; // Simple assignment
    }
    | %empty
    {
        // This rule represents an empty argument expression list.
        $$ = 0; // Defaults to 0 arguments.
    }
    ;

unary_expression:
    postfix_expression
    {
        // This rule represents a unary expression with a postfix expression.
        $$ = $1; // Assign the result to the postfix expression.
    }
    | INC_OP unary_expression
    {
        // This handles the increment operator '++' as a unary expression.
        // Emit code to increment the operand by 1.
        Q.emit("+", $2->Array->name, $2->Array->name, "1");
        $$ = $2;
    }
    | DEC_OP unary_expression
    {
        // This handles the decrement operator '--' as a unary expression.
        // Emit code to decrement the operand by 1.
        Q.emit("-", $2->Array->name, $2->Array->name, "1");
        $$ = $2;
    }
    | unary_operator cast_expression
    {
        // This rule handles unary operators applied to a cast expression.
        $$ = new Array();
        // Perform different actions based on the unary operator type.
        switch ($1) {
            case '&':
                // Handle the address-of operator '&'.
                $$->Array = gentemp(new symboltype("ptr"));
                $$->Array->type->arrtype = $2->Array->type;
                // Emit code to take the address of the operand.
                Q.emit("=&", $$->Array->name, $2->Array->name);
                break;
            case '*':
                // Handle the dereferencing operator '*'.
                $$->atype = "ptr";
                $$->loc = gentemp($2->Array->type->arrtype);
                $$->Array = $2->Array;
                // Emit code to dereference the pointer.
                Q.emit("=*", $$->loc->name, $2->Array->name);
                break;
            case '+':
                // Handle the unary plus operator '+', which doesn't change the operand.
                $$ = $2;
                break;
            case '-':
                // Handle the unary minus operator '-', which negates the operand.
                $$->Array = gentemp(new symboltype($2->Array->type->type));
                // Emit code to negate the operand.
                Q.emit("uminus", $$->Array->name, $2->Array->name);
                break;
            case '~':
                // Handle the bitwise NOT operator '~'.
                $$->Array = gentemp(new symboltype($2->Array->type->type));
                // Emit code to perform bitwise NOT on the operand.
                Q.emit("~", $$->Array->name, $2->Array->name);
                break;
            case '!':
                // Handle the logical NOT operator '!', which negates the operand.
                $$->Array = gentemp(new symboltype($2->Array->type->type));
                // Emit code to perform logical NOT on the operand.
                Q.emit("!", $$->Array->name, $2->Array->name);
                break;
        }
    }
    | SIZEOF unary_expression
    {
        // Handle the sizeof operator applied to an expression.
        // No action needed.
    }
    | SIZEOF PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE
    {
        // Handle the sizeof operator applied to a type name.
        // No action needed.
    }
    ;  


unary_operator:
    BITWISEAND
    { 
        // This rule represents the bitwise AND operator '&' in unary expressions.
        $$ = '&'; 
    }
    | STAR
    { 
        // This rule represents the pointer dereference operator '*' in unary expressions.
        $$ = '*'; 
    }
    | PLUS
    { 
        // This rule represents the unary plus operator '+' in unary expressions.
        $$ = '+'; 
    }
    | MINUS
    { 
        // This rule represents the unary minus operator '-' in unary expressions.
        $$ = '-'; 
    }
    | NOT
    { 
        // This rule represents the bitwise NOT operator '~' in unary expressions.
        $$ = '~'; 
    }
    | EXCLAMATION
    { 
        // This rule represents the logical NOT operator '!' in unary expressions.
        $$ = '!'; 
    }
    ;

cast_expression:
    unary_expression
    { 
        // This rule handles a cast expression with a unary expression.
        $$ = $1; 
    }
    | PARENTHESIS_OPEN type_name PARENTHESIS_CLOSE cast_expression
    { 
        // This rule handles a cast expression with a type name and a cast expression.
        $$ = new Array();
        // Convert and assign the type of the cast expression.
        $$->Array = convertType($4->Array, variable_type);
    }
    ;

multiplicative_expression:
    cast_expression
    {
        // This rule handles multiplicative expressions starting with a cast expression.
        $$ = new Expression();
        // Handle casting by checking types and performing necessary conversions.
        if ($1->atype == "arr") {
            $$->loc = gentemp($1->loc->type);	
            Q.emit("=[]", $$->loc->name, $1->Array->name, $1->loc->name);     
        }
        else if ($1->atype == "ptr") { 
            $$->loc = $1->loc;        
        }
        else {
            $$->loc = $1->Array;
        }
    }
    | multiplicative_expression STAR cast_expression
    { 
        // This rule handles multiplication in multiplicative expressions.
        if (!compareSymbolType($1->loc, $3->Array)) {
            // Types are not the same; report a type error.
            yyerror("Error! Type not matched");
            return 1;
        }
        else {
            // Perform the multiplication operation.
            $$ = new Expression();	
            $$->loc = gentemp(new symboltype($1->loc->type->type));
            Q.emit("*", $$->loc->name, $1->loc->name, $3->Array->name);
        }
    }
    | multiplicative_expression DIVIDE cast_expression
    {
        // This rule handles division in multiplicative expressions.
        if (!compareSymbolType($1->loc, $3->Array)) {
            // Types are not the same; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {
            // Perform the division operation.
            $$ = new Expression();
            $$->loc = gentemp(new symboltype($1->loc->type->type));
            Q.emit("/", $$->loc->name, $1->loc->name, $3->Array->name);
        }
    }
    | multiplicative_expression PERCENTAGE cast_expression     
    {
        // This rule handles the modulo operation in multiplicative expressions.
        if (!compareSymbolType($1->loc, $3->Array)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;		
        }
        else {
            // Perform the modulo operation.
            $$ = new Expression();
            $$->loc = gentemp(new symboltype($1->loc->type->type));
            Q.emit("%", $$->loc->name, $1->loc->name, $3->Array->name);	
        }
    }
    ;


additive_expression:        
    multiplicative_expression
    { 
        // This rule handles additive expressions starting with a multiplicative expression.
        $$ = $1;
    }
    | additive_expression PLUS multiplicative_expression
    {
        // This rule handles addition in additive expressions.
        if (!compareSymbolType($1->loc, $3->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {
            // Continue with the addition operation.
            $$ = new Expression();	
            $$->loc = gentemp(new symboltype($1->loc->type->type));
            Q.emit("+", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    | additive_expression MINUS multiplicative_expression
    {
        // This rule handles subtraction in additive expressions.
        if (!compareSymbolType($1->loc, $3->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;		
        }
        else {	
            $$ = new Expression();	
            $$->loc = gentemp(new symboltype($1->loc->type->type));
            Q.emit("-", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    ;


shift_expression:
    additive_expression
    { 
        // This rule handles shift expressions starting with an additive expression.
        $$ = $1;
    }
    | shift_expression LEFT_OP additive_expression
    { 
        // This rule handles left shift in shift expressions.
        if (!($3->loc->type->type == "int")) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl; 		
        }
        else {		
            $$ = new Expression();		
            $$->loc = gentemp(new symboltype("int"));
            Q.emit("<<", $$->loc->name, $1->loc->name, $3->loc->name);		
        }
    }
    | shift_expression RIGHT_OP additive_expression
    { 	
        // This rule handles right shift in shift expressions.
        if (!($3->loc->type->type == "int")) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl; 		
        }
        else {			
            $$ = new Expression();	
            $$->loc = gentemp(new symboltype("int"));
            Q.emit(">>", $$->loc->name, $1->loc->name, $3->loc->name);			
        }
    }
    ;

relational_expression:
    shift_expression
    { 
        // This rule handles relational expressions starting with a shift expression.
        $$ = $1;
    }
    | relational_expression LESS_THAN shift_expression
    {
        // This rule handles the less than operator in relational expressions.
        if (!compareSymbolType($1->loc, $3->loc)) {
            // Incompatible types; report a type error.
            yyerror("Error! Type not matched");
        }
        else {      
            $$ = new Expression();
            $$->type = "bool";
            // Need to update truelist and falselist since the type is boolean.
            $$->truelist = makelist(nextinstr());     
            $$->falselist = makelist(nextinstr() + 1);
            Q.emit("<", "", $1->loc->name, $3->loc->name);     
            Q.emit("goto", "");	
        }
    }
    | relational_expression GREATER_THAN shift_expression
    {
        // This rule handles the greater than operator in relational expressions.
        if (!compareSymbolType($1->loc, $3->loc)) {
            // Incompatible types; report a type error.
            yyerror("Error! Type not matched");
        }
        else {	
            $$ = new Expression();		
            $$->type = "bool";
            // Need to update truelist and falselist since the type is boolean.
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr() + 1);
            Q.emit(">", "", $1->loc->name, $3->loc->name);
            Q.emit("goto", "");
        }	
    }
    | relational_expression LTE_OP shift_expression
    {
        // This rule handles the less than or equal to operator in relational expressions.
        if (!compareSymbolType($1->loc, $3->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {			
            $$ = new Expression();		
            $$->type = "bool";
            // Need to update the attributes for boolean data type.
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr() + 1);
            Q.emit("<=", "", $1->loc->name, $3->loc->name);
            Q.emit("goto", "");
        }		
    }
    | relational_expression GTE_OP shift_expression
    {
        // This rule handles the greater than or equal to operator in relational expressions.
        if (!compareSymbolType($1->loc, $3->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {	
            $$ = new Expression();	
            $$->type = "bool";
            // Need to update the attributes for the boolean data type.
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr() + 1);
            Q.emit(">=", "", $1->loc->name, $3->loc->name);
            Q.emit("goto", "");
        }
    }
    ;

equality_expression:
    relational_expression
    { 
        $$=$1;
    }
    | equality_expression EQ_OP relational_expression
    {
        // Check and assign
        if(!compareSymbolType($1->loc, $3->loc)) {
            cout << "Error! Type not matched"<< endl;
        }
        else {
            // We need to convert here
            BOOL2INT($1);                  
            BOOL2INT($3);

            $$ = new Expression();

            $$->type = "bool";
            $$->truelist = makelist(nextinstr());            
            $$->falselist = makelist(nextinstr()+1); 

            Q.emit("==", "", $1->loc->name, $3->loc->name);      
            Q.emit("goto", "");				
        }
    }
    | equality_expression NE_OP relational_expression
    {
        // Check and assign
        if(!compareSymbolType($1->loc, $3->loc)) {
            cout << "Error! Type not matched"<< endl;
        }
        else {			
            BOOL2INT($1);
            BOOL2INT($3);

            $$ = new Expression();                 

            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);

            Q.emit("!=", "", $1->loc->name, $3->loc->name);
            Q.emit("goto", "");
        }
    }
    ;
and_expression:
    equality_expression
    { 
        $$=$1;
    }
    | and_expression BITWISEAND equality_expression
    {
        // Check and assign
        if(!compareSymbolType($1->loc, $3->loc)){		
            cout << "Error! Type not matched"<< endl;
        }
        else {              
            BOOL2INT($1);                             
            BOOL2INT($3);			

            $$ = new Expression();

            $$->type = "not-boolean";                   
            $$->loc = gentemp(new symboltype("int"));

            Q.emit("&", $$->loc->name, $1->loc->name, $3->loc->name);               
        }
    }
    ;

exclusive_or_expression:
    and_expression
    { 
        $$=$1;
    }
    | exclusive_or_expression BITWISEXOR and_expression
    {
        // Check and assign
        if(!compareSymbolType($1->loc, $3->loc)) {
            cout << "Error! Type not matched"<< endl;
        }
        else {
            BOOL2INT($1);
            BOOL2INT($3);

            $$ = new Expression();

            $$->type = "not-boolean";
            $$->loc = gentemp(new symboltype("int"));

            Q.emit("^", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    ;

inclusive_or_expression:
    exclusive_or_expression
    { 
        $$=$1;
    }
    | inclusive_or_expression BITWISEOR exclusive_or_expression
    { 
        // Check and assign
        if(!compareSymbolType($1->loc, $3->loc)) { 
            yyerror("Error! Type not matched"); 
        }
        else {
            BOOL2INT($1);		
            BOOL2INT($3);

            $$ = new Expression();

            $$->type = "not-boolean";
            $$->loc = gentemp(new symboltype("int"));

            Q.emit("|", $$->loc->name, $1->loc->name, $3->loc->name);
        } 
    }
    ;

logical_and_expression:
    inclusive_or_expression
    { 
        $$=$1;
    }
    | logical_and_expression AND_OP M inclusive_or_expression
    { 
        // Converto to bool before the logical operation
        INT2BOOL($4);                                  
        INT2BOOL($1);                                 

        // Generate new boolean expression
        $$ = new Expression();                               
        $$->type = "bool";
        
        // Do the backpatching and generate the attributes
        backpatch($1->truelist, $3);                        
        $$->truelist = $4->truelist;                       
        $$->falselist = merge($1->falselist, $4->falselist);   
    }
    ;

logical_or_expression:
    logical_and_expression
    { 
        $$=$1;
    }
    | logical_or_expression OR_OP M logical_and_expression
    { 
        // Convert to bool before the logical operation
        INT2BOOL($4);			 
        INT2BOOL($1);			

        $$ = new Expression();	
        $$->type = "bool";

        // As per requirement
        backpatch($1->falselist, $3);		
        $$->truelist = merge($1->truelist, $4->truelist);		
        $$->falselist = $4->falselist;		 	
    }
    ;

conditional_expression:
    logical_or_expression
    { $$=$1;/* Simple assign */ }
    | logical_or_expression QUESTION_MARK expression COLON conditional_expression
    {
        //normal conversion method to get conditional expressions
        $$->loc = gentemp($3->loc->type);       //generate temporary for expression
        $$->loc->update($3->loc->type);
        
        backpatch($1->truelist, nextinstr());           // $1 true goes to expression
        Q.emit("=", $$->loc->name, $3->loc->name);      // make it equal to first expression
        list<int> temp = makelist(nextinstr());            //makelist next instruction
        Q.emit("goto", "");                             //prevent fallthrough

        backpatch($1->falselist, nextinstr());          // $1 false goes to conditional expression
        Q.emit("=", $$->loc->name, $5->loc->name);      // Second Expression

        backpatch(temp, nextinstr());                      // fallthrough, go to next instruction
    }
    ;

assignment_expression:
    conditional_expression
    { $$=$1;/* Simple assign */ }
    | unary_expression assignment_operator assignment_expression
    {
        if($1->atype=="arr")                                            // if type is arr, Check and convert then Q.emit as []=
        {
            $3->loc = convertType($3->loc, $1->type->type);
            Q.emit("[]=", $1->Array->name, $1->loc->name, $3->loc->name);		
        }
        else if($1->atype=="ptr")                                       // if type is ptr, simply Q.emit as *=
        {
            Q.emit("*=", $1->Array->name, $3->loc->name);	
        }
        else                                                            // otherwise simple assignment
        {
            $3->loc = convertType($3->loc, $1->Array->type->type);
            Q.emit("=", $1->Array->name, $3->loc->name);
        }
        
        $$ = $3;
    }
    ;


assignment_operator: 
    EQ
    { /*No action needed*/ }
    | MUL_ASSIGN
    { /*No action needed*/ }
    | DIV_ASSIGN
    { /*No action needed*/ }
    | MOD_ASSIGN
    { /*No action needed*/ }
    | ADD_ASSIGN
    { /*No action needed*/ }
    | SUB_ASSIGN
    { /*No action needed*/ }
    | LEFT_ASSIGN
    { /*No action needed*/ }
    | RIGHT_ASSIGN
    { /*No action needed*/ }
    | AND_ASSIGN
    { /*No action needed*/ }
    | XOR_ASSIGN
    { /*No action needed*/ }
    | OR_ASSIGN
    { /*No action needed*/ }
                    ;

expression:
    assignment_expression
    { $$ = $1; }
    | expression COMMA assignment_expression
    { /*No action needed*/ }
    ;

constant_expression:
    conditional_expression
    { /*No action needed*/ }
    ;

declaration:
    declaration_specifiers init_declarator_list_opt SEMI_COLON
    { /*No action needed*/ }
    ;

init_declarator_list_opt:
    init_declarator_list { /*No action needed*/ }
    | %empty{ /*No action needed*/ }
    ;

declaration_specifiers:
    storage_class_specifier declaration_specifiers_opt
    { /*No action needed*/ }
    | type_specifier declaration_specifiers_opt
    { /*No action needed*/ }
    | type_qualifier declaration_specifiers_opt
    { /*No action needed*/ }
    | function_specifier declaration_specifiers_opt
    { /*No action needed*/ }
    ;

declaration_specifiers_opt:
    declaration_specifiers { /*No action needed*/ }
    | %empty { /*No action needed*/ }
    ;

init_declarator_list:
    init_declarator
    { /*No action needed*/ }
    | init_declarator_list COMMA init_declarator
    { /*No action needed*/ }
    ;

init_declarator:
    declarator
    { 
        $$ = $1;                            // Simple Assign 
    }
    | declarator EQ initializer
    {
        if($3->val != ""){
            $1->val=$3->val;                // get the initial value
        }
        Q.emit("=", $1->name, $3->name);	// emit that initial value with Assign operator
    }
    ;

storage_class_specifier:
    EXTERN
    { /*No action needed*/ }
    | STATIC
    { /*No action needed*/ }
    | AUTO
    { /*No action needed*/ }
    | REGISTER
    { /*No action needed*/ }
    ;

type_specifier:
    VOID
    { variable_type="void"; /* Store the latest var type */ lookupInsideParent = false;}
    | CHAR
    { variable_type="char"; /* Store the latest var type */ lookupInsideParent = false;}
    | SHORT
    { /*No action needed*/ }
    | INT
    { variable_type="int"; /* Store the latest var type */ lookupInsideParent = false;}
    | LONG
    { /*No action needed*/ }
    | FLOAT
    { variable_type="float"; /* Store the latest var type */ lookupInsideParent = false;}
    | DOUBLE
    { /*No action needed*/ }
    | SIGNED
    { /*No action needed*/ }
    | UNSIGNED
    { /*No action needed*/ }
    | BOOL
    { /*No action needed*/ }
    | COMPLEX
    { /*No action needed*/ }
    | IMAGINARY
    { /*No action needed*/ }
    | enum_specifier
    { /*No action needed*/ }
    | struct_or_union_specifier
    { /*No action needed*/ }
    ;


specifier_qualifier_list:
    type_specifier specifier_qualifier_list_opt
    { /*No action needed*/ }
    | type_qualifier specifier_qualifier_list_opt
    { /*No action needed*/ }
    ;

specifier_qualifier_list_opt:
    specifier_qualifier_list { /*No action needed*/ }
    | %empty { /*No action needed*/ }
    ;

struct_or_union_specifier:
    struct_or_union CURLY_BRACE_OPEN struct_declaration_list CURLY_BRACE_CLOSE
    { /*No action needed*/ }
    | struct_or_union IDENTIFIER CURLY_BRACE_OPEN struct_declaration_list CURLY_BRACE_CLOSE
    { /*No action needed*/ }
    | struct_or_union IDENTIFIER
    { /*No action needed*/ }
    ;

struct_or_union:
    STRUCT
    { /*No action needed*/ }
    | UNION
    { /*No action needed*/ }
    ;

struct_declaration_list: 
    struct_declaration
    { /*No action needed*/ }
    | struct_declaration_list struct_declaration
    { /*No action needed*/ }
                    ;

struct_declaration:
    specifier_qualifier_list SEMI_COLON
    { /*No action needed*/ }
    | specifier_qualifier_list struct_declarator_list SEMI_COLON
    { /*No action needed*/ }
    ;

struct_declarator_list:
    struct_declarator
    { /*No action needed*/ }
    | struct_declarator_list COMMA struct_declarator
    { /*No action needed*/ }
    ;
struct_declarator:
    COLON constant_expression
    { /*No action needed*/ }
    | declarator COLON constant_expression
    { /*No action needed*/ }
    | declarator
    { /*No action needed*/ }
    ;

enum_specifier:
    ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list CURLY_BRACE_CLOSE
    { /*No action needed*/ }
    | ENUM identifier_opt CURLY_BRACE_OPEN enumerator_list COMMA CURLY_BRACE_CLOSE
    { /*No action needed*/ }
    | ENUM IDENTIFIER
    { /*No action needed*/ }
    ;

identifier_opt:
    IDENTIFIER { /*No action needed*/ }
    | %empty { /*No action needed*/ }
    ;

enumerator_list:
    enumerator
    { /*No action needed*/ }
    | enumerator_list COMMA enumerator
    { /*No action needed*/ }
    ;


enumerator:
    IDENTIFIER
    { /*No action needed*/ }
    | IDENTIFIER EQ constant_expression
    { /*No action needed*/ }
    ;
                

type_qualifier:
    CONST
    { /* NOT to be modelled */ }
    | RESTRICT
    { /*No action needed*/ }
    | VOLATILE
    { /*No action needed*/ }
    ;

function_specifier:
    INLINE
    { /*No action needed*/ }
    ;

declarator:
    pointer direct_declarator 
    {
        symboltype *t = $1;
        while(t->arrtype!=NULL)
        {
            t = t->arrtype;                                         // Recursively get to the base Array
        }   
        t->arrtype = $2->type;                                      // add the base type 
        
        $$ = $2->update($1);                                        // update the symbol type
    }
    | direct_declarator {   }
    ;



direct_declarator:
    IDENTIFIER                 
    {
        // Handle a direct declarator with an IDENTIFIER:
        string nameOfTable = $1->name;
        if (nameOfTable.find(".") != nameOfTable.npos)
            nameOfTable = nameOfTable.substr(0, nameOfTable.find("."));
        curPossibleSTName = nameOfTable;
        $$ = $1->update(new symboltype(variable_type));
        currSymbolPtr = $$;                                                          // store the latest Symbol
    }
    | PARENTHESIS_OPEN declarator PARENTHESIS_CLOSE
    {
        // Handle a declarator enclosed in parentheses:
        $$ = $2;  // Simply assign the result to the current node.
    }                                                     // simply assign
    | direct_declarator SQR_BRACE_OPEN type_qualifier_list assignment_expression SQR_BRACE_CLOSE { /*No action needed*/ 	}
    | direct_declarator SQR_BRACE_OPEN type_qualifier_list SQR_BRACE_CLOSE { /*No action needed*/ 	}
    | direct_declarator SQR_BRACE_OPEN assignment_expression SQR_BRACE_CLOSE 
    {
        // Handle an array with an assignment expression:
        symboltype *t = $1->type;
        symboltype *prev = NULL;

        while (t->type == "arr") 
        {
            prev = t;
            t = t->arrtype;
        }

        if (prev == NULL) 
        {
            symboltype *s = new symboltype("arr", t, stoi($3->loc->val));
            $$ = $1->update(s);
        }
        else 
        {
            prev->arrtype = new symboltype("arr", t, stoi($3->loc->val));
            $$ = $1->update($1->type);
        }
    }
    | direct_declarator SQR_BRACE_OPEN SQR_BRACE_CLOSE
    {
        // Handle an empty array (no size specified):
        symboltype *t = $1->type;
        symboltype *prev = NULL;

        while (t->type == "arr") 
        {
            prev = t;
            t = t->arrtype;
        }

        if (prev == NULL) 
        {
            symboltype *s = new symboltype("arr", t, 0);
            $$ = $1->update(s);
        }
        else 
        {
            prev->arrtype = new symboltype("arr", t, 0);
            $$ = $1->update($1->type);
        }
    }
    | direct_declarator SQR_BRACE_OPEN STATIC type_qualifier_list assignment_expression SQR_BRACE_CLOSE { /*No action needed*/ 	}
    | direct_declarator SQR_BRACE_OPEN STATIC assignment_expression SQR_BRACE_CLOSE { /*No action needed*/ 	}
    | direct_declarator SQR_BRACE_OPEN type_qualifier_list STAR SQR_BRACE_CLOSE { /*No action needed*/ 	}
    | direct_declarator SQR_BRACE_OPEN STAR SQR_BRACE_CLOSE { /*No action needed*/ 	}
    | direct_declarator PARENTHESIS_OPEN FUN_CT parameter_type_list PARENTHESIS_CLOSE 
    {
        // Handle a function declaration:
        string nameOfTable = $1->name;
        if (nameOfTable.find(".") != nameOfTable.npos)
            nameOfTable = nameOfTable.substr(0, nameOfTable.find("."));
        ST->name = nameOfTable;
        $1->name = nameOfTable;
        if ($1->type->type != "void") 
        {
            sym *s = ST->lookup("return");
            s->update($1->type);
        }
        $1->nested = ST;
        $1->category = "function";
        $1->updateFuntionStatus(true);
        listOffunctions.push_back($1);
        ST->parent = globalST;
        changeTable(globalST);
        currSymbolPtr = $$;
    }
    | direct_declarator PARENTHESIS_OPEN identifier_list PARENTHESIS_CLOSE { /*No action needed*/ 	}
    | direct_declarator PARENTHESIS_OPEN FUN_CT PARENTHESIS_CLOSE 
    {
        // Handle a function declaration with no parameters (similar to the previous function declaration).
        // Extract the name of the symbol table from the direct declarator.
        string nameOfTable = $1->name;
        // If the name contains a dot, extract the table name before the dot.
        if (nameOfTable.find(".") != nameOfTable.npos)
            nameOfTable = nameOfTable.substr(0, nameOfTable.find("."));
        // Set the name of the current symbol table to the extracted name.
        ST->name = nameOfTable;
        $1->name = nameOfTable;
        // Check if the function has a return type other than "void."
        if ($1->type->type != "void") {
            // Update the return type in the symbol table.
            sym *s = ST->lookup("return");
            s->update($1->type);
        }
        // Link the nested symbol table.
        $1->nested = ST;        
        // Set the category of $1 as "function."
        $1->category = "function";        
        // Update the function status.
        $1->updateFuntionStatus(true);        
        // Add the function to the list of functions.
        listOffunctions.push_back($1);        
        // Set the parent of the current symbol table to the global symbol table.
        ST->parent = globalST;
        // Change the current symbol table back to the global symbol table.
        changeTable(globalST);
        // Update the current symbol pointer.
        currSymbolPtr = $$;
    }


type_qualifier_list_opt:
    type_qualifier_list { /*No action needed*/ }
    | %empty { /*No action needed*/ }
    ;


pointer:
    STAR type_qualifier_list_opt 
    { 
        $$ = new symboltype("ptr");   //create a new pointer symbol
    }
    | STAR type_qualifier_list_opt pointer
    { 
        $$ = new symboltype("ptr",$3); // create the symboltype with $3 symbol type
    }
    ;

type_qualifier_list:
    type_qualifier
    { /*No action needed*/ }
    | type_qualifier_list type_qualifier
    { /*No action needed*/ }
    ;

parameter_type_list:
    parameter_list
    { /*No action needed*/ }
    | parameter_list COMMA ELLIPSIS
    { /*No action needed*/ }
    ;                       

parameter_list:
    parameter_declaration
    { /*No action needed*/ }
    | parameter_list COMMA parameter_declaration
    { /*No action needed*/ }
    ;


parameter_declaration:
    declaration_specifiers declarator
    {  
        $2->category = "param"; /* Parameter */
    }
    | declaration_specifiers
    { /*No action needed*/ }
    ;

identifier_list:
    IDENTIFIER
    { /*No action needed*/ }
    | identifier_list COMMA IDENTIFIER
    { /*No action needed*/ }
    ;

type_name:
    specifier_qualifier_list
    { /*No action needed*/ }
    ;

initializer:
    assignment_expression
    { $$=$1->loc; /* assignment */  }
    | CURLY_BRACE_OPEN initializer_list CURLY_BRACE_CLOSE
    { /*No action needed*/ }
    | CURLY_BRACE_OPEN initializer_list COMMA CURLY_BRACE_CLOSE
    { /*No action needed*/ }
    ;

initializer_list:
    designation_opt initializer
    { /*No action needed*/ }
    | initializer_list COMMA designation_opt initializer
    { /*No action needed*/ }
    ;

designation_opt:
    designation { /*No action needed*/ }
    | %empty { /*No action needed*/ }
    ;

designation:
    designator_list EQ
    { /*No action needed*/ }
    ;

designator_list:
    designator
    { /*No action needed*/ }
    | designator_list designator
    { /*No action needed*/ }
    ;

designator:
    SQR_BRACE_OPEN constant_expression SQR_BRACE_CLOSE
    { /*No action needed*/ }
    | DOT IDENTIFIER
    { /*No action needed*/ }
    ;

statement:
    labeled_statement
    { /*No action needed*/ }
    | compound_statement
    { $$=$1; }
    | expression_statement
    { 
        $$=new Statement();              //create new statement with same nextlist
        $$->nextlist=$1->nextlist; 
    }
    | selection_statement
    { $$=$1; }
    | iteration_statement
    { $$=$1; }
    | jump_statement
    { $$=$1; }
    ;


loop_statement: 
    labeled_statement   { /*No action needed*/ }
    | expression_statement   
    { 
        $$=new Statement();                         // create new statement with same nextlist
        $$->nextlist=$1->nextlist;                  // assign the nextlist
    }
    | selection_statement   { $$=$1; }
    | iteration_statement   { $$=$1; }
    | jump_statement   { $$=$1; }
    ;
labeled_statement:
    IDENTIFIER COLON M statement
    {
        // Set the result of this production to the result of the 'statement'.
        $$ = $4;

        // Find the label associated with the provided identifier.
        label *s = find_label($1->name);

        if (s != nullptr) {
            // If the label exists, set its address and backpatch its nextlist.
            s->addr = $3;
            backpatch(s->nextlist, s->addr);
        } else {
            // If the label does not exist, create a new label.
            s = new label($1->name);

            // Set the label's address to the next instruction and create a nextlist with $3.
            s->addr = nextinstr();
            s->nextlist = makelist($3);

            // Add the newly created label to the label store.
            label_store.push_back(*s);
        }
    }
    | CASE constant_expression COLON statement
    { /* Not to be modelled */ }
    | DEFAULT COLON statement
    { /*No action needed*/ }
    ;

compound_statement:
    CURLY_BRACE_OPEN X changetable block_item_list_opt CURLY_BRACE_CLOSE
    { 
        // Handle a compound statement.
        $$ = $4; // Compound Statement = blockItemList
        changeTable(ST->parent); // Change Symbol Table
    }
    ;

block_item_list:
    block_item
    { 
        // Handle a block item list with a single block item.
        $$ = $1; /* Simple assign */
    }
    | block_item_list M block_item
    { 
        // Handle a block item list with multiple block items.
        $$ = $3;
        backpatch($1->nextlist, $2); // After $1, move to block_item via $2
    }
    ;

block_item_list_opt:
    block_item_list
    { 
        // Handle a block item list.
        $$ = $1; /* simple assign */
    }
    | %empty 
    { 
        // Handle an empty block item list.
        $$ = new Statement(); /* Create a new statement */
    } 
    ;

block_item:
    declaration
    { 
        // Handle a declaration as a block item.
        $$ = new Statement(); /* Create a new statement */
    } 
    | statement
    { 
        // Handle a statement as a block item.
        $$ = $1; /* Simple assign */
    }
    ;

expression_statement:
    semicolon
    { 
        // Handle an empty expression statement.
        $$ = new Expression(); /* Create a new Expression */
    }
    | expression semicolon
    { 
        // Handle an expression followed by a semicolon.
        $$ = $1; /* Simple assign */
    }
    ;


selection_statement:
    IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE M statement N %prec "then"
    {
        // Handle an 'if' statement without an 'else' part.
        INT2BOOL($3); // Convert the expression to bool.

        $$ = new Statement();
        backpatch($3->truelist, $5); // If true, we access the statement.

        list<int> temp = merge($3->falselist, $6->nextlist);
        $$->nextlist = merge($7->nextlist, temp);
        backpatch($$->nextlist, nextinstr());
    }
    | IF PARENTHESIS_OPEN expression PARENTHESIS_CLOSE M statement N ELSE M statement
    {
        // Handle an 'if' statement with an 'else' part.
        INT2BOOL($3); // Convert the expression to bool.

        $$ = new Statement();
        backpatch($3->truelist, $5); // If true, we access the first part.
        backpatch($3->falselist, $9); // Else, the second part.

        list<int> temp = merge($6->nextlist, $7->nextlist); // Merge with the nextlists of both statements.
        $$->nextlist = merge($10->nextlist, temp);
        backpatch($$->nextlist, nextinstr());
    }
    | SWITCH PARENTHESIS_OPEN expression PARENTHESIS_CLOSE statement
    { 
        // Handle a 'switch' statement (not asked in the question).
    }
    ;


iteration_statement:
    // While loop without a body enclosed in curly braces.
    WHILE W PARENTHESIS_OPEN X changetable M expression PARENTHESIS_CLOSE M loop_statement
    {	
        // Handle a 'while' statement.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($7); // Convert the expression to a boolean.

        // Proper backpatching
        backpatch($10->nextlist, $6); // M1 to go back to the expression again.
        backpatch($7->truelist, $9); // M2 to go to the statement if the expression is true.
        $$->nextlist = $7->falselist; // If the expression is false, exit the loop.

        // Emit a 'goto' to prevent fallthrough.
        string str = INT2STRING($6);		
        Q.emit("goto", str);	
        loop_name = "";
        changeTable(ST->parent);
    }
    | WHILE W PARENTHESIS_OPEN X changetable M expression PARENTHESIS_CLOSE CURLY_BRACE_OPEN M block_item_list_opt CURLY_BRACE_CLOSE     
    {
        // While loop with a body enclosed in curly braces.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($7); // Convert the expression to a boolean.

        // Proper backpatching
        backpatch($11->nextlist, $6); // M1 to go back to the expression again.
        backpatch($7->truelist, $10); // M2 to go to the statement if the expression is true.
        $$->nextlist = $7->falselist; // If the expression is false, then exit the loop.

        // Emit a 'goto' to prevent fallthrough.
        string str = INT2STRING($6);		
        Q.emit("goto", str);	
        loop_name = "";
        changeTable(ST->parent);
    }
    | DO D M loop_statement M WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE semicolon
    {
        // Handle a 'do-while' statement.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($8); // Convert the expression to a boolean.

        // Proper backpatching
        backpatch($8->truelist, $3); // M1 to go back to the statement if the expression is true.
        backpatch($4->nextlist, $5); // M2 to go to check the expression if the statement is complete.

        $$->nextlist = $8->falselist; // Exit the loop if the statement is false.
        loop_name = "";
    }
    | DO D CURLY_BRACE_OPEN M block_item_list_opt CURLY_BRACE_CLOSE M WHILE PARENTHESIS_OPEN expression PARENTHESIS_CLOSE semicolon
    {
        // Handle a 'do-while' statement with a body enclosed in curly braces.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($10); // Convert the expression to a boolean.

        backpatch($10->truelist, $4); // M1 to go back to the statement if the expression is true.
        backpatch($5->nextlist, $7); // M2 to go to check the expression if the statement is complete.

        $$->nextlist = $10->falselist; // Exit the loop if the statement is false.
        loop_name = "";
    }
    | FOR F PARENTHESIS_OPEN X changetable declaration M expression_statement M expression N PARENTHESIS_CLOSE M loop_statement     
    {
        // Handle a 'for' loop with a declaration, check expression, and update expression.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($8); // Convert the check expression to a boolean.

        // Proper backpatching
        backpatch($8->truelist, $13); // If the check expression is true, go to M2.
        backpatch($11->nextlist, $7); // After N, go back to M1.
        backpatch($14->nextlist, $9); // The statement goes back to the expression.

        string str = INT2STRING($9);
        Q.emit("goto", str); // Emit a 'goto' to prevent fallthrough.
        $$->nextlist = $8->falselist; // Exit the loop if the statement is false.
        loop_name = "";
        changeTable(ST->parent);
    }
    | FOR F PARENTHESIS_OPEN X changetable expression_statement M expression_statement M expression N PARENTHESIS_CLOSE M loop_statement     
    {
        // Handle a 'for' loop with check and update expressions, without a declaration.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($8); // Convert the check expression to a boolean.

        // Proper backpatching
        backpatch($8->truelist, $13); // If the check expression is true, go to M2.
        backpatch($11->nextlist, $7); // After N, go back to M1.
        backpatch($14->nextlist, $9); // The statement goes back to the expression.

        string str = INT2STRING($9);
        Q.emit("goto", str); // Emit a 'goto' to prevent fallthrough.
        $$->nextlist = $8->falselist; // Exit the loop if the statement is false.
        loop_name = "";
        changeTable(ST->parent);
    }
    | FOR F PARENTHESIS_OPEN X changetable declaration M expression_statement M expression N PARENTHESIS_CLOSE M CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE      
    {
        // Handle a 'for' loop with a declaration, check expression, update expression, and a body enclosed in curly braces.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($8); // Convert the check expression to a boolean.

        // Proper Backpatching
        backpatch($8->truelist, $13); // If the check expression is true, go to M2.
        backpatch($11->nextlist, $7); // After N, go back to M1.
        backpatch($15->nextlist, $9); // The statement goes back to the expression.

        string str = INT2STRING($9);
        Q.emit("goto", str); // Prevent fallthrough.
        $$->nextlist = $8->falselist; // Exit the loop if the statement is false.
        loop_name = "";
        changeTable(ST->parent);
    }
    | FOR F PARENTHESIS_OPEN X changetable expression_statement M expression_statement M expression N PARENTHESIS_CLOSE M CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE
    {	
        // Handle a 'for' loop with check and update expressions, without a declaration, and with a body enclosed in curly braces.
        $$ = new Statement(); // Create a new statement.
        INT2BOOL($8); // Convert the expression to a boolean.

        // Proper backpatching
        backpatch($8->truelist, $13); // Backpatch &13.
        backpatch($11->nextlist, $7); // After N, go back to M1.
        backpatch($15->nextlist, $9); // The statement goes back to the expression.

        string str = INT2STRING($9);
        Q.emit("goto", str); // Emit goto str.
        $$->nextlist = $8->falselist; // Exit if the statement is false.
        loop_name = "";
        changeTable(ST->parent);                        
    }
    ;


jump_statement:
    GOTO IDENTIFIER semicolon
    { 
        // Handle a 'goto' statement.
        $$ = new Statement();
        label *l = find_label($2->name);

        if (l) {
            Q.emit("goto", "");
            list<int> lst = makelist(nextinstr());
            l->nextlist = merge(l->nextlist, lst);

            if (l->addr != -1)
                backpatch(l->nextlist, l->addr);
        } else {
            l = new label($2->name);
            l->nextlist = makelist(nextinstr());
            Q.emit("goto", "");
            label_store.push_back(*l);
        }
    }  
    | CONTINUE semicolon
    { 
        // Handle a 'continue' statement.
        $$ = new Statement();
    }	
    | BREAK semicolon
    { 
        // Handle a 'break' statement.
        $$ = new Statement();
    }
    | RETURN expression semicolon
    {
        // Handle a 'return' statement with an expression.
        $$ = new Statement();	
        Q.emit("return", $2->loc->name);
    }
    | RETURN semicolon
    {
        // Handle a 'return' statement without an expression.
        $$ = new Statement();	
        Q.emit("return", "");
    }
    ;


translation_unit:
    external_declaration
    { /*No action needed*/ }
    | translation_unit external_declaration
    { /*No action needed*/ }
    ;

external_declaration:
    function_definition
    { /*No action needed*/ }
    | declaration
    { /*No action needed*/ }
    ;

function_definition:
    declaration_specifiers declarator declaration_list_opt FUN_CT CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE 
    {
        // Handle a function definition.

        // Emit the end of function marker for the current function name.
        Q.emit("funcend", ST->name);

        // Set the parent Symbol Table to the global Symbol Table.
        ST->parent = globalST;

        // Update the function status for the declarator.
        $2->updateFuntionStatus(true);

        // Reset the function name and label data.
        table_count = 0;
        label_store.clear();

        // Change the Symbol Table to the global Symbol Table.
        changeTable(globalST);
    }
    ;


declaration_list_opt:
    declaration_list 
    { /*No action needed*/ }
    | %empty 
    { /*No action needed*/ }
    ;

declaration_list:
    declaration
    { /*No action needed*/ }
    | declaration_list declaration
    { /*No action needed*/ }
    ;

changetable: %empty 
    {    
        // This rule represents a change in the symbol table.
        // It includes some operations on the symbol table.
        parent_ST = ST;  // Backup the current symbol table.

        // If nested, call recursively on the nested table.
        if (currSymbolPtr->nested == NULL) {
            changeTable(new symtable(""));  // Create a new symbol table if it's nested.	                                           
        }
        else {
            changeTable(currSymbolPtr->nested);  // Change to the nested symbol table.
            Q.emit("label", ST->name);  // Emit a label in the intermediate code.
        }
    }
    ;


M: %empty
    {
        // This empty production is used for backpatching. 
        // It sets the result ($$) to the next instruction in the generated code.
        $$ = nextinstr();
    }
;

F: %empty
    {
        // This empty production is used at the beginning of a for statement.
        // It sets the loop_name to "FOR," which is useful for identifying the type of loop.
        loop_name = "FOR";
    }
;

W: %empty
    {
        // This empty production is used at the beginning of a while statement.
        // It sets the loop_name to "WHILE," helping to distinguish the loop type.
        loop_name = "WHILE";
    }
;

D: %empty
    {
        // This empty production is used at the beginning of a do-while statement.
        // It sets the loop_name to "DO_WHILE" for proper loop type identification.
        loop_name = "DO_WHILE";
    }
;

X: %empty 
{
    // Handle the case where X is empty (no loop labels).

    // Generate a unique name for the block symbol table.
    string name = ST->name + "$" + loop_name + "$" + to_string(table_count);
    table_count++; 

    // Create an entry in the current symbol table with the generated name.
    sym* s = ST->lookup(name); 

    // Create a nested symbol table for the block.
    s->nested = new symtable(name);
    s->nested->parent = ST;
    s->name = name;

    // Update the symbol type for the symbol entry to "block".
    s->update(new symboltype("block"));

    // Update the current symbol pointer to the newly created symbol entry.
    currSymbolPtr = s;
}   


N: %empty
	{
        /*
        In this production, we handle the case where N is empty.
        It creates a new Statement and sets its nextlist to a new list containing the current next instruction.
        After that, it emits a "goto" statement (action is not specified) for further processing.
        */
		$$ = new Statement();
		$$->nextlist=makelist(nextinstr());

		Q.emit("goto","");
	}
	;
FUN_CT: %empty 
{    
    // Handle the case when FUN_CT is empty (no function parameters).

    // Save the current symbol table as the parent symbol table.
    parent_ST = ST;                                                               

    // If the current symbol pointer's nested table is empty, create a new nested table.
    if (currSymbolPtr->nested == NULL) {
        changeTable(new symtable(curPossibleSTName));	                                           
    }
    else {
        // Change the current symbol table to the nested table and emit a "func" marker.
        changeTable(currSymbolPtr->nested);						               
        Q.emit("func", ST->name);
    }
}

semicolon:
SEMI_COLON
{
    // Set a flag to indicate that a lookup is inside the parent symbol table.
    lookupInsideParent = true;
}

%%

/*Auxiliaries*/
void yyerror(string s) {
    // print error
    cout<<s<<endl;
}
