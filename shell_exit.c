#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;
	char *arg = datash->args[1];

	if (arg != NULL)
	{
		is_digit = 1;
		for (str_len = 0; arg[str_len] != '\0'; str_len++)
		{
			if (arg[str_len] < '0' || arg[str_len] > '9')
			{
				is_digit = 0;
				break;
			}
		}
		ustatus = (is_digit) ? _atoi(arg) : 0;
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}
