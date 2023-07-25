#include "main.h"

#include "main.h"

/**
 * get_length - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: length.
 */
int get_length(const char *format, int *i)
{
	int x = *i + 1, length = 0;

	if (format[x] == 'l')
		length = S_LONG;
	else if (format[x] == 'h')
		length = S_SHORT;

	if (length == 0)
		*i = x - 1;
	else
		*i = x;

	return (length);
}

