/*
Assignment Number 6

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

int printStr(char *p);
int printInt(int n);
int readInt(int *eP);
int printFlt(float n);
int readFlt(float *eP);

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

int main()
{

    printStr("\nTesting GCD\n\n");

    printStr("Enter the first number: ");
    int x;
    readInt(&x);

    printStr("Enter the second number: ");
    int y;
    readInt(&y);

    int res = gcd(x, y);
    printStr("GCD of ");
    printInt(x);
    printStr(" and ");
    printInt(y);
    printStr(" is: ");
    printInt(res);
    printStr("\n\n");

    return 0;
}