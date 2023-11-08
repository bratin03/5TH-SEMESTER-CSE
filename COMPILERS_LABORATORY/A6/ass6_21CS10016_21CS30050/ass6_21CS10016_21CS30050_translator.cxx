/*
Assignment Number 6

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/
#include "ass6_21CS10016_21CS30050_translator.h"

#include <bits/stdc++.h>

using namespace std;

/*
  Declaration of global variables for storing essential data.
*/
basicType bt; // Instantiate the basicType class, which holds basic type information.

// Data structures for storage
symtable *globalST;        // Pointer to the Global Symbol Table
symtable *parent_ST;       // Pointer to the Parent Symbol Table
symtable *ST;              // Pointer to the Current Symbol Table
quadArray Q;               // Array for storing intermediate code (quads)
sym *currSymbolPtr;        // Pointer to the current symbol
vector<label> label_store; // Vector for label storage

// Utility variables
string variable_type;  // Variable to keep track of the latest found data type
long long table_count; // Variable for counting the number of tables
string loop_name;      // Variable for storing the name of the current loop
int lineno = 1;        // Variable for tracking the current line number
string symbolTableSuffix;
bool lookupInsideParent;
string curPossibleSTName;
list<sym *> listOffunctions;
vector<string> stringsToBePrinted;
vector<string> floatsToBePrinted;

/*
    Implementation of the Symbol Type Class functions
*/
symboltype::symboltype(string type, symboltype *arrtype, int width)
    : type(type), width(width), arrtype(arrtype)
{
    // Constructor for a given type of symbol.
    // 'type' is the primary data type, such as int, float, char, etc.
    // 'width' represents the size in bytes of the data type.
    // 'arrtype' points to the element type for arrays, or NULL for non-array types.
}

/*
    Constructor for symbols to be stored in the symbol table.
*/
sym::sym(string name, string dataType, symboltype *arrayType, int width)
    : name(name)
{
    // Initialize symbol properties.
    type = new symboltype(dataType, arrayType, width); // Create a symbol type.
    size = computeSize(type);                          // Calculate its size.
    offset = 0;                                        // Initial offset is set to 0, will be adjusted later.
    val = "";                                          // Initial value is not yet defined.
    nested = NULL;                                     // No nested symbol tables attached.
    isItFunction = false;                              // Indicates if the current entry is a function.
    category = "";                                     // Category of the symbol
}

/*
    Update the symbol's properties and return the updated symbol.
*/
sym *sym::update(symboltype *newType)
{
    // Update the symbol's type and size based on the provided type.
    type = newType;              // Update the new type.
    size = computeSize(newType); // Recalculate the size.
    return this;                 // Return the updated symbol.
}

/*
    Constructor for a label in intermediate code generation.
*/
label::label(string _name, int _addr) : name(_name), addr(_addr), nextlist()
{
    // Initialize a label with a given name and associated address.
    // '_name' is the label's name.
    // '_addr' is the associated address.
    // 'nextlist' is a list of quads referencing this label.
}

/*
    Constructor for an empty symbol table
*/
symtable::symtable(string _name)
    : name(_name), count(0), symbols(), parent(NULL)
{
    // Constructor for a symbol table.
    // '_name' is the name of the symbol table.
    // 'count' keeps track of the number of temporary variables in the table.
    // 'symbols' is a container for storing symbols within the table.
    // 'parent' points to the parent symbol table; NULL for the global symbol table.
}

/**
 This function is used to look up a symbol (variable or function) by its name within the symbol table.
 It checks for the symbol in the current symbol table and its parent symbol tables, if applicable.
 If the symbol is not found, it creates a new local variable in the current symbol table.
 Returns:
 - A pointer to the found symbol if it exists.
 - NULL if the symbol is not found.
 */
