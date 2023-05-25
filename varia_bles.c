#include "shell.h"

/**
 * _is_chain - check code
 * @parramt: parameter to check
 * @buff: the buffer of the char
 * @ptr: address of position in the buffer
 * Description: function to check if current
 * char in buffer is a chain delimeter
 * Return: 1 or 0
 */

int _is_chain(info_t *parramt, char *buff, size_t *ptr)
{
	size_t iterater = *ptr;

	if (buff[iterater] == '|' && buff[iterater + 1] == '|')
	{
		buff[iterater] = 0;
		iterater++;
		parramt->cmd_buf_type = CMD_OR;
	}

	else if (buff[iterater] == '&' && buff[iterater + 1] == '&')
	{
		buff[iterater] = 0;
		iterater++;
		parramt->cmd_buf_type = CMD_AND;
	}

	else if (buff[iterater] == ';')
	{
		buff[iterater] = 0;
		parramt->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);

	*ptr = iterater;
	return (1);
}

/**
 * chain_check - check code
 * @prm: parameter to check
 * @buff: the buffer of the char
 * @ptr: address of position in the buffer
 * @itr: starting iterator position in buffer
 * @len: the length of buffer
 * Description: checks if we should continue
 * chaining based on last status
 * Return: Nothings are returned
 */

void chain_check(info_t *prm, char *buff, size_t *ptr, size_t itr, size_t len)
{
	size_t iterater = *ptr;

	if (prm->cmd_buf_type == CMD_AND)
	{
		if (prm->status)
		{
			buff[itr] = 0;
			iterater = len;
		}
	}
	if (prm->cmd_buf_type == CMD_OR)
	{
		if (!prm->status)
		{
			buff[itr] = 0;
			iterater = len;
		}
	}

	*ptr = iterater;
}

/**
 * _alias_repl - replace aliases in a token string
 * @paramts: parameter
 * Description: replace aliases in a string
 * Return: 1 or 0
 */

int _alias_repl(info_t *paramts)
{
	int itr;
	list_t *node;
	char *ptr;

	for (itr = 0; itr < 10; itr++)
	{
		node = node_starts_with(paramts->alias, paramts->argv[0], '=');

		if (!node)
			return (0);
		free(paramts->argv[0]);
		ptr = _strchr(node->str, '=');

		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);

		if (!ptr)
			return (0);
		paramts->argv[0] = ptr;
	}

	return (1);
}

/**
 * _vars_repl - check code
 * @info: parameter
 * Description: replaced vars string
 * Return: 1 or 0
 */

int _vars_repl(info_t *info)
{
	int itr = 0;
	list_t *node;

	for (itr = 0; info->argv[itr]; itr++)
	{
		if (info->argv[itr][0] != '$' || !info->argv[itr][1])
			continue;

	if (!_strcmp(info->argv[itr], "$?"))
	{
		_str_repl(&(info->argv[itr]),
				_strdup(convert_number(info->status, 10, 0)));
		continue;
	}
	if (!_strcmp(info->argv[itr], "$$"))
	{
		_str_repl(&(info->argv[itr]),
				_strdup(convert_number(getpid(), 10, 0)));
		continue;
	}

	node = node_starts_with(info->env, &info->argv[itr][1], '=');
	if (node)
	{
		_str_repl(&(info->argv[itr]),
				_strdup(_strchr(node->str, '=') + 1));
		continue;
	}
	_str_repl(&info->argv[itr], _strdup(""));
	}

	return (0);
}

/**
 * _str_repl - check code
 * @old_ptr: pointer address of old string
 * @new: pointer to new string
 * Description: replaces a string
 * Return: 1 or 0
 */

int _str_repl(char **old_ptr, char *new)
{
	free(*old_ptr);
	*old_ptr = new;
	return (1);
}
