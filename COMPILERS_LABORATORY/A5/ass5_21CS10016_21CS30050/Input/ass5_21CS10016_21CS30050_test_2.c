/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int knapsack(int W, int wt[10], int val[10], int n)
{
	int i, w;
	int K[105][10005];

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	int val[3];
	int wt[3];
	val[0] = 60;
	val[1] = 100;
	val[2] = 120;
	wt[0] = 10;
	wt[1] = 20;
	wt[2] = 30;
	int W = 50;
	int n = 3;

	int result = knapsack(W, wt, val, n);

	return 0;
}
