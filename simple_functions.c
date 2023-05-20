#include "shell.h"

/**
 * inter - true if shell is interactive
 * @info: struct address
 *
 * Return: 1 for interactive mode and 0 if not
 */

int inter(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * for_delim - checks for delimeted characters
 * @c: character to check
 * @delim: delimeter string
 * Return: 1 for successful and 0 otherwise
 */

int for_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @i: The character to input
 * Return: 1 if i is alphabetic, 0 otherwise
 */

int _isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * str_conv - converts string to integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int str_conv(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
