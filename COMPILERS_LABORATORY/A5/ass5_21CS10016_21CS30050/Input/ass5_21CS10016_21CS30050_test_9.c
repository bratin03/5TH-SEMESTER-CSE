/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void find_pythagorean_triples(int limit, int triples[100][3])
{
    int count = 0;
    int a, b, c;
    for (a = 1; a < limit; a++)
    {
        for (b = a + 1; b < limit; b++)
        {
            for (c = b + 1; c < limit; c++)
            {
                if (a * a + b * b == c * c)
                {
                    if (count < limit)
                    {
                        triples[count][0] = a;
                        triples[count][1] = b;
                        triples[count][2] = c;
                        count++;
                    }
                }
            }
        }
    }
}

int main()
{
    int limit = 30;
    int triples[100][3];

    find_pythagorean_triples(limit, triples);

    return 0;
}
