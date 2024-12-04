/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

#include "ass5_21CS10016_21CS30050_translator.h"

#include <bits/stdc++.h>

using namespace std;

/*
  Declaration of global variables for storing essential data.
*/
basicType bt; // Instantiate the basicType class, which holds basic type information.

// Data structures for storage
symtable *globalST;        // Pointer to the Global Symbol Table
symtable *parent_ST;           // Pointer to the Parent Symbol Table
symtable *ST;              // Pointer to the Current Symbol Table
quadArray Q;               // Array for storing intermediate code (quads)
sym *currSymbolPtr;        // Pointer to the current symbol
vector<label> label_store; // Vector for label storage

// Utility variables
string variable_type;       // Variable to keep track of the latest found data type
long long table_count; // Variable for counting the number of tables
string loop_name;      // Variable for storing the name of the current loop
int lineno = 1;        // Variable for tracking the current line number

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
    val = "-";                                         // Initial value is not yet defined.
    nested = NULL;                                     // No nested symbol tables attached.
    isItFunction = false;                              // Indicates if the current entry is a function.
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

/*
    Lookup a symbol in the symbol table, whether it exists or not.
    If not found, it will recursively search in its parent tables
    and create a new symbol if not found in the base symbol table.
*/
sym *symtable::lookup(string name)
{
    sym *symbol; // Declare a pointer to the symbol.

    // Iterate over the symbols in the current symbol table.
    for (auto &it : symbols)
    {
        if (it.name == name)
        {
            return &it; // Return the symbol if found.
        }
    }

    sym *ptr = NULL; // Declare a pointer for recursive lookup in parent tables.

    // Look up recursively in the parent symbol table, if it exists.
    if (this->parent)
    {
        ptr = this->parent->lookup(name);
    }

    // If the symbol is not found in the base symbol table and parent,
    // create a new symbol and return its address.
    if (ST == this && !ptr)
    {
        symbol = new sym(name);
        symbols.push_back(*symbol); // Add the symbol to the table.
        return &symbols.back();     // Return the symbol.
    }
    else if (ptr)
    {
        // Otherwise, if found in a parent table, return the existing symbol's address.
        return ptr;
    }

    return NULL; // Return NULL if the symbol is not found in any table.
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
    Utility function for printing the symbol table with proper indentation.
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
        cout << symbol.name;                         // Print the name of the symbol
        Add_Space(27 - symbol.name.length()); // Align the name column
        cout << "|";
        Add_Space(2);
        // Use PrintType to print the type of the symbol entry, and if it's a function, print "function"
        string typeString = (symbol.isItFunction) ? "function" : printType(symbol.type);
        cout << typeString;                         // Print the type of the symbol
        Add_Space(21 - typeString.length()); // Align the type column
        cout << "|";
        Add_Space(2);

        cout << symbol.size;                                    // Print the size of the symbol
        Add_Space(13 - to_string(symbol.size).length()); // Align the size column
        cout << "|";
        Add_Space(2);
        cout << symbol.offset;                                    // Print the offset of the symbol
        Add_Space(13 - to_string(symbol.offset).length()); // Align the offset column
        cout << "|";
        Add_Space(2);
        // Print all the required information
        cout << symbol.val;                         // Print the initial value of the symbol
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
    for (auto &table : nestedTables)
    {
        table->print(); // Recursively print nested symbol tables
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

/*
    Utility function to print quads (three address codes).
    It prints the details of a quad with appropriate formatting,
    identifying the type of operation and printing accordingly.
*/
void quad::print()
{
    int next_instr = 0;

    // Binary Assignment Instruction
    vector<string> binary_ops = {"+", "-", "*", "/", "%", "|", "^", "&"};
    for (auto check : binary_ops)
    {
        if (op == check)
        {
            type1(); // Handle binary assignment operation
            cout << '\n';
            return;
        }
    }

    // Relational operators | Conditional Jump Instruction
    vector<string> relational_ops = {"==", "!=", "<=", "<", ">", ">="};
    for (auto check : relational_ops)
    {
        if (op == check)
        {
            type2(); // Handle relational operations
            cout << '\n';
            return;
        }
    }

    // Unconditional Jump Instruction
    if (op == "goto")
    {
        cout << "goto " << res;
    }

    // Shift operators | Binary Assignment Instruction
    else if (op == ">>")
    {
        type1(); // Handle right shift operation
    }
    else if (op == "<<")
    {
        type1(); // Handle left shift operation
    }

    // Assignment operator | Copy Assignment Instruction
    else if (op == "=")
    {
        cout << res << " = " << arg1; // Handle copy assignment
    }

    // Assignment + operation | Unary Assignment Instruction
    else if (op == "=&")
    {
        cout << res << " = &" << arg1; // Handle reference assignment
    }
    else if (op == "=*")
    {
        cout << res << " = *" << arg1; // Handle pointer assignment
    }
    else if (op == "*=")
    {
        cout << "*" << res << " = " << arg1; // Handle multiplication assignment
    }
    else if (op == "uminus")
    {
        cout << res << " = -" << arg1; // Handle unary minus operation
    }
    else if (op == "~")
    {
        cout << res << " = ~" << arg1; // Handle bitwise NOT operation
    }
    else if (op == "!")
    {
        cout << res << " = !" << arg1; // Handle logical NOT operation
    }

    // Other operators
    // Indexed Copy Instruction
    else if (op == "=[]")
    {
        cout << res << " = " << arg1 << "[" << arg2 << "]"; // Handle indexed copy assignment
    }
    else if (op == "[]=")
    {
        cout << res << "[" << arg1 << "]"
             << " = " << arg2; // Handle indexed assignment
    }
    // Return Value
    else if (op == "return")
    {
        cout << "return " << res; // Handle return statement
    }
    // Procedure call
    else if (op == "param")
    {
        cout << "param " << res; // Handle parameter passing
    }
    else if (op == "call")
    {
        cout << res << " = "
             << "call " << arg1 << ", " << arg2; // Handle function call
    }
    else if (op == "label")
    {
        cout << res << ": "; // Handle label definition
    }
    else
    {
        cout << "Operator not found: " << op; // Handle unrecognized operator
    }
    cout << '\n';
}

// For printing quads with binary ops
void quad::type1()
{
    cout << res << " = " << arg1 << " " << op << " " << arg2;
}

// For printing quads with relational ops and jumps
void quad::type2()
{
    cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << res;
}

/*
    The main utility function for printing quads
    i.e. all the three address codes
*/

void quadArray::print()
{
    // This function prints the Three-Address Code (TAC) stored in the quad array with proper formatting.

    cout << string(75, '/') << string(75, '\\') << '\n'; // Print a line of slashes for visual separation.
    cout << "THREE ADDRESS CODE (TAC): " << '\n';        // Header for the TAC section.
    cout << string(150, '=') << '\n';                    // Print a line of equal signs for a visual separator.

    int j = 0; // Initialize a counter for quad indices.

    // Print all the stored quads in the Array with proper indentation.
    for (auto &it : Array)
    {
        if (it.op == "label")
        {
            // If the operation is a label, add a new line, print the quad's index, and then the label.
            cout << '\n'
                 << j << ": ";
            it.print();
        }
        else
        {
            // For other operations, print the quad's index, indent with spaces, and then print the quad.
            cout << j << ": ";
            Add_Space(4);
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
    The `gentemp` function generates a new temporary symbol in the current symbol table
    and returns a pointer to the current entry.
*/
sym *gentemp(symboltype *t, string str_new)
{
    // Generate a temporary symbol name with a unique identifier
    string tmp_name = "t_" + INT2STRING(ST->count++);

    // Create a new symbol with the generated name
    sym *s = new sym(tmp_name);

    // Set the type of the symbol to the provided 't'
    s->type = t;

    // Compute and set the size of the symbol based on its type
    s->size = computeSize(t);

    // Set the initial value of the symbol (if provided)
    s->val = str_new;

    // Add the symbol to the current symbol table's list of symbols
    ST->symbols.push_back(*s);

    // Return a pointer to the newly created symbol
    return &ST->symbols.back();
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

/*
    A utility function for changing the current symbol table
*/
void changeTable(symtable *newtable)
{
    // Set the current symbol table to the provided newtable
    ST = newtable;
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

    return -1; // Returning -1 indicates an error or unknown type.
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
        string str = INT2STRING(t->width); // Recursive for arrays - includes array size.
        return "arr(" + str + "," + printType(t->arrtype) + ")"; // Format the type as "arr(size, element_type)".
    }
    else if (basicType::getSize.count(t->type))
        return t->type; // If it's a basic type (e.g., int, char), simply return the type.

    return "NA"; // If the type is not recognized, return "NA" (Not Available) to indicate an error.
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

int main()
{
    // Clear the label table
    label_store.clear(); // Clears the label table to start with an empty slate.

    // Initialize the count of nested symbol tables
    table_count = 0; // Sets the count of nested symbol tables to zero at the beginning.

    // Create the Global Symbol Table
    globalST = new symtable("global"); // Creates the Global Symbol Table with the name "global".

    // Set the current symbol table to the Global Symbol Table
    ST = globalST; // Initially, the current symbol table is set to the Global Symbol Table.

    // Set the parent symbol table to null
    parent_ST = NULL; // At the beginning, there is no parent symbol table.

    // Initialize loop_name
    loop_name = ""; // Initializes the variable used for loop labels to an empty string.

    if (yyparse())
    {
        cout << "Parsing Failed\n"; // Display an error message if the parsing process fails.
    }
    else
    {
        // Update the global Symbol Table
        globalST->update(); // Update the Global Symbol Table, typically used after parsing is successful.

        // Print three address codes
        cout << "\n";
        Q.print(); // Print the generated three-address codes for the program.

        // Print all Symbol Tables
        cout << "\nSymbol Tables:\n"; // Indicates the start of symbol table printing.
        cout << string(150, '=') << '\n'; // Creates a line of '=' characters for visual separation.
        globalST->print(); // Prints the contents of all symbol tables.
    }
};

