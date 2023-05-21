#include "shell.h"

/**
 * inputs - prints an input string
 * @str: string to be printed
 *
 * Return: none
 */

void inputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		stputchar(str[a]);
		a++;
	}
}

/**
 * stputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: 1 if successful, -1 otherwise
 */

int stputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: filedescriptor to write to
 *
 * Return: 1 if successful, -1 otherwise and errno is set appropriately.
 */

int putfd(char c, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * putsfd - prints an input string
 * @str: the string to be printed
 * @fd: filedescriptor to write to
 *
 * Return: number of characters put
 */
int putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += putfd(*str++, fd);
	}
	return (a);
}
