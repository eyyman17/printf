#include "main.h"

/**
 * handle_string - handles case of string
 * @str: string
 * @num: int
 *
 * Return: nothing
 **/

void handle_string(const char *str, int *num)
{
	if (str == NULL)
	{
		write(1, "(null)", sizeof("(null)") - 1);
		(*num) += 6;
	}
	else
	{
		write(1, str, strlen(str));
		(*num) += strlen(str);
	}
}


/**
 * _format - handles formatting of c, str and %
 *
 * @format: const char
 * @args: va_list
 * @num: pointer to int
 *
 * Return: 0
 **/

int _format(const char *format, va_list args, int *num)
{
	char c;
	char *str;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			(*num)++;
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
				(*num)++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				handle_string(str, num);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				(*num)++;
			}
		}
		format++;
	}
	return (0);
}
