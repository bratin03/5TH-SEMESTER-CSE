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

float waste_float_d = 2.3;
char waste_char1;
int waste_int1, waste_int2;
int a = 4, *p, b;

int main()
{
	int itr = 1;
	do
	{
		printStr("Entered for iteration ");
		printInt(itr++);
		printStr("\n");
	} while (itr < 10);

	{
		int w = 10;
		printStr("\nScope 1: ");
		printInt(w);

		{
			int w = 2;
			printStr("\nScope 2: ");
			printInt(w);

			{
				int w = 3;
				if (w == 3)
				{
					printStr("\nw==3\n");
					w = 4;
				}
				printStr("\nScope 3: ");
				printInt(w);
				printStr("\n");
			}
		}
	}
	return 0;
}