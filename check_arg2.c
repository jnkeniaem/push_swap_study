#include "pushswap.h"

void if_satisfied(t_arg *arg)
{
	int i;

	i = 0;
	if (arg->total == 1)
		exit(EXIT_SUCCESS);
	while (i < arg->total - 1)
	{
		if (arg->num[i] < arg->num[i + 1])
			i++;
		else
			return ;
	}
	exit(EXIT_SUCCESS);
}

void check_space(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if (argv[i + 1][j] == ' ')
				j++;
			else
				break;
		}
		if (argv[i + 1][j] == 0)
			ft_error("Error\nWhite-spaced argument.");
		i++;
	}
}