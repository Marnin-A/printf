#include "main.h"
#include <stdarg.h>

/*
 * _printf - The fuction writes output to stdout,
 *  and returns the numbers of characters.
 *
 *  @format: is a character string composed of zero or more directives.
 *  @count: holds the number of charaters outputed.
 *
 */

int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;
	
	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					{
						count += _putchar(va_arg(args, int));
						break;
					}
				case 's':
					{
						const char *str = va_arg(args, const char *);
						while (*str != '\0')
						{
							count += _putchar(*str);
							str++;
						}
						break;
					}
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					break;
			}
		}
		else
		{
			count += _putchar(*ptr);
		}
	}
	va_end(args);
	return count;
}
