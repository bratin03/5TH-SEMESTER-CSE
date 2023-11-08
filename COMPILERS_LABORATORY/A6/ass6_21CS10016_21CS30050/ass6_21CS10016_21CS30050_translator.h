/*
Assignment Number 6

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/
#ifndef __TRANSLATOR__H__
#define __TRANSLATOR__H__

#include <iostream>                                 // for input and output
#include <vector>                                   // for vector
#include <list>                                     // for list
#include <string>                                   // for string
#include <map>                                      // for BasicType class

using namespace std;

extern  char* yytext;
extern  int yyparse();


/*
                 Class Declarations              
*/

class sym;                                                                                 // Class for Symbol, an atomic entity of Symbol Table
class quad;                                                                                // Class for Quad, it stores the 4 main column data (op, res, arg1, arg2)
class label;                                                                               // stands for a single label entry in the label table
class symtable;                                                                            // Class for Symbol Table
class basicType;                                                                           // Class for the standard basic types, mainly used to find the size of basic data types
class quadArray;                                                                           // Class QuadArray, An Array of quads
class symboltype;                                                                          // Class for type of symbols of the symbol table
class Expression;                                                                          // Class for Expressions

typedef sym s;
typedef symboltype symtyp;
typedef Expression* Exps;

//
//              global variables
//
extern string symbolTableSuffix;                                                           // Current symbol suffix
extern bool lookupInsideParent;
extern string curPossibleSTName;
extern list <sym*> listOffunctions;
extern vector<string> stringsToBePrinted;
extern vector<string> floatsToBePrinted;
extern symtable* ST;                                                                       // Points to the current Symbol Table
extern symtable* globalST;                                                                 // Points to the Global Symbol Table
extern symtable* parent_ST;                                                                    // Points to the Parent of the current Symbol Table
extern s* currSymbolPtr;                                                                   // Points to the latest encountered symbol
extern quadArray Q;                                                                        // Global Quad Array : this stores the TAC in suitable format
extern basicType bt;                                                                       // BT is an instance of Basic Types used to find the size of inbuilt data types
extern long long int table_count;                                                          // denotes count of nested tables
extern string loop_name;                                                                   // Stores the name of the loop
extern vector<label>label_store;                                                           // table to store the labels

//
//      Definition of structure of each element of the symbol table
//
class sym  {                                                                                          // For an entry in Symbol Table
	public:
        string name;                                                                       // name of the symbol
        symboltype *type;                                                                  // type of the symbol, this give us more methods relevant to type
        int size;                                                                          // size of the symbol
        int offset;                                                                        // offset of symbol in ST, calulated after parsing
        symtable* nested;                                                                  // points to the nested symbol table
        string val;                                                                        // initial value of the symbol if specified
        bool isItFunction;                                                                 // True if the symbol represent a function

        string category; 
        // local, param, function

        inline void updateFuntionStatus(bool b){ isItFunction = b; }                       // inline function to update isItFunction
        sym (string , string t="int", symboltype* ptr = NULL, int width = 0);              // constructor
        sym* update(symboltype*);                                                          // Method to update different fields of an existing entry.
};

//
//      Definition of the label symbol
//
class label                                                                                // class of label symbols
{
    public:
        string name;                                                                       // name of the label
        int addr;                                                                          // address the label is pointing to.
        list<int> nextlist;                                                                // list of dangling goto statements

        label(string _name, int _addr = -1);                                               // label
};

//
//      Definition of the type of symbol
//
class symboltype 
{                                                                                           // Class to store the type of the symbol
    public:
        string type;                                                                        // stores the type of symbol. 
        int width;                                                                          // stores the size of Array (if we encounter an Array) and it is 1 in default case
        symboltype* arrtype;                                                                // Linked List for storing type of multiDimentional Arrays
        
        symboltype(string , symboltype* ptr = NULL, int width = 1);                         // Constructor
};

//
//          Class definition for the Symbol Table
//
class symtable 
{                                                                                           // class for the symbol table, made as a tree of tables with global table as the root
    public:
        string name;                                                                        // Name of the Table
        int count;                                                                          // Count of the temporary variables, helps in naming the next compiler generated temporary
        list<sym> symbols;                                                                  // The table of symbols which is essentially a list of sym
        symtable* parent;                                                                   // Parent SymbolTable of the current ST
        
        map<string, int> ActivationRecord; 

        symtable (string name="NULL");                                                      // Constructor
        s* lookup (string);                                                                 // Lookup for a symbol in ST
        void print();                                                                       // Print the ST
        void update();                                                                      // Update the ST
};

