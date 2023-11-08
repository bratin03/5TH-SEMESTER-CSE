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

int min_3(int x, int y, int z)
{
	int ans;
	ans = min(x, y);
	ans = min(ans, z);
	return ans;
}

int max_3(int x, int y, int z)
{
	int ans;
	ans = max(x, y);
	ans = max(ans, z);
	return ans;
}

int max_4(int x, int y, int z, int w)
{
	int ans;
	ans = max(x, y);
	ans = max(ans, z);
	ans = max(ans, w);
	return ans;
}

int min_4(int x, int y, int z, int w)
{
	int ans;
	ans = min(x, y);
	ans = min(ans, z);
	ans = min(ans, w);
	return ans;
}

int absolute_val(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}


int main()
{
	int x = 729;
	int y = -1296;
	int z = 1000;

	printStr("\nTesting the absolute_val function\n");
	int ans1 = absolute_val(x);
	printStr("absolute_val(");
	printInt(x);
	printStr(") = ");
	printInt(ans1);
	printStr("\n");

	int ans2 = absolute_val(y);
	printStr("absolute_val(");
	printInt(y);
	printStr(") = ");
	printInt(ans2);
	printStr("\n");

	int ans3 = min(x, y);
	printStr("Testing the min function\n");
	printStr("Min(");
	printInt(x);
	printStr(", ");
	printInt(y);
	printStr(") = ");
	printInt(ans3);
	printStr("\n");

	int ans4 = max(x, y);
	printStr("Testing the max function\n");
	printStr("Max(");
	printInt(x);
	printStr(", ");
	printInt(y);
	printStr(") = ");
	printInt(ans4);
	printStr("\n");

	int ans5 = min_3(x, y, z);
	printStr("Testing the min_3 function\n");
	printStr("Min_3(");
	printInt(x);
	printStr(", ");
	printInt(y);
	printStr(", ");
	printInt(z);
	printStr(") = ");
	printInt(ans5);
	printStr("\n");

	int ans6 = max_3(x, y, z);
	printStr("Testing the max_3 function\n");
	printStr("Max_3(");
	printInt(x);
	printStr(", ");
	printInt(y);
	printStr(", ");
	printInt(z);
	printStr(") = ");
	printInt(ans6);
	printStr("\n");

	int a;
	a=313;
	int ans7 = min_4(x, y, z, a);
	printStr("Testing the min_4 function\n");
	printStr("Min_4(");
	printInt(x);
	printStr(", ");
	printInt(y);
	printStr(", ");
	printInt(z);
	printStr(", ");
	printInt(a);
	printStr(") = ");
	printInt(ans7);
	printStr("\n");

	int ans8 = max_4(x, y, z, a);
	printStr("Testing the max_4 function\n");
	printStr("Max_4(");
	printInt(x);
	printStr(", ");
	printInt(y);
	printStr(", ");
	printInt(z);
	printStr(", ");
	printInt(a);
	printStr(") = ");
	printInt(ans8);
	printStr("\n");



	return 0;
}
