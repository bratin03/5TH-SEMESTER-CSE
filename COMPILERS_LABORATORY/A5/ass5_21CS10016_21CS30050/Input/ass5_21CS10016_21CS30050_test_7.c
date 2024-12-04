/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void maxSubArraySum(int a[8], int size)
{
    int max_so_far;
    max_so_far = -100;
    int max_ending_here;
    max_ending_here = 0;
    int start;
    start = 0;
    int end;
    end = 0;
    int s;
    s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
}

int main()
{
    int a[8];
    a[0] = -2;
    a[1] = -3;
    a[2] = 4;
    a[3] = -1;
    a[4] = -2;
    a[5] = 1;
    a[6] = 5;
    a[7] = 3;
    int n;
    n = 8;
    maxSubArraySum(a, n);
    return 0;
}
