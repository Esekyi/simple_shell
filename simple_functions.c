#include "shell.h"

/**
 * _strcmp - this function compares two strings
 * @str1: 1st string
 * @str2: 2nd string
 * Return: 0 if strings match and -1 if they don't
 */

int _strcmp(char *str1, char *str2)
{
	int s;

	if (_strlen(str1) != _strlen(str2))
	{
		return (-1);
	}
	for (s = 0; str1[s] != '\0'; s++)
	{
		if (str1[s] != str2[s])
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * simple_error - function prints simple error
 * Return: void
 */

void simple_error(void)
{
	perror("Fatal Error");
	exit(100);
}

/**
 * print_error - function that prints error message if command not found
 * @argv: name of shell program
 * @cnt: number of commands running on shell
 * @cmd: command not found
 * Return: void
 */

void print_error(char *argv, int cnt, char *cmd)
{
	print_str(argv, 1);
	print_str(": ", 1);
	print_number(cnt);
	print_str(": ", 1);
	print_str(cmd, 1);
}

/**
 * print_str - function prints a string character by character
 * @str: string to print
 * @newline: if the interger is zero a newline is printed
 * Return: void
 */

void print_str(char *str, int newline)
{
	int a;

	if (str == NULL)
		str = "(null)";
	for (a = 0; str[a] != '\0'; a++)
	{
		write(STDOUT_FILENO, &str[a], 1);
	}

	if (newline == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * execute_error - a function that prints execution errors
 * @argv: the name of the shell program
 * @cnt: the number of commands running on the shell
 * @temp_cmd: the command that fails
 */

void execute_error(char *argv, int cnt, char *temp_cmd)
{
	print_error(argv, cnt, temp_cmd);
	print_str(": ", 1);
	perror("");
	exit(1);
}
