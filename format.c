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
			write(1, &c, 1);
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
			write(1, &format[i], 1);
			character++;
		}
		else
		{
			write(1, &format[i], 1);
			character++;
		}
		i++;
	}
	va_end(output);
	return (character);
}