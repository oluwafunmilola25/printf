#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			if(*format == 'c')
			{
				char chr = (char) va_arg(args, int);
				putchar(chr);
			}
		}
		else
		{
			putchar(*format);
		}

		format++;
	}
	va_end(args);

	return (0);
}

int main(void)
{
	_printf("%c\n", 'A');
	printf("%c\n", 'A');
	return (0);
}