//
//      Definition of the Class quad 
//
class quad {                                                                                 // quad has four components:
    public:
        string res;                                                                          // Result
        string op;                                                                           // Operator - the op code and type of TAC depends on this
        string arg1;                                                                         // Argument 1
        string arg2;                                                                         // Argument 2    
                                                                                             // res = op(arg1, arg2);

	    // Used for printing
        void print();	
        void type1();                                                                        // for printing binary operators
        void type2();                                                                        // for printing relational operators and jumps

        //Overloaded Constructors						
        quad (string , string , string op = "=", string arg2 = "");			
        quad (string , int , string op = "=", string arg2 = "");				
        quad (string , float , string op = "=", string arg2 = "");			
};

//
//          Definition of the quad array type               
//
class quadArray {
                                                                                             // Quad Array Class, simple vector of quads with emit function
    public:
        vector<quad> Array;                                                                  // Simply an Array (vector) of quads
        void print();                                                                        // Print the quadArray
        //
        //          Overloaded emit function used by the parser
        //
        void emit(string , string , string arg1="", string arg2 = "");                       // Overloaded Emit function
        void emit(string , string , int, string arg2 = "");		  
        void emit(string , string , float , string arg2 = "");
        quadArray():Array(){}                                                                // simple constructor of QuadArray
};

//
//          Definition of the basic type
//
class basicType 
{                                                                                            // To denote a basic type
    public:
        static map<string, int> getSize;                                                     // map: Type -> size of (Type)
};

//
//     Definition of the expression type
//

class Expression {
    public:
    s* loc;                                                                                  // pointer to the symbol table entry
    string type;                                                                             // to store whether the expression is of type int or bool or float or char
    list<int> truelist;                                                                      // fruelist for boolean expressions
    list<int> falselist;                                                                     // falselist for boolean expressions
    list<int> nextlist;                                                                      // for statement expressions

    Expression():loc(NULL),type(), truelist(), falselist(), nextlist(){}                      // Default constructor
    
};

//
//          Class array type
//
struct Array {
    string atype;                                                                            // Used for type of Array: may be "ptr"(pointer) or "arr"(array) type
    s* loc;                                                                                  // Location used to compute address of Array
    s* Array;                                                                                // pointer to the symbol table Symbol
    symboltype* type;                                                                        // Type of Subarray, used for multidimesional arrays
};

class Statement {
    public:
    list<int> nextlist;                                                                      // nextlist for Statement with dangling exit
    Statement():nextlist(){}                                                                 // default constructor
};

/*
    The gentemp function generates a new symbol (temporary variable) in the current symbol table
    Then it returns the pointer to the Current entry
*/
s* gentemp (symboltype* , string init = "");

/*
    The backpatch utility function
    Takes in a list and then stores the
    target value given in addr 
*/
void backpatch (list <int> , int );                                                          // backpatch the dangling instructions with the given address(parameter) 

/*
    Initializes a list with only one element (init)
    Then returns it
*/
list<int> makelist (int );                                                                   // Make a new list contanining an integer address

/*
    Merges 2 lists and returns the result
*/
list<int> merge (list<int> &l1, list <int> &l2);                                             // Merge two lists into a single list

/*
    Some miscellaneous functions to aid our design
*/

label* find_label(string name);

// Some Helper functions
string INT2STRING(int);                                                              // Utility function to convert integer to string
string FLT2STRING(float);                                                          // Utility function to convert float to string
Exps INT2BOOL(Exps);                                                                 // Utility function to convert int expression to boolean
Exps BOOL2INT(Exps);                                                                 // Utility function to convert boolean expression to int

s* convertType(sym*, string);                                                                // Utility function for type conversion
int computeSize (symboltype *);                                                              // Utility function to calculate size of symbol type
void changeTable (symtable* );                                                               // Utility function to change current table
bool compareSymbolType(sym* &s1, sym* &s2);                                                  // Utility function to check for same type of two symbol table entries
bool compareSymbolType(symboltype*, symboltype*);                                            // Utility function to check for same type of two symboltype objects

// Getting the address of the next instruction: Simply the size of the quad array
int nextinstr();                                                                             // Returns the next instruction number

//
//           Some Other function for printing
//
// Aiding in indentation
string printType(symboltype *);                                                              // print type of symbol
void Add_Space(int);

symtable* flattenFunctionSymbolTable(sym *function);
#endif
