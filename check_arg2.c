#include "pushswap.h"

void if_satisfied(t_arg *parg)
{
	int i;

	i = 0;
	if (parg->total == 1)
		exit(EXIT_SUCCESS);
	while (i < parg->total - 1)
	{
		if (parg->num[i] < parg->num[i + 1])
			i++;
		else
			return ; // 딱 아닌 위치를 반환
	}
	exit(EXIT_SUCCESS);
}//

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