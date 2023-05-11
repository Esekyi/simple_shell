#include "main.h"

/**
 * digit - checks if num is digit
 *
 * @c: parameter to be checked
 *
 * Return: returns 0 or 1
 */

int digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
