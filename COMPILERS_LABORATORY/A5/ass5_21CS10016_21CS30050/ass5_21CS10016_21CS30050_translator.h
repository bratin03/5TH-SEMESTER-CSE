/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/


#ifndef __TRANSLATOR__H__
#define __TRANSLATOR__H__

#include <bits/stdc++.h>

using namespace std;

extern char *yytext;
extern int yyparse();

class sym;        // Class for Symbol, an atomic entity of Symbol Table
class quad;       // Class for Quad, it stores the 4 main column data (op, res, arg1, arg2)
class label;      // stands for a single label entry in the label table
class symtable;   // Class for Symbol Table
class basicType;  // Class for the standard basic types, mainly used to find the size of basic data types
class quadArray;  // Class QuadArray, An Array of quads
class symboltype; // Class for type of symbols of the symbol table
class Expression; // Class for Expressions

typedef sym s;
typedef symboltype symtyp;
typedef Expression *Exps;

//
//              global variables
//

extern symtable *ST;              // Points to the current Symbol Table
extern symtable *globalST;        // Points to the Global Symbol Table
extern symtable *parent_ST;           // Points to the Parent of the current Symbol Table
extern s *currSymbolPtr;          // Points to the latest encountered symbol
extern quadArray Q;               // Global Quad Array : this stores the TAC in suitable format
extern basicType bt;              // BT is an instance of Basic Types used to find the size of inbuilt data types
extern long long int table_count; // denotes count of nested tables
extern string loop_name;          // Stores the name of the loop
extern vector<label> label_store; // table to store the labels

// ──────── sym Class ────────

// A symbol entry in the symbol table
class sym
{ // For an entry in Symbol Table
public:
    string name;       // The name of the symbol
    symboltype *type;  // The type of the symbol, offering relevant type-related methods
    int size;          // Size of the symbol
    int offset;        // Offset of the symbol in the symbol table, calculated post-parsing
    symtable *nested;  // Points to a nested symbol table
    string val;        // The initial value of the symbol if specified
    bool isItFunction; // Indicates whether the symbol represents a function

    inline void UpdateFunctStatus(bool b) { isItFunction = b; }         // A method to swiftly update the function status
    sym(string, string t = "int", symboltype *ptr = NULL, int width = 0); // Constructor for creating a symbol entry
    sym *update(symboltype *);                                            // A method to update various fields of an existing symbol entry
};

// ──────── label Class ────────

// Definition of a label symbol
class label
{
public:
    string name;        // The label's name
    int addr;           // The address to which the label points
    list<int> nextlist; // A list of dangling goto statements

    // Constructor for a label symbol
    label(string _name, int _addr = -1);
};

// ──────── symboltype Class ────────

// Definition of the type of symbol
class symboltype
{
public:
    string type;         // Stores the type of the symbol
    int width;           // Stores the size of an array (if applicable), default is 1
    symboltype *arrtype; // Linked List for storing the type of multi-dimensional arrays

    symboltype(string, symboltype *ptr = NULL, int width = 1); // Constructor
};

// ──────── symtable Class ────────

// Class definition for the Symbol Table
class symtable
{
public:
    string name;       // Name of the Table
    int count;         // Count of temporary variables, assists in naming compiler-generated temporaries
    list<sym> symbols; // The table of symbols, essentially a list of sym
    symtable *parent;  // Parent SymbolTable of the current ST

    symtable(string name = "NULL"); // Constructor
    s *lookup(string);              // Lookup for a symbol in ST
    void print();                   // Print the ST
    void update();                  // Update the ST
};

// ──────── quad Class ────────

// Definition of the Class quad
class quad
{
public:
    string res;  // Result
    string op;   // Operator - the op code and type of TAC depends on this
    string arg1; // Argument 1
    string arg2; // Argument 2
                 // res = op(arg1, arg2);

    // Used for printing
    void print();
    void type1(); // For printing binary operators
    void type2(); // For printing relational operators and jumps

    // Overloaded Constructors
    quad(string, string, string op = "=", string arg2 = "");
    quad(string, int, string op = "=", string arg2 = "");
    quad(string, float, string op = "=", string arg2 = "");
};

// ──────── quadArray Class ────────

