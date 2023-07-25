#include "main.h"

#include "main.h"

/**
 * get_all_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Banner:
 */
int get_all_flags(const char *format, int *i)
{
	int x;
	int y;
	int banner  = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[x] == FLAGS_CH[y])
			{
				banner  |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*i = x - 1;

	return (banner);
}