sym *symtable::lookup(string name)
{
    sym *symbol;

    // Check if the name refers to a function
    string nameOfFunc = name;
    if (nameOfFunc.find(".") != nameOfFunc.npos)
        nameOfFunc = nameOfFunc.substr(0, nameOfFunc.find("."));

    for (auto funcs : listOffunctions)
    {
        if (funcs != NULL && funcs->name == nameOfFunc)
            return funcs;
    }

    // Iterate over the symbols in the current symbol table
    for (auto &it : symbols)
    {
        if (it.name == name)
            return &it;
    }

    sym *ptr = NULL;

    // Recursively look up the symbol in the parent symbol table
    if (this->parent && lookupInsideParent)
    {
        string toSearchName = name;
        if (toSearchName.find(".") != toSearchName.npos)
        {
            while (!toSearchName.empty() && toSearchName.back() != '.')
            {
                toSearchName.pop_back();
            }
            if (!toSearchName.empty() && toSearchName.back() == '.')
            {
                toSearchName.pop_back();
            }
            toSearchName += ("." + this->parent->name);
        }
        ptr = this->parent->lookup(toSearchName);
    }

    // If the symbol is not found in the current symbol table, create a new symbol
    // and return its address
    if (ST == this && !ptr)
    {
        symbol = new sym(name);
        symbol->category = "local"; // It is a local variable
        symbols.push_back(*symbol); // Add the symbol to the table
        return &symbols.back();     // Return the symbol's address
    }
    else if (ptr)
        // If the symbol is found in the parent symbol table, return the existing address
        return ptr;

    return NULL; // If the symbol is not found, return NULL
}

/*
    Utility function to update the symbol table and its nested tables.
*/
void symtable::update()
{
    // Create a list of symbol tables to store nested tables.
    list<symtable *> nestedTables;
    int offset = 0; // Initialize the offset variable.

    for (auto &symbol : symbols)
    {
        symbol.offset = offset; // Set the offset for the symbol.

        if (symbol.isItFunction)
        {
            symbol.size = 0; // If it's a function, set its size to 0.
        }

        offset += symbol.size; // Increment the offset by the size of the current symbol.

        // Check for nested symbol tables.
        if (symbol.nested != NULL)
        {
            nestedTables.push_back(symbol.nested); // Add nested table to the list for further processing.
        }
    }

    // Recursively update all the nested symbol tables.
    for (auto &nestedTable : nestedTables)
    {
        nestedTable->update(); // Update nested symbol tables.
    }
}

/*
    Utility function for printing the symbol table with proper indentation
*/
void symtable::print()
{
    int next_instr = 0;

    // We store all the nested symbol tables in a list
    list<symtable *> nestedTables;

    // Print a horizontal line of slashes and backslashes for better readability
    cout << string(75, '/') << string(75, '\\') << '\n';

    cout << "Symbol Table: " << name;
    Add_Space(40 - name.length());
    cout << " Parent Symbol Table: ";

    if (!parent)
        cout << "NULL" << '\n'; // If there's no parent, print "NULL"
    else
        cout << parent->name << '\n'; // Print the parent's name if available

    cout << string(150, '=') << '\n';

    // Table headers as per requirement
    cout << "Name";
    Add_Space(23); // Print the "Name" column header
    cout << "|";
    Add_Space(2);
    cout << "Type";
    Add_Space(17); // Print the "Type" column header
    cout << "|";
    Add_Space(2);
    cout << "Size";
    Add_Space(9); // Print the "Size" column header
    cout << "|";
    Add_Space(2);
    cout << "Offset";
    Add_Space(7); // Print the "Offset" column header
    cout << "|";
    Add_Space(2);
    cout << "Initial Value";
    Add_Space(5); // Print the "Initial Value" column header
    cout << "|";
    Add_Space(2);
    cout << "Nested Table" << '\n';
    // Print the "Nested Table" column header

    // Printing the symbols inside
    for (auto &symbol : symbols)
    {
        cout << symbol.name;                  // Print the name of the symbol
        Add_Space(27 - symbol.name.length()); // Align the name column
        cout << "|";
        Add_Space(2);
        // Use PrintType to print the type of the symbol entry, and if it's a function, print "function"
        string typeString = (symbol.isItFunction) ? "function" : printType(symbol.type);
        cout << typeString;                  // Print the type of the symbol
        Add_Space(21 - typeString.length()); // Align the type column
        cout << "|";
        Add_Space(2);

        cout << symbol.size;                             // Print the size of the symbol
        Add_Space(13 - to_string(symbol.size).length()); // Align the size column
        cout << "|";
        Add_Space(2);
        cout << symbol.offset;                             // Print the offset of the symbol
        Add_Space(13 - to_string(symbol.offset).length()); // Align the offset column
        cout << "|";
        Add_Space(2);
        // Print all the required information
        cout << symbol.val;                  // Print the initial value of the symbol
        Add_Space(18 - symbol.val.length()); // Align the initial value column
        cout << "|";
        Add_Space(2);

        // Check for nested tables
        if (symbol.nested == NULL)
        {
            cout << "null" << '\n'; // If there's no nested table, print "NULL"
        }
        else
        {
            cout << symbol.nested->name << '\n';   // Print the name of the nested table
            nestedTables.push_back(symbol.nested); // Store nested tables for further printing
        }
    }

    cout << string(150, '=') << "\n\n";
    // Recursively print nested symbol tables
    for (auto &it : nestedTables)
    {
        it->print();
    }
}

