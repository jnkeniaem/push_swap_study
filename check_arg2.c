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