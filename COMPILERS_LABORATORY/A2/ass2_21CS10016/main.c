/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include "myl.h" // Include the custom header file "myl.h"
int main()
{
    char *newline = "\n"; // String containing a newline character

    // Print a string using the printStr function
    char *string1 = "\nBratin Mondal\n21CS10016\nCompilers Laboratory\nAssignment-2\nWelcome to this main.c file. This is a test line.\n(Printed by printStr function)\n";
    printStr(string1);
    int key = 1; // key to continue loop
    while (key == 1)
    {
        // Print a prompt for the user to enter an integer
        char *string2 = "Enter Integer:(Will be read by readInt function)\n";
        printStr(string2);

        int intinput;
        if (readInt(&intinput))
        {
            // Display the entered integer using the printInt function
            char *string3 = "The integer you have entered is:(Displayed by printInt function)\n";
            printStr(string3);
            printInt(intinput);
            printStr(newline);
        }
        else
        {
            // Display an error message if reading the integer failed
            char *string4 = "ERROR!\nreadInt could not read the input number.\n";
            printStr(string4);
        }

        // Print a prompt for the user to enter a floating-point number
        char *string5 = "Enter Floating point number:(Will be read by readFlt function)\n";
        printStr(string5);

        float floatinput;
        if (readFlt(&floatinput))
        {
            // Display the entered float using the printFlt function
            char *string6 = "The float you have entered is:(Displayed by printFlt function)\n";
            printStr(string6);
            printFlt(floatinput);
            printStr(newline);
        }
        else
        {
            // Display an error message if reading the float failed
            char *string7 = "ERROR!\nreadFlt could not read the input number.\n";
            printStr(string7);
        }

        char *string8 = "Enter 1 to continue or 0 to exit:\n"; // Prompt asking if to contiune loop
        printStr(string8);
        readInt(&key);
    }

    return 0; // Return 0 to indicate successful program execution
}