/*
    Quad functions
*/

// Overloaded constructors for creating quadruples (quads)

// Constructor for quadruples with string operands
quad::quad(string res, string arg1, string op, string arg2)
    : op(op), arg1(arg1), arg2(arg2), res(res) {}

// Constructor for quadruples with an integer operand, converting the integer to a string
quad::quad(string res, int arg1, string op, string arg2)
    : op(op), arg1(INT2STRING(arg1)), arg2(arg2), res(res) {}

// Constructor for quadruples with a float operand, converting the float to a string
quad::quad(string res, float arg1, string op, string arg2)
    : op(op), arg1(FLT2STRING(arg1)), arg2(arg2), res(res) {}

void quad::print()
{
    int next_instr = 0;

    // Binary Assignment Instruction
    vector<string> binary_ops = {"+", "-", "*", "/", "%", "|", "^", "&"};
    for (auto check : binary_ops)
        if (op == check)
        {
            type1(); // Print type 1 quad
            cout << '\n';
            return;
        }

    // Relational operators | Conditional Jump Instruction
    vector<string> relational_ops = {"==", "!=", "<=", "<", ">", ">="};
    for (auto check : relational_ops)
        if (op == check)
        {
            type2(); // Print type 2 quad
            cout << '\n';
            return;
        }
    // Unconditional Jump Instruction
    if (op == "goto")
        cout << "goto " << res;

    // Shift operators | Binary Assignment Instruction
    else if (op == ">>")
        type1(); // Print type 1 quad
    else if (op == "<<")
        type1(); // Print type 1 quad

    // Assignment operator | Copy Assignment Instruction
    else if (op == "=")
        cout << res << " = " << arg1;

    // Assignment + operation | Unary Assignment Instruction
    else if (op == "=&")
        cout << res << " = &" << arg1; // reference
    else if (op == "=*")
        cout << res << " = *" << arg1; // pointer
    else if (op == "*=")
        cout << "*" << res << " = " << arg1; // *res = arg1
    else if (op == "uminus")
        cout << res << " = -" << arg1;
    else if (op == "~")
        cout << res << " = ~" << arg1;
    else if (op == "!")
        cout << res << " = !" << arg1;

    // Other operators
    // Indexed Copy Instruction
    else if (op == "=[]")
        cout << res << " = " << arg1 << "[" << arg2 << "]";
    else if (op == "[]=")
        cout << res << "[" << arg1 << "]"
             << " = " << arg2;
    // Return Value
    else if (op == "return")
        cout << "return " << res;
    // Procedure call
    else if (op == "param")
        cout << "param " << res;
    else if (op == "call")
        cout << res << " = "
             << "call " << arg1 << ", " << arg2;
    else if (op == "label")
        cout << "Label " << res << ": ";
    else if (op == "func")
        cout << "function " << res << ": ";
    else if (op == "funcend")
        cout << ""; // Function end, no printing
    else if (op == "equalstr")
        cout << res << " = " << stringsToBePrinted.at(stoi(arg1)); // Assign string to a variable
    else if (op == "equalfloat")
       cout << res << " = " << floatsToBePrinted.at(stoi(arg1)); // Assign float to a variable
    else
        cout << "Operator not found " << op; // Handle unknown operators
    cout << '\n';
}

/**

 This function is used to print quads with binary operations.
 It prints the result variable, the first operand, the operation, and the second operand.
*/
void quad::type1()
{
    cout << res << " = " << arg1 << " " << op << " " << arg2;
}

/**

 This function is used to print quads with relational operations and jumps.
 It prints "if" followed by the first operand, the relational operation, the second operand,
 and "goto" followed by the result (target) label.
 */
void quad::type2()
{
    cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << res;
}

/**

 This function is the main utility function for printing all the three-address codes (TAC) stored in the quadArray.
 It formats and prints the quads, including labels, functions, and function endings, with proper indentation.
 Quads are sequentially numbered for reference.
 */
