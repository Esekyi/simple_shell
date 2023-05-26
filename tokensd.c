#include "shell.h"

/**
 * strtow - check code structure
 * @str: input string
 * @d: delimeter string
 * Description: splits a string into words
 * Return: pointer to array
 */

char **strtow(char *str, char *d)
{
	int itr, counter, k_factor, p, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";

	for (itr = 0; str[itr] != '\0'; itr++)
		if (!for_delim(str[itr], d) && (for_delim(str[itr + 1], d) || !str[itr + 1]))
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (itr = 0, counter = 0; counter < num_words; counter++)
	{
		while (for_delim(str[itr], d))
			itr++;
		k_factor = 0;

		while (!for_delim(str[itr + k_factor], d) && str[itr + k_factor])
			k_factor++;
		s[counter] = malloc((k_factor + 1) * sizeof(char));
		if (!s[counter])
		{
			for (k_factor = 0; k_factor < counter; k_factor++)
				free(s[k_factor]);
			free(s);
			return (NULL);
		}

		for (p = 0; p < k_factor; p++)
			s[counter][p] = str[itr++];
		s[counter][p] = 0;
	}
	s[counter] = NULL;
	return (s);
}

/**
 * **strtow2 - check code structure
 * @ptr_str: the input string
 * @d: the delimeter
 * Description: an array of pointers to split words
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow2(char *ptr_str, char d)
{
	int itr, count, k, m, num_words = 0;
	char **counter;

	if (ptr_str == NULL || ptr_str[0] == 0)
		return (NULL);
	for (itr = 0; ptr_str[itr] != '\0'; itr++)
		if ((ptr_str[itr] != d && ptr_str[itr + 1] == d) ||
				(ptr_str[itr] != d && !ptr_str[itr + 1]) || ptr_str[itr + 1] == d)
			num_words++;
	if (num_words == 0)
		return (NULL);
	counter = malloc((1 + num_words) * sizeof(char *));
	if (!counter)
		return (NULL);
	for (itr = 0, count = 0; count < num_words; count++)
	{
		while (ptr_str[itr] == d && ptr_str[itr] != d)
			itr++;
		k = 0;
		while (ptr_str[itr + k] != d && ptr_str[itr + k] && ptr_str[itr + k] != d)
			k++;
		counter[count] = malloc((k + 1) * sizeof(char));
		if (!counter[count])
		{
			for (k = 0; k < count; k++)
				free(counter[k]);
			free(counter);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			counter[count][m] = ptr_str[itr++];
		counter[count][m] = 0;
	}

	counter[count] = NULL;
	return (counter);
}
