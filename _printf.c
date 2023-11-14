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

	_format(format, args, &num);


	va_end(args);
	return (num);
}
