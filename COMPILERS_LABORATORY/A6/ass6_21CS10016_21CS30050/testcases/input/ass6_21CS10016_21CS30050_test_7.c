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

int fib(int n)
{
    int ans;
    if (n <= 1)
        ans = n;
    else
        ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int main()
{
    int n;
    int ans;
    printStr("Program to print fibonacci numbers upto 40\n");
    for (n = 1; n <= 40; n++)
    {
        ans = fib(n);
        printStr("Fib(");
        printInt(n);
        printStr(") = ");
        printInt(ans);
        printStr("\n");
    }
    return 0;
}