void quadArray::print()
{
    cout << string(75, '/') << string(75, '\\') << '\n'; // Print a line of slashes for visual separation.
    cout << "THREE ADDRESS CODE (TAC): " << '\n';        // Header for the TAC section.
    cout << string(150, '=') << '\n';                    // Print a line of equal signs for a visual separator.

    int j = 0; // Initialize a counter for quad indices.

    // Printing all the stored quads in the Array with proper indentation
    for (auto &it : Array)
    {
        if (it.op == "label" || it.op == "func")
        {
            cout << '\n'
                 << j << ": ";
            it.print();
        }
        else if (it.op != "funcend")
        {
            cout << j << ": ";
            Add_Space(4); // Add indentation for non-label, non-func, non-funcend quads
            it.print();
        }
        j++;
    }
    cout << string(150, '=') << '\n'; // Print a line of equal signs for a visual separator.
}

/*
    Creates a corresponding quad from the three-address code and then stores it in the array
*/
void quadArray::emit(string op, string res, string arg1, string arg2)
{
    // This function creates a new quad with the specified operation 'op', result 'res', and arguments 'arg1' and 'arg2'.
    quad q1(res, arg1, op, arg2); // Create a new quad with string operands.
    Array.push_back(q1);          // Add the quad to the quad array.
}

void quadArray::emit(string op, string res, int arg1, string arg2)
{
    // This function creates a new quad with the specified operation 'op', result 'res', and integer argument 'arg1' and 'arg2'.
    quad q2(res, arg1, op, arg2); // Create a new quad with an integer operand.
    Array.push_back(q2);          // Add the quad to the quad array.
}

void quadArray::emit(string op, string res, float arg1, string arg2)
{
    // This function creates a new quad with the specified operation 'op', result 'res', and float argument 'arg1' and 'arg2'.
    quad q3(res, arg1, op, arg2); // Create a new quad with a float operand.
    Array.push_back(q3);          // Add the quad to the quad array.
}

/*
    The gentemp function generates a new symbol (temporary variable) in the current symbol table
    Then it returns the pointer to the Current entry
*/
sym *gentemp(symboltype *t, string str_new)
{
    static int tempCnt = 1;                         // Static counter for generating unique temporary variable names
    string tmp_name = "t_" + INT2STRING(tempCnt++); // Generate a new unique name for the temporary variable
    sym *s = new sym(tmp_name);                     // Create a new symbol entry
    s->type = t;                                    // Set the type of the temporary variable
    s->size = computeSize(t);                       // Compute and set the size of the variable
    s->val = str_new;                               // Set the initial value of the variable
    s->category = "temp";                           // Set the category of the variable to "temp"
    ST->symbols.push_back(*s);                      // Add the symbol to the current symbol table's list of symbols
    return &ST->symbols.back();                     // Return a pointer to the newly created symbol
}

/*
    Utility function to search for a label by name
    Returns a pointer to the label if found, otherwise NULL.
*/
label *find_label(string _name)
{
    for (auto &it : label_store)
    {
        if (it.name == _name)
            return &(it);
    }
    return NULL;
}

/*
    The `backpatch` utility function takes in a list of quad indices and stores
    the target value (address) given in 'addr' as the result of each quad in the list.
*/
void backpatch(list<int> list1, int addr)
{
    string str = INT2STRING(addr);

    // Update the 'res' field of each quad in the list with the new address.
    for (auto &it : list1)
        Q.Array[it].res = str;
}

/*
    Initializes a list with only one element ('init') and returns it.
*/
list<int> makelist(int init)
{
    list<int> newlist(1, init);
    return newlist;
}

/*
    Merges two lists ('a' and 'b') and returns the result.
*/
list<int> merge(list<int> &a, list<int> &b)
{
    // Merges list 'b' into list 'a'.
    a.merge(b);
    return a;
}
// Some standard conversions

// Convert an integer to a string
string INT2STRING(int a)
{
    return to_string(a);
}

// Convert a float to a string
string FLT2STRING(float x)
{
    ostringstream buff;
    buff << x;
    return buff.str();
}

