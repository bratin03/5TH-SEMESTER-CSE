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

int main()
{
	printStr("\nThis is for Integer\n");
	int int_a, int_b, int_c;
	int_a = 3;
	int_b = 6;
	int_c = 4;
	printStr("int_a = ");
	printInt(int_a);
	printStr("\nint_b = ");
	printInt(int_b);
	printStr("\nint_c = ");
	printInt(int_c);
	int_c++;
	printStr("\nc+;\n");
	printStr("int_c = ");
	printInt(int_c);
	printStr("\n");
	printStr("int_c = int_a + int_b\n");
	int_c = int_a + int_b;
	printStr("int_c = ");
	printInt(int_c);
	printStr("\n");
	printStr("int_c = -int_b\n");
	int_c = -int_b;
	printStr("int_c = ");
	printInt(int_c);
	printStr("\n");


	if (int_a == int_b)
	{
		printStr("int_a is equal to int_b\n");
	}
	else
	{
		printStr("int_a is not equal to int_b\n");
	}

	printStr("\nThis is for Float\n");
	float float_a, float_b, float_c;
	float_a = 3.0;
	float_b = 6.5;
	float_c = 4.0;
	printStr("float_a = ");
	printFlt(float_a);
	printStr("\nfloat_b = ");
	printFlt(float_b);
	printStr("\nfloat_c = ");
	printFlt(float_c);
	printStr("\n");
	printStr("float_c = float_a + float_b\n");
	float_c = float_a + float_b;
	printStr("float_c = ");
	printFlt(float_c);
	printStr("\n");
	printStr("float_c = float_a * float_b\n");
	float_c = float_a * float_b;
	printStr("float_c = ");
	printFlt(float_c);
	printStr("\n");
	printStr("float_c = float_a / float_b\n");
	float_c = float_a / float_b;
	printStr("float_c = ");
	printFlt(float_c);
	printStr("\n");
	printStr("float_c = float_a - float_b\n");
	float_c = float_a - float_b;
	printStr("float_c = ");
	printFlt(float_c);
	printStr("\n");
	printStr("float_c = -float_b\n");
	float_c = -float_b;
	printStr("float_c = ");
	printFlt(float_c);
	printStr("\n");
	
	return 0;
}