// Definition of the quad array type
class quadArray
{
    // Quad Array Class, a simple vector of quads with an emit function
public:
    vector<quad> Array; // Simply an Array (vector) of quads
    void print();       // Print the quadArray
    //
    // Overloaded emit function used by the parser
    //
    void emit(string, string, string arg1 = "", string arg2 = ""); // Overloaded Emit function
    void emit(string, string, int, string arg2 = "");
    void emit(string, string, float, string arg2 = "");
    quadArray() : Array() {} // Simple constructor of QuadArray
};

// ──────── basicType Class ────────

// Definition of the basic type
class basicType
{
public:
    static map<string, int> getSize; // Map: Type -> size of (Type)
};

// ──────── Expression Class ────────

// Definition of the expression type
class Expression
{
public:
    s *loc;              // Pointer to the symbol table entry
    string type;         // To store whether the expression is of type int or bool or float or char
    list<int> truelist;  // Truelist for boolean expressions
    list<int> falselist; // Falselist for boolean expressions
    list<int> nextlist;  // For statement expressions

    Expression() : loc(NULL), type(), truelist(), falselist(), nextlist() {} // Default constructor
};

// ──────── Array Struct ────────

struct Array
{
    string atype;     // Used for the type of Array: may be "ptr" (pointer) or "arr" (array) type
    s *loc;           // Location used to compute the address of the Array
    s *Array;         // Pointer to the symbol table Symbol
    symboltype *type; // Type of Subarray, used for multidimensional arrays
};

// ──────── Statement Class ────────

class Statement
{
public:
    list<int> nextlist;         // Nextlist for Statement with dangling exit
    Statement() : nextlist() {} // Default constructor
};

/*
    The gentemp function generates a new symbol (temporary variable) in the current symbol table.
    It also initializes this symbol with the provided type and optional initial value.
    Finally, it returns a pointer to the newly created symbol.
*/
s *gentemp(symboltype *, string init = "");

/*
    The backpatch utility function takes in a list of instruction addresses and updates them
    to point to the provided target address. It is used to resolve dangling goto statements.
*/
void backpatch(list<int>, int);

/*
    The makelist function initializes a new list with a single integer address (init).
    It returns the newly created list.
*/
list<int> makelist(int);

/*
    The merge function takes two lists (l1 and l2) and merges them into a single list.
    The merged list is then returned.
*/
list<int> merge(list<int> &l1, list<int> &l2);

/*
    The find_label function searches for a label with the given name and returns a pointer to it.
*/

label *find_label(string name);

// Helper functions

/*
    The INT2STRING utility function converts an integer to a string and returns the string representation.
*/
string INT2STRING(int);

/*
    The FLT2STRING utility function converts a float to a string and returns the string representation.
*/
string FLT2STRING(float);

/*
    The INT2BOOL utility function takes an integer expression and converts it to a boolean expression.
*/
Exps INT2BOOL(Exps);

/*
    The BOOL2INT utility function takes a boolean expression and converts it to an integer expression.
*/
Exps BOOL2INT(Exps);

/*
    The convertType utility function takes a symbol and a target type as parameters.
    It converts the symbol's type to the target type and returns a pointer to the modified symbol.
*/
s *convertType(sym *, string);

/*
    The computeSize utility function calculates the size of a symbol type and returns the size.
*/
int computeSize(symboltype *);

/*
    The changeTable utility function changes the current symbol table to the one specified as a parameter.
*/
void changeTable(symtable *);

/*
    The compareSymbolType utility function compares the types of two symbol table entries (s1 and s2).
    It returns true if the types are the same.
*/
bool compareSymbolType(sym *&s1, sym *&s2);

/*
    The compareSymbolType utility function compares the types of two symboltype objects.
    It returns true if the types are the same.
*/
bool compareSymbolType(symboltype *, symboltype *);

// Other functions

/*
    The nextinstr function returns the address of the next instruction by examining the size of the quad array.
*/
int nextinstr();

// Printing and formatting

/*
    The printType function prints the type of a symbol (symboltype) and returns it as a string.
*/
string printType(symboltype *);

/*
    The Add_Space function adds indentation to the output by adding the specified number of spaces.
*/
void Add_Space(int);

// End of the header
#endif
