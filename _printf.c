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
	int num = 0;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num++;
		}
		else
		{
			_format(format, args, &num);
		}
		format++;
	}

	va_end(args);
	return (num);
}
