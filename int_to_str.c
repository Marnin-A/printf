#include "main.h"

/*
 * int_to_str - converts an integer to a string.
 * @num: number to be converted.
 * @str: is a buffer that holds a the converted integers.
 * @i: is a counter
 */


void int_to_str(int num, char * str, int buffer_size)
{
	int i = 0, j;
	int is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do
	{
		if (i < buffer_size - 1)
		{
			str[i++] = num % 10 + '0';
			num /= 10;
		}
	} while (num > 0 && i < buffer_size - 1);
	
	if (is_negative && i < buffer_size - 1)
		str[i++] = '-';

	for (j = 0; j < i / 2; j++)
	{
		char temp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}

	str[i] = '\0';
	return;
}
