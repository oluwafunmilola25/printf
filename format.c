#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: is a character string
 * Return: the resulting output
 */

int _printf(const char *format, ...)
{
	va_list output;
	int character = 0, i = 0;
	char *str;
	char c;

	va_start(output, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
		}
		if (format[i] == 'c')
		{
			c = va_arg(output, int);
			_putchar(c);
			character++;
		}
		else if (format[i] == 's')
		{
			str = va_arg(output, char *);
			write(1, str, strlen(str));
			character++;
		}
		else if (format[i] == '%')
		{
			_putchar('%');
			character++;
		}
		else
		{
			_putchar(format[i]);
			character++;
		}
		i++;
	}
	va_end(output);
	return (character);
}