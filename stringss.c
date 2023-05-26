#include "shell.h"

/**
 * _strlen - check code structure
 * @str: string to check length of characters
 * Description: function to check length of a string
 * Return: length of string
 */

int _strlen(char *str)
{
	int itr = 0;

	if (!str)
		return (0);

	while (*str++)
		itr++;

	return (itr);
}

/**
 * _strcmp - check code structure
 * @str_i: string to compare
 * @str_o: second string to compare
 * Description: function to compare strings
 * Return: negative if string
 */

int _strcmp(char *str_i, char *str_o)
{
	while (*str_i && *str_o)
	{
		if (*str_i != *str_o)
			return (*str_i - *str_o);

		str_i++;
		str_o++;
	}

	if (*str_i == *str_o)
		return (0);

	else
		return (*str_i < *str_o ? -1 : 1);
}


/**
 * _strcat - check code structure
 * @dest: buffer destination
 * @src: source of buffer
 * Description: function to concatenate two str
 * Return: buffer destination
 */

char *_strcat(char *dest, char *src)
{
	char *ret_val = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;

	return (ret_val);
}


/**
 * starts_with - check code structure
 * @haystack: variable string to search
 * @needle: substring to search
 * Description: function to checks
 * Return: address of next substring
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);

	return ((char *)haystack);
}
