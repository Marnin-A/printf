#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int n = 0;
	va_list args;

	va_start(args, format);

	while(*format != '\0')
	{
		if(*format == '%')
		{
			char val = (char)va_arg(args, int);

			format++;

			if(val == 'c')
			{
				_putchar(val);
				n++;
			}
			else if(val == 's')
			{
				const char *str = va_arg(args, const char *);

				while(*str != '\0')
				{
					_putchar(*str);
					n++;
					str++;
				}
			}
			else if(val == '%')
			{
				_putchar('%');
				n++;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			_putchar(*format);
			n++;
		}
		format++;
	}

	va_end(args);

	return n;
}
