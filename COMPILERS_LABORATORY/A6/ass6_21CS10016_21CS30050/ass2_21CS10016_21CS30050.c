/*
Assignment Number 6

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

// Including the header file "myl.h"
#include "myl.h"

// Maximum length for strings, integers, and floats
const int maxlen_str = 10001;
const int maxlen_int = 101;
const int maxlen_float = 101;

// Function to print a string
int printStr(char *str)
{
    int idx = 0;
    char str_print[maxlen_str];

    // Copy the input string into a local buffer
    while (str[idx] != '\0')
    {
        str_print[idx] = str[idx];
        idx++;
    }

    // Using inline assembly to invoke the syscall for printing
    __asm__ __volatile__(
        "movl $1, %%eax \n\t" // Set syscall number (1 for sys_write)
        "movq $1, %%rdi \n\t" // Set file descriptor (1 for stdout)
        "syscall \n\t"        // Invoke the syscall
        :
        : "S"(str_print), "d"(idx) // Inputs (source string and length)
    );

    return idx; // Return number of characters printed
}

// Function to read an integer from standard input
int readInt(int *n)
{
    char int_store[maxlen_int]; // Buffer to store input characters

    // Using inline assembly to invoke the syscall for reading
    __asm__ __volatile__(
        "movl $0, %%eax \n\t" // Set syscall number (0 for sys_read)
        "movq $0, %%rdi \n\t" // Set file descriptor (0 for stdin)
        "syscall \n\t"        // Invoke the syscall
        :
        : "S"(int_store), "d"(sizeof(int_store)) // Inputs (destination buffer and buffer size)
    );

    int isneg = 0; // Flag to indicate negative number
    int num = 0;   // Final integer value
    int idx = 0;   // Index for traversing input buffer

    // If only '-' is entered
    if (int_store[0] == '-' && (int_store[1] == ' ' || int_store[1] == '\n' || int_store[1] == '\t'))
    {
        return ERR;
    }

    // Check for negative sign at the beginning of the input
    if (int_store[idx] == '-')
    {
        isneg = 1;
        idx++;
    }

    // Parse digits from input until a non-digit character is encountered
    while (int_store[idx] != ' ' && int_store[idx] != '\n' && int_store[idx] != '\t' && idx < maxlen_int)
    {
        int digit = int_store[idx++] - '0'; // Convert ASCII digit to integer
        if (digit < 0 || digit > 9)
        {
            return ERR; // Return an error code if non-digit character encountered
        }
        num = num * 10 + digit; // Accumulate digits to form the number
    }

    num = (isneg == 1) ? -num : num; // Apply negative sign if needed
    *n = num;                        // Store the final integer value in the provided pointer

    return OK; // Return success code
}

// Function to print an integer
int printInt(int n)
{
    char int_store[maxlen_int]; // Buffer to store characters representing the integer
    int idx = 0;                // Index for storing digits in the buffer
    if (n == 0)
    {
        int_store[0] = '0'; // Handling the special case where the number is 0
        idx = 1;
    }
    else
    {

        int isneg = 0; // Flag to indicate if the number is negative

        if (n < 0)
        {
            isneg = 1; // Mark the number as negative
            n = -n;    // Convert the number to positive for processing
        }

        // Extract individual digits and store them in reverse order
        while (n)
        {
            char digit = (n % 10) + '0'; // Convert the digit to its ASCII representation
            if (digit < '0' || digit > '9' || idx > maxlen_int)
            {
                return ERR; // Return an error code if an invalid digit or buffer overflow occurs
            }
            int_store[idx++] = digit; // Store the digit in the buffer
            n /= 10;                  // Move to the next digit
        }

        if (isneg)
        {
            int_store[idx++] = '-'; // Add negative sign if needed
        }

        // Reverse the order of digits in the buffer
        for (int j = 0; j < idx - 1 - j; j++)
        {
            char temp = int_store[j];
            int_store[j] = int_store[idx - 1 - j];
            int_store[idx - 1 - j] = temp;
        }
    }
    // Using inline assembly to invoke the syscall for printing
    __asm__ __volatile__(
        "movl $1, %%eax \n\t" // Set syscall number (1 for sys_write)
        "movq $1, %%rdi \n\t" // Set file descriptor (1 for stdout)
        "syscall \n\t"        // Invoke the syscall
        :
        : "S"(int_store), "d"(idx) // Inputs (source buffer and buffer size)
    );

    // Return the number of characters printed, return 1 for the special case when the input integer is 0
    return (idx == 0) ? 1 : idx;
}

// Function to read a float from standard input
int readFlt(float *f)
{
    char float_store[maxlen_float]; // Buffer to store input characters

    // Using inline assembly to invoke the syscall for reading
    __asm__ __volatile__(
        "movl $0, %%eax \n\t" // Set syscall number (0 for sys_read)
        "movq $0, %%rdi \n\t" // Set file descriptor (0 for stdin)
        "syscall \n\t"        // Invoke the syscall
        :
        : "S"(float_store), "d"(sizeof(float_store)) // Inputs (destination buffer and buffer size)
    );

    int isneg = 0;     // Flag to indicate if the number is negative
    float num = 0;     // Final float value
    int idx = 0;       // Index for traversing input buffer
    int decindex = -1; // Index where the decimal point is found in the input

    // If only '-' is entered
    if (float_store[0] == '-' && (float_store[1] == ' ' || float_store[1] == '\n' || float_store[1] == '\t'))
    {
        return ERR;
    }

    // Check for negative sign at the beginning of the input
    if (float_store[idx] == '-')
    {
        isneg = 1; // Mark the number as negative
        idx++;
    }

    // Process the input characters to build the float value
    while (float_store[idx] != ' ' && float_store[idx] != '\n' && float_store[idx] != '\t' && idx < maxlen_float)
    {
        char digit_char = float_store[idx];
        if (digit_char == '.')
        {
            // Handle the decimal point
            if (decindex != -1)
            {
                return ERR; // Return an error if there's already a decimal point
            }
            decindex = idx++; // Mark the decimal point and move to the next character
            continue;
        }
        if (digit_char < '0' || digit_char > '9')
        {
            return ERR; // Return an error if an invalid digit is encountered
        }
        // Convert character digit to actual digit and update the float value
        num = num * 10 + (digit_char - '0');
        idx++;
    }

    // Calculate the divisor for the decimal part
    float divider = 1;
    int times_divide;
    if (decindex != -1)
    {
        for (times_divide = 0; times_divide < idx - decindex - 1; times_divide++)
        {
            divider *= 10;
        }
    }

    // Divide the integer part by the divisor to get the final float value

    // Apply negative sign if the number is negative
    if (isneg)
    {
        num *= -1;
    }

    num /= divider;

    // Set the float value in the provided pointer and return success code
    *f = num;
    return OK;
}

// Function to print a floating-point number as a string
int printFlt(float f)
{
    char float_store[maxlen_float]; // Buffer to store characters representing the float
    int idx = 0;                    // Index for storing digits in the buffer
    // Handle special case where the number is 0
    if (f == 0)
    {
        float_store[0] = '0';
        idx = 1;
    }
    else
    {
        int isneg = 0; // Flag to indicate if the number is negative

        // Check if the number is negative
        if (f < 0)
        {
            isneg = 1; // Mark the number as negative
            f = -f;    // Convert the number to positive for processing
        }

        int f_int = (int)f;      // Integer part of the float
        float f_dec = f - f_int; // Decimal part of the float

        // Extract individual digits of the integer part and store them in reverse order
        while (f_int)
        {
            char digit = (f_int % 10) + '0'; // Convert the digit to its ASCII representation
            // Check for invalid digit or buffer overflow
            if (digit < '0' || digit > '9' || idx > maxlen_float)
            {
                return ERR; // Return an error code if an issue occurs
            }
            float_store[idx++] = digit; // Store the digit in the buffer
            f_int /= 10;                // Move to the next digit
        }

        if (f < 1)
        {
            float_store[idx++] = '0'; // Add a leading zero if the integer part is zero
        }

        // Add negative sign if the number is negative
        if (isneg)
        {
            float_store[idx++] = '-';
        }

        // Reverse the order of digits in the buffer
        for (int j = 0; j < idx - 1 - j; j++)
        {
            char temp = float_store[j];
            float_store[j] = float_store[idx - 1 - j];
            float_store[idx - 1 - j] = temp;
        }

        // Add a decimal point if the decimal part is not zero
        if (f_dec > 1e-9 || f_dec < -1e9)
        {
            float_store[idx++] = '.';
            int f_dec_to_int = (int)(1e6 * f_dec);
            int after_dec_digits[6];
            int arr_idx;

            // Extract individual digits of the decimal part and store them
            for (arr_idx = 5; arr_idx >= 0; arr_idx--)
            {
                after_dec_digits[arr_idx] = f_dec_to_int % 10;
                f_dec_to_int /= 10;
            }

            // Store decimal digits in the buffer
            for (arr_idx = 0; arr_idx < 6; arr_idx++)
            {
                float_store[idx++] = after_dec_digits[arr_idx] + '0';
            }
        }
    }
    // Using inline assembly to invoke the syscall for printing
    __asm__ __volatile__(
        "movl $1, %%eax \n\t" // Set syscall number (1 for sys_write)
        "movq $1, %%rdi \n\t" // Set file descriptor (1 for stdout)
        "syscall \n\t"        // Invoke the syscall
        :
        : "S"(float_store), "d"(idx) // Inputs (source buffer and buffer size)
    );

    // Return the number of characters printed,return 1 for the special case when the input float is 0
    return (idx == 0) ? 1 : idx;
}