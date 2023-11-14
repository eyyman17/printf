#include "main.h"
/**
 * print_int - prints integer
 * @args: argument
 * Return: nbr of bytes
 */
int print_int(va_list args, int *num)
{
	int n = va_arg(args, int);
	int m, k = 1, i = 0, j, lastd = n % 10;

	n = n / 10;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		lastd = -lastd;
		i++;
	}
	m = n;
	while (m / 10 != 0)
	{
		m = m / 10;
		k = k * 10;
	}
	while (k > 0)
	{
		j = n / k;
		_putchar(j + '0');
		n = n - (j * k);
		k = k / 10;
		i++;
	}
	*num += i;
	_putchar(lastd + '0');
	return (0);
}
