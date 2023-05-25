#include "shell.h"

/**
 * inter - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 if not
 */

int inter(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * for_delim - checks if character is a delimeter
 * @c: char to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
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
 * @c: character to input
 * Return: 1 if c is alphabetic and 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * str_conv - converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in string and converted number otherwise
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
