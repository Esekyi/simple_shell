#include "shell.h"

/**
 * _strcpy - check code
 * @dest_str: string destination
 * @src_str: string source
 * Description: This function copies a string
 * Return: points to destination
 */

char *_strcpy(char *dest_str, char *src_str)
{
	int itr = 0;

	if (dest_str == src_str || src_str == 0)
		return (dest_str);

	while (src_str[itr])
	{
		dest_str[itr] = src_str[itr];
		itr++;
	}
	dest_str[itr] = 0;

	return (dest_str);
}

/**
 * _strdup - check code
 * @str_dup: string to duplicate
 * Description: This function duplicates a string
 * Return: pointer to the duplicate string
 */

char *_strdup(const char *str_dup)
{
	int len = 0;
	char *ret_val;

	if (str_dup == NULL)
		return (NULL);

	while (*str_dup++)
		len++;
	ret_val = malloc(sizeof(char) * (len + 1));

	if (!ret_val)
		return (NULL);

	for (len++; len--;)
		ret_val[len] = *--str_dup;

	return (ret_val);
}

/**
 * _puts - check code
 * @str: string to write on stdout
 * Description: This function prints an input string
 * Return: Nothing
 */

void _puts(char *str_val)
{
	int itr = 0;

	if (!str_val)
		return;

	while (str_val[itr] != '\0')
	{
		_putchar(str_val[itr]);
		itr++;
	}
}


/**
 * _putchar - check code
 * @c: The char to display
 * Description: displays the char c to stdout
 * Return: 1 (success)
 */

int _putchar(char c)
{
	static int itr;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || itr >= WRITE_BUF_SIZE)
	{
		write(1, buf, itr);
		itr = 0;
	}

	if (c != BUF_FLUSH)
		buf[itr++] = c;

	return (1);
}
