#include "pushswap.h"

#include <stdio.h>

int if_satisfied(int argc, char **argv)
//인수가 하나만 들어오는 경우
//인수가 순서대로 들어오는 경우
{
	int i;

	i = 1;
	if (argc == 2)
		return 1;
	while (i <= argc - 2)
	{
		if (argv[i] < argv[i + 1])
			i++;
		else
			return (0);
	}
	if (i == argc - 1)
		return 1;
	return (0);
}
/*
if_double_quote(char **argv)
{
*/