// Convert a boolean expression to an integer
Expression *BOOL2INT(Expression *e)
{
    if (e->type == "bool")
    {
        // Implementing the standard procedures and
        // Generating required attributes for int
        e->loc = gentemp(new symboltype("int"));
        backpatch(e->truelist, nextinstr());
        Q.emit("=", e->loc->name, "true");
        int p = nextinstr() + 1;
        string str = INT2STRING(p);
        Q.emit("goto", str);
        backpatch(e->falselist, nextinstr());
        Q.emit("=", e->loc->name, "false");
    }
    return e;
}

// Convert an integer to a boolean expression
Expression *INT2BOOL(Expression *e)
{
    if (e->type != "bool")
    {
        // Implementing the standard procedures and
        // Generating required attributes for bool
        e->falselist = makelist(nextinstr());
        Q.emit("==", "", e->loc->name, "0");
        e->truelist = makelist(nextinstr());
        Q.emit("goto", "");
    }
    return e;
}

/*
    Converts from one type to another and returns the converted instance
*/

// Function to convert the type of a symbol
sym *convertType(sym *s, string rettype)
{
    // This function converts the type of a symbol 's' to the desired 'rettype'.

    // Declaration of a temporary symbol with the desired return type
    sym *temp = gentemp(new symboltype(rettype));

    if (s->type->type == "float")
    {
        // If the source type is float
        // Convert float to int
        if (rettype == "int")
        {
            Q.emit("=", temp->name, "float2int(" + (*s).name + ")");
            return temp; // Return the temporary symbol with the converted type
        }
        // Convert float to char
        else if (rettype == "char")
        {
            Q.emit("=", temp->name, "float2char(" + (*s).name + ")");
            return temp; // Return the temporary symbol with the converted type
        }
        return s; // If no conversion is needed, return the original symbol 's'
    }
    else if ((*s).type->type == "int")
    {
        // If the source type is int
        // Convert int to float
        if (rettype == "float")
        {
            Q.emit("=", temp->name, "int2float(" + (*s).name + ")");
            return temp; // Return the temporary symbol with the converted type
        }
        // Convert int to char
        else if (rettype == "char")
        {
            Q.emit("=", temp->name, "int2char(" + (*s).name + ")");
            return temp; // Return the temporary symbol with the converted type
        }
        return s; // If no conversion is needed, return the original symbol 's'
    }
    else if ((*s).type->type == "char")
    {
        // If the source type is char
        // Convert char to int
        if (rettype == "int")
        {
            Q.emit("=", temp->name, "char2int(" + (*s).name + ")");
            return temp; // Return the temporary symbol with the converted type
        }
        // Convert char to float
        if (rettype == "float")
        {
            Q.emit("=", temp->name, "char2float(" + (*s).name + ")");
            return temp; // Return the temporary symbol with the converted type
        }
        return s; // If no conversion is needed, return the original symbol 's'
    }
    return s; // If the source type and desired type match, return the original symbol 's'
}

/**

 The `changeTable` function is a utility function used to change the current symbol table.
 It updates the global `ST` (current symbol table) pointer to the specified new symbol table,
 and it also updates the `symbolTableSuffix` for the current context.
 */
void changeTable(symtable *newtable)
{
    ST = newtable;                            // Update the current symbol table to the new symbol table
    symbolTableSuffix = "." + newtable->name; // Update the symbol table suffix for the current context
}

/*
    Overloaded compareSymbolType function to compare two entries in the symbol table
    Initially called with 2 symbols, then we may call with the types for further checking
*/
bool compareSymbolType(sym *&s1, sym *&s2)
{
    // This function compares the types of two symbols and attempts type conversion if necessary.

    // Get the types of the two symbols
    symboltype *type1 = s1->type;
    symboltype *type2 = s2->type;

    sym *temp;    // Temporary symbol for type conversion
    int flag = 0; // A flag to track whether type conversion is performed

    if (compareSymbolType(type1, type2))
        flag = 1;
    // Check if the types are compatible, and if so, set the flag to 1.

    else if (s1 != (temp = convertType(s1, type2->type)))
    {
        // If the types are not compatible, attempt to convert s1's type to match s2's type
        flag = 1;  // Set the flag to 1 to indicate a successful conversion
        s1 = temp; // Update s1 with the converted symbol
    }

    else if (s2 != (temp = convertType(s2, type1->type)))
    {
        // If the first conversion didn't work, attempt to convert s2's type to match s1's type
        flag = 1;  // Set the flag to 1 to indicate a successful conversion
        s2 = temp; // Update s2 with the converted symbol
    }

    if (flag)
        return true; // If a type conversion occurred, return true to indicate compatibility

    else
        return false; // If no conversion occurred, return false to indicate incompatibility
}

