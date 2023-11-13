#include "main.h"

/**
 * _printf - custumized printf
 *
 * @format: format
 *
 * Return: Number of character printed
 **/

int _printf(const char *format, ...)
{
	char c;
	char *str;
	int num = 0;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			num++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				num++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				write(1, str, strlen(str));
				num += strlen(str);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				num++;
		}
		format++;
		}
	}

	va_end(args);
	return (num);
}
