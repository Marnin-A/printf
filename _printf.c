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
<<<<<<< HEAD
	while (*format != '\0')
	{
		if (*format == '%')
=======

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
				return (-1);
	
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
>>>>>>> 8ced175d84bbb880845b9c6681fecb768609f3e1
		{
			char *numStr;

<<<<<<< HEAD
			format++;
			if (val == 'c')
			{
				_putchar(val);
				n++;
			}
			else if (val == 's')
			{
				const char *str = va_arg(args, const char *);

				while (*str != '\0')
				{
					_putchar(*str);
					n++;
					str++;
				}
			}
			else if (val == '%')
			{
				_putchar('%');
				n++;
			}
			else
			{
				return (-1);
=======
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
						int i, len = 0;

						if (str == NULL)
						{
							return (len);
						}
						else
						{
							len = strlen(str);

							for (i = 0; i < len; i++)
							{
							       	_putchar(str[i]);
								count++;
							}
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
>>>>>>> 8ced175d84bbb880845b9c6681fecb768609f3e1
			}
		}
		else
		{
			count += _putchar(*ptr);
		}
	}
	va_end(args);
<<<<<<< HEAD
	return (n);
=======
	return count;
>>>>>>> 8ced175d84bbb880845b9c6681fecb768609f3e1
}
