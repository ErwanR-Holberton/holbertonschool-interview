#include <stdio.h>

int is_palindrome(unsigned long n)
{
	unsigned long len = 1, div = 1, div2 = 1;
	while (n / div > 9)
	{
		div *= 10;
		len++;
	}

	while (div > div2)
	{
		if (n / div % 10 != n / div2 % 10)
			return 0;

		div /= 10;
		div2 *= 10;
	}
	return 1;
}
