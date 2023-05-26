#include "shell.h"

/**
 * bfree - check code
 * @ptr: address of the pointer to free
 * Description: frees a pointer
 * Return: 1 (if free success) or 0 failure
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;

		return (1);
	}

	return (0);
}
