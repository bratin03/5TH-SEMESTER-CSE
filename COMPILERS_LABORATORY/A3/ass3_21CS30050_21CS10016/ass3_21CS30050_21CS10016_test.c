/*
    Assignment - 3
    21CS10016 - Bratin Mondal
    21CS30050 - Somya Kumar
*/

// This is a test comment

// Define a macro for RANDNUM
#define RANDNUM (16 + 50)

/*

    This is another test comment

*/

// Define a structure struct_test
struct struct_test
{
    _Bool B;
    _Complex C;
    _Imaginary I;
    char CHARACTER;
    long LONG_VAR;
};

// Define an enum for COLOR
enum COLOR
{
    RED,
    BLUE,
    GREEN
};

// Define a union Union_unit_test
union Union_unit_test
{
    int int_test;
    char test_char;
    double test_double;
};

// Define a typedef for struct_test as st
typedef struct struct_test st;

// Declare a static int int_static
static int int_static;

// Define an inline function inline_func
inline int inline_func(int *restrict p)
{
    auto int auto_int = 1;
    register int register_int;
    extern int extern_int;
    volatile int volatile_int;
    return auto_int;
}

int main()
{
    // Declare and initialize variables
    int n1 = 4 * sizeof(int);
    int j = 1000;

    // Loop with nested loops
    for (int i = n1; i <= j && j >= 0; i++, j--)
    {
        for (int k = j; k < i * j; k *= 2)
        {
            double x = k;
            x /= j;
            x *= i;
            x += 12.23;
            x -= k;
            x = x ^ j; // XOR
        }

        // Perform operations on variable y
        float y = i;
        y |= j;
        y &= i;

        // Check if j is even
        if (j % 2 == 0)
        {
            printf("j = %d\n", j);
        }
        else
        {
            printf("Enter y:\n");
            scanf("%f", &y);
            y = i + (-y) / 2;
            int z = (int)y;
            z <<= 3;
            z -= y;
            z >>= 1;
        }

        n1 /= (i / j);
    }

    // Declare and initialize variables
    unsigned long vxyz = 98237123;
    signed short abcd = -23;
    const float pqrst = 0.456;
    char xyzab = '\t';
    int mnop = 15;

    double uvwx = 678.123;
    double ijkl = 67.892e3;
    float efgh = 0.5e-1;
    float klmn = 34.12e2;

    int qrst = mnop & abcd ? 2 : 1;

    // Print the value of vxyz
    printf("Initial ul: %lu\n", vxyz);

    // Declare a pointer to a struct RandomStruct
    struct RandomStruct *rstu;

    // Perform operations based on switch case
    switch (rstu->zzz)
    {
    case 2:
        xyz.n ^= xyz.n;
        xyz.n %= qrst;
        break;
    default:
        break;
    }

    // Declare and initialize variables
    double wxyz = 0.567;
    char abcde[] = "This is a string!";
    double ghijk = 123.789;

    // Perform operations in a loop
    do
    {
        abcd = ~abcd;
        abcd = abcd | abcd;
        if (abcd < 20 && abcd > 0)
            goto xyz_label;
    xyz_label:
        continue;
        abcd <<= 3;
        abcd >>= 2;
    } while (qrst != -1 || !mnop);

    // Declare and initialize a struct CustomStruct
    struct CustomStruct efg;
    efg.b = 2;
    efg.n = 25;

    qrst--;

    printf("Assignment 3.\n");

    return 0;
}