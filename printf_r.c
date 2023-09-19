#include "main.h"
#include <stddef.h>

/**
 * printf_r - function that prints a string in reverse
 * @val: is a point the the string to be reversed
 *
 * Return: the length of the string
 */
int printf_r(char* val)
{

	char *s = val;
	int i;
	int j = 0;

	if (s == NULL)
		return (0);
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}