/*
    Utility function to compare types of two symbols
*/
bool compareSymbolType(symboltype *t1, symboltype *t2)
{
    // Check if both types are null
    if (!t1 && !t2)
    {
        return true;
    }
    // Check if either type is null or their types don't match
    else if (!t1 || !t2 || t1->type != t2->type)
    {
        return false;
    }
    else
    {
        // Recursively check for array types
        return compareSymbolType(t1->arrtype, t2->arrtype);
    }
}

// Aiding in indentation
void Add_Space(int n)
{
    // This utility function prints spaces for indentation.
    cout << " ";
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}

// Getting the address of the next instruction: Simply the size of the quad array
int nextinstr()
{
    // This function returns the address of the next instruction by determining the size of the quad array.
    return Q.Array.size();
}

// Utility function to compute the size
int computeSize(symboltype *t)
{
    // This utility function calculates the size of a symboltype. It handles different types and arrays.
    if ((t->arrtype != NULL) && (t->type == "arr"))
        return (t->width) * computeSize(t->arrtype);
    else if (basicType::getSize.count(t->type))
        return basicType::getSize[t->type];

    return 0; // Returning 0 indicates an error or unknown type.
}

// Prints the type of the symbol in the symbol table
string printType(symboltype *t)
{
    if (t == NULL)
        return "NULL"; // If the type is NULL, return "NULL".
    else if (t->type == "ptr")
        return "ptr(" + printType(t->arrtype) + ")"; // If it's a pointer type, include details of the pointed type.
    else if (t->type == "arr")
    {
        string str = INT2STRING(t->width);                       // Recursive for arrays - includes array size.
        return "arr(" + str + "," + printType(t->arrtype) + ")"; // Format the type as "arr(size, element_type)".
    }
    else if (basicType::getSize.count(t->type))
        return t->type; // If it's a basic type (e.g., int, char), simply return the type.

    return "NA"; // If the type is not recognized, return "NA" (Not Available) to indicate an error.
}

/**
 The `flattenFunctionSymbolTable` function is responsible for flattening the symbol table hierarchy
 associated with a function, making it more accessible and manageable for further processing.
 It creates a new symbol table (`functionTable`) that represents the flattened symbol table of the given function.
 The function table is populated with symbols from the original hierarchical symbol tables,
 and the function's `nested` pointer is updated to point to the new flattened table.
 *
 Parameters:
 - `function`: A pointer to the symbol representing the function for which the symbol table is to be flattened.

 Returns:
 A pointer to the newly created flattened symbol table (`functionTable`).
 */

symtable *flattenFunctionSymbolTable(sym *function)
{
    // Create a new symbol table for the flattened function symbol table
    symtable *originalFunctionTable = function->nested;
    symtable *functionTable = new symtable(originalFunctionTable->name);

    // Set the parent of the new function symbol table
    functionTable->parent = originalFunctionTable->parent;

    // Create a list to track all symbol tables related to the function
    vector<symtable *> listOfFunctionTables = {originalFunctionTable};

    // Iterate through all symbol tables associated with the function and flatten them
    for (int i = 0; i < listOfFunctionTables.size(); ++i)
    {
        symtable *curfuntable = listOfFunctionTables[i];
        for (auto &currentSymbol : curfuntable->symbols)
        {
            if (currentSymbol.nested != NULL)
            {
                // If the symbol has a nested symbol table, add it to the list for further processing
                listOfFunctionTables.push_back((currentSymbol.nested));
            }
            else
            {
                // If the symbol does not have a nested symbol table, add it to the flattened function symbol table
                functionTable->symbols.push_back(currentSymbol);
            }
        }
    }

    // Update the function's nested pointer to point to the newly flattened symbol table
    function->nested = functionTable;

    // Return a pointer to the flattened symbol table
    return functionTable;
}

// Storing the basic types with size
// Using sizeof for machine-independent translation
map<string, int> basicType::getSize = {{"null", 0}, // A map that associates basic types with their sizes.
                                       {"void", 0},
                                       {"char", sizeof(char)},
                                       {"int", sizeof(int)},
                                       {"float", sizeof(float)},
                                       {"ptr", sizeof(int *)},
                                       {"arr", 0},
                                       {"func", 0},
                                       {"block", 0}};
