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

int min(int x, int y)
{
	int ans;
	ans = x > y ? y : x;
	return ans;
}

int max(int x, int y)
{
	int ans;
	ans = x < y ? y : x;
	return ans;
}

int gcdAlgorithm(int a, int b)
{
	if (a == 0)
		return b;
	else
		return gcdAlgorithm(b % a, a);
}

int guessing_game(int a, int b)
{
	int count = 1;
	int min_num = min(a, b);
	int max_num = max(a, b);
	int gcd = gcdAlgorithm(min_num, max_num);
	int guess = min_num + gcd;
	int user_input;
	printStr("Guess a number between ");
	printInt(min_num);
	printStr(" and ");
	printInt(max_num);
	printStr(":\n");
	readInt(&user_input);
	while (user_input != guess)
	{
		if (user_input < guess)
		{
			printStr("Too low! Guess again:\n");
			readInt(&user_input);
		}
		else
		{
			printStr("Too high! Guess again:\n");
			readInt(&user_input);
		}
		count++;
	}
	return count;
}

int main()
{
	int x, y;
	printStr("\nEnter a number(Lower Bound): ");
	readInt(&x);
	printStr("\nEnter a number(Upper Bound): ");
	readInt(&y);
	int attempts = guessing_game(x, y);
	printStr("You guessed the number in ");
	printInt(attempts);
	printStr(" attempt(s)!\n");


	return 0;
}
