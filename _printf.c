#include "main.h"
#include <stdlib.h>
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
			char *numStr;

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
				case 'd':
            			case 'i':
            				{
                				int num = va_arg(args, int);
						int digits = num_digits(num);
                				char *buffer = (char *)malloc((digits + 1) * sizeof(char));

                                                if (buffer == NULL)
                                                {
                                                    va_end(args);
                                                    return (-1);
						}
						int_to_str(num, buffer, digits + 1);

                				numStr = buffer;
                				
						while (*numStr != '\0')
                				{
                    					count += _putchar(*numStr);
                    					numStr++;
                				}
                                                free(buffer);
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
