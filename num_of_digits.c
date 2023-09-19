#include "main.h"

int num_digits(int num)
{
	int digits = 1;
	
	while (num / 10 != 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

