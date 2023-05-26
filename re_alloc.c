#include "shell.h"

/**
 * fill_mem - check code
 * @mem_area: string pointer to memory area
 * @byt_fill: the byte to fill
 * @num: amount of bytes
 * Description: fills the memory area
 * Return: pointer to memory area
 */

char *fill_mem(char *mem_area, char byt_fill, unsigned int num)
{
	unsigned int itr;

	for (itr = 0; itr < num; itr++)
		mem_area[itr] = byt_fill;
	return (mem_area);
}

/**
 * ffree - check code
 * @str_ptr: string of strings
 * Description: frees string of strings
 * Return: None
 */

void ffree(char **str_ptr)
{
	char **ptr = str_ptr;

	if (!str_ptr)
		return;

	while (*str_ptr)
		free(*str_ptr++);

	free(ptr);
}

/**
 * _realloc - check code
 * @pp_malloc: pointer to previous malloc block
 * @old_size: byte_size of previous block, in bytes
 * @new_size: byte_size of new block
 * Description: reallocates block of memory
 * Return: pointer to previous block.
 */

void *_realloc(void *pp_malloc, unsigned int old_size, unsigned int new_size)
{
	char *p_ptr;

	if (!pp_malloc)
		return (malloc(new_size));

	if (!new_size)
		return (free(pp_malloc), NULL);

	if (new_size == old_size)
		return (pp_malloc);

	p_ptr = malloc(new_size);
	if (!p_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		p_ptr[old_size] = ((char *)pp_malloc)[old_size];

	free(pp_malloc);
	return (p_ptr);
}
