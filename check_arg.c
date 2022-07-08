#include "pushswap.h"

void check_argc(int argc)
{
	if (argc == 1)
		ft_error("Error\nNeed more than 1 argument.");
}

void if_double_quote_1(int argc, char **argv, t_arg *parg)
{
	int i;
	int	j;
    char **temp;

    i = 0;
    parg->total = 0;
    while (i < argc -1)
    {
        j = 0;
        temp = ft_split(argv[i + 1], ' ');
        while (temp[j])
        {
			check_int(temp[j]);
			check_int_range(temp[j]);
            j++;
            parg->total++;
        }
		free(temp);
		i++;
    }
    parg->num = malloc(sizeof(int) * parg->total);
	
}

void if_double_quote_2(int argc, char **argv, t_arg *parg)
{
	int	i;
	int	j;
	int	k;
	char **temp;

	i = 0;
	k = 0;
	while (i < argc - 1)
	{
	j = 0;
	temp = ft_split(argv[i + 1], ' ');
	while (temp[j])
	{
		parg->num[k] = ft_atoi(temp[j]);
		k++;
		j++;
	}
	free(temp);
	i++;
    }
}

void check_int(char *str)
{
	int			flag;
	int	i;

	flag = 0;
	i = 0;
	while (ft_available(*(str + i), "+-"))
		i++;
	while (ft_available(*(str + i), "0123456789"))
	{
		flag = 1;
		i++;
	}
	if (!((flag == 1) && (*(str + i) == '\0')))
		ft_error("Error\nNot an integer.");
}

void check_int_range(char *str)
{
	int			minus;
	long long	result;
	int	i;

	minus = 1;
	result = 0;
	i = 0;
	while (ft_available(*(str + i), "+-"))
	{
		if (*(str + i) == '-')
			minus *= -1;
		i++;
	}
	while (ft_available(*(str + i), "0123456789"))
	{
		result *= 10;
		result += *(str + i) - '0';
		if ((result > 2147483647 && minus == 1)
		|| (result > 2147483648 && minus == -1))
			ft_error("Error\nOut of int range.");
		i++;
	}
}

void check_duplicate(t_arg *parg)
{
	int	i;
	int	j;

	i = 0;
	while (i < parg->total -1)
	{
		j = i + 1;
		while (j < parg->total)
		{
			if (parg->num[i] == parg->num[j])
				ft_error("Error\nDuplicate here.");
			else
				j++;
		}
		i++;
	}
}


#include <stdio.h>

void check_arg(int argc, char **argv, t_arg *parg)
{
	
	check_argc(argc);
	check_space(argc, argv);
	if_double_quote_1(argc, argv, parg);
	if_double_quote_2(argc, argv, parg);
	check_duplicate(parg);
	if_satisfied(parg);
}