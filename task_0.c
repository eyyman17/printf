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

void handle_char(va_list args, int *num)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    (*num)++;
}

void handle_percent(int *num)
{
    write(1, "%", 1);
    (*num)++;
}

int _format(const char *format, va_list args, int *num)
{
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
                handle_char(args, num);
            else if (*format == 's')
	    {
		    str = va_arg(args, char *);
		    handle_string(str, num);
	    }
            else if (*format == '%')
                handle_percent(num);
            else
            {
                handle_percent(num);
                write(1, format, 1);
                (*num)++;
            }
        }
        format++;
    }
    return 0;
}
