/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void SieveOfEratosthenes(int n, int primeList[30])
{
    int prime[n + 1];
    for (int i = 0; i < n + 1; i++)
        prime[i] = 1;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == 1)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }
    int j = 0;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primeList[j++] = p;
}
int main()
{
    int n = 30;
    int primeList[30];
    SieveOfEratosthenes(n, primeList);
    return 0;
}
