// This is a test file.
/*
Assignment-4
21CS10016-Bratin Mondal
21CS30050-Somya Kumar
*/

void foo1(int *restrict p1, const int p2, volatile int p3, ...);

int main()
{
  // Variable declarations and assignments
  unsigned long largeNumber = 123456789;
  short negShort = -16;
  float negativeFloat = -3.53;
  double smallDouble = 0.0299;
  _Bool boolValue = 0;
  double _Complex complexValue;
  double _Imaginary imaginaryValue;

  // Various mathematical operations
  largeNumber = sizeof(int);
  largeNumber = sizeof largeNumber;

  largeNumber *= largeNumber;
  largeNumber /= largeNumber;
  largeNumber %= largeNumber;

  largeNumber += (largeNumber -= largeNumber);
  largeNumber <<= (largeNumber >>= largeNumber);
  largeNumber &= largeNumber |= largeNumber ^= largeNumber;

  // Conditional statements
  if (negativeFloat < smallDouble)
  {
    negShort++;
  }
  else if (negativeFloat > smallDouble)
  {
    if (negShort >= largeNumber)
    {
      largeNumber++;
    }
  }
  else
  {
    if (negShort <= largeNumber)
    {
      negShort++;
    }
  }

  // Looping and control flow
  while (negShort--)
  {
    goto RANDOM_LOC;
  }

  for (;;)
  {
    for (int i = 0; i < 10; i++)
    {
      if (i == 1)
      {
        continue;
      }
    }
  }

  do
  {
    negShort++;
  } while (negShort < 0);

  // More mathematical operations
  int result1, result2, operand1, operand2, operand3, operand4, operand5, operand6;

  result1 = operand1 + operand2 - operand3 / operand4 * operand5 % operand6;
  result2 = operand2 << 2;
  result2 = result2 >> 2;

  // Function calls
  foo1(&result1, operand2, operand3);

  ms1.field = 3;
  ms2->field = 4;

  return 0;
}

// Custom function implementations
void foo1(int *restrict p1, const int p2, volatile int p3, ...)
{
  auto int localInt;
  register int registerInt;
  extern int externalInt;
  static int staticInt = 4;
}

// THE END