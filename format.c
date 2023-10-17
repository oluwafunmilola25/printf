#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the resulting output
 */

int _printf(const char *format, ...)
{
	va_list output;
	int character = 0;
	char *str;
	char c;
	

	if (format == NULL)
	{
		return (-1);
	}

	va_start(output, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, &(*format), 1);
			character++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return 0;
			
			if (*format == 'c')
			{
				c = va_arg(output, int);
				write(1, &c, 1);
				character++;
			}
			else if (*format == 's')
			{
				str = va_arg(output, char *);
				write(1, str, strlen(str));
				character++;
			}
			else if (*format == '%')
			{
				write(1, &(*format), 1);
				character++;
			}
		}
		format++;
	}
	va_end(output);

	return (character);
}
