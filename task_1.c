#include "main.h"
/**
 * print_int - prints integer
 * @args: argument
 * @num: count
 * Return: nbr of bytes
 */
int print_int(va_list args, int *num)
{
	int n = va_arg(args, int);
	int m, k = 1, i = 0, j;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		*num += 11;
		return 0;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
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
	return 0;
}
