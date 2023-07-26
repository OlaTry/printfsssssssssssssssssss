#include "main.h"

/**
 * get_tuning - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Tuning.
 */
int get_tuning(const char *format, int *i, va_list list)
{
	int x = *i + 1;
	int tuning = -1;

	if (format[x] != '.')
		return (tuning);

	tuning = 0;

	for (x += 1; format[x] != '\0'; x++)
	{
		if (a_number(format[x]))
		{
			tuning *= 10;
			tuning += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			tuning = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = x - 1;

	return (tuning);
}
