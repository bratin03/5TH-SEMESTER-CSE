/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

int is_prime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int sum_primes(int limit)
{
    int sum = 0;
    for (int i = 2; i <= limit; i++)
    {
        if (is_prime(i))
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int limit = 100; 
    int result = sum_primes(limit);
    return 0; 
}
