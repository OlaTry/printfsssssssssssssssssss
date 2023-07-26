#include "main.h"

void stoop(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, res = 0, prch = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list ap;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				stoop(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			prch++;
		}
		else
		{
			stoop(buffer, &buff_ind);
			flags = get_all_flags(format, &i);
			width = get_range(format, &i, ap);
			precision = get_tuning(format, &i, ap);
			size = get_length(format, &i);
			++i;
			res = get_carbon(format, &i, ap, buffer,
				flags, width, precision, size);
			if (res == -1)
				return (-1);
			prch += res;
		}
	}

	stoop(buffer, &buff_ind);

	va_end(ap);

	return (prch);
}

/**
 * stoop - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void stoop(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

