#include "main.h"

/**
 * good - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int good(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * attach - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int attach(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * a_number - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int a_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * csn - Casts a number to the specified size
 * @n: Number to be casted.
 * @s: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int csn(long int n, int s)
{
	if (s == S_LONG)
		return (n);
	else if (s == S_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * csu - Casts a number to the specified size
 * @n: Number to be casted
 * @s: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int csu(unsigned long int n, int s)
{
	if (s == S_LONG)
		return (n);
	else if (s == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
