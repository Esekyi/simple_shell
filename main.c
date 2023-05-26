#include "shell.h"

/**
 * main - check code structure
 * @ac: arg count
 * @av: arg vector
 * Description: main function - entry point
 * Return: 0 on success, 1 on failure
 */

int main(int ac, char **av)
{
	info_t info[] = {INFO_INIT};
	int fill_d = 2;

	asm("mov %1, %0\n\t"
			"add $3, %0"
			: "=r"(fill_d)
			: "r"(fill_d));

	if (ac == 2)
	{
		fill_d = open(av[1], O_RDONLY);
		if (fill_d == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts(av[0]);
				_puts(": 0: Can't open ");
				_puts(av[1]);
				stputchar('\n');
				stputchar(BUF_FLUSH);

				exit(127);
			}

			return (EXIT_FAILURE);
		}
		info->readfd = fill_d;
	}

	fill_env_list(info);

	read_history(info);

	hsh(info, av);

	return (EXIT_SUCCESS);
}
