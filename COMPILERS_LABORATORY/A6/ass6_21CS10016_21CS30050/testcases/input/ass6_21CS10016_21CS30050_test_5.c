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
  printStr("Testing Conditional Jumps\n");
  int x = 123;
  printStr("x = ");
  printInt(x);
  printStr("\n");
  if (x == 123)
  {
    printStr("x == 123\n");
    printStr("Success \n");
  }
  if (x != 123)
  {
    printStr("x!=123\n");
    printStr("Fail\n");
  }
  else if (x > 100 && x < 150)
  {
    printStr("x > 100 && x < 150 \n");
    printStr("Success \n");
  }
  else
  {
    printStr("Fail\n");
  }

  if (x > 100 || x < 50)
  {
    printStr("x > 100 || x < 50 \n");
    printStr("Success \n");
  }
  else
  {
    printStr("Fail\n");
  }

  if (x > 1000 || x == 200)
  {
    printStr("x > 1000 || x == 200 \n");
    printStr("Fail\n");
  }
  else if ((x % 3) != 0)
  {
    printStr("(x % 3) != 0 \n");
    printStr("Fail\n");
  }
  else if (x)
  {
    printStr("Success\n");
  }
  else
  {
    printStr("Fail\n");
  }
  return 0;
}