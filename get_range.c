#include "main.h"

/**
 * get_range - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @ap: list of arguments.
 *
 * Return: range.
 */
int get_range(const char *format, int *i, va_list ap)
{
	int x;
	int range = 0;

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		if (a_number(format[x]))
		{
			range *= 10;
			range += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			range = va_arg(ap, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (range);
}
