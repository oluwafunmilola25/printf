#include "main.h"

/**
 * _printf - prints output according to the specifiers
 * @format: parameter to use
 * Return: output
*/

int _printf(const char *format, ...)
{
	va_list output;
	int character = 0;
	int num, count = 0, alpha;
	char c;

	va_start(output, format);
	while (*format)
	{
		if (*format != '%')
			character++;
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format =='%')
			{
				write(1, format, 1);
				character++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(output, int);
				if (num < 0)
					c = '-';
				write(1, &c, 1);
				num = -num;
				character++;
			}
			alpha = num;
			while (alpha)
			{
				alpha /= 10;
				count++;
			}
		}
		format++;
	}
	va_end(output);
	return (character);
}
