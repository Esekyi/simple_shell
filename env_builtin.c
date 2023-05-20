#include "shell.h"

/**
 * _env - prints the current environment
 * @info: Structure containing potential arguments
 * Return: 0
 */

int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * find_env - finds the value of an environ variable
 * @info: Structure containing potential arguments
 * @name: environment variable name
 *
 * Return: value
 */

char *find_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *c;

	while (node)
	{
		c = starts_with(node->str, name);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * st_env - starts new environment variable
 * @info: Structure containing potential arguments
 *  Return: 0
 */

int st_env(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * rem_env - Remove an environment variable
 * @info: Structure containing potential arguments
 * Return: 0
 */

int rem_env(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}

/**
 * fill_env_list - fills env linked list
 * @info: Structure containing potential arguments
 * Return: 0
 */

int fill_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
