/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void foo(int i);

int main()
{
    // Checking different types of rules
    int a = 2;
    int *ptr = &a;
    int **ptr2 = &ptr;
    float b = 3.0;
    a = (int)b;
    b = (float)a;
    char c1 = 'a';
    float float_arr_2d[20][50];  
    a=b;
}

void foo(int i)
{
    int a = 2;
    i = i << a;
}