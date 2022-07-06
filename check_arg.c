#include "pushswap.h"

void check_argc(int argc)
{
	if (argc == 1)
		ft_error("Error\nNeed more than 1 argument.");
}

void if_double_quote_1(int argc, char **argv, t_arg *arg)
{
	int i;
	int	j;
    char **temp;

    i = 0;
    arg->total = 0;
    while (i < argc -1)
    {
        j = 0;
        temp = ft_split(argv[i + 1], ' ');
        while (temp[j])
        {
			check_int(temp[j]);
			check_int_range(temp[j]);
            j++;
            arg->total++;
        }
        i++;
    }
    arg->num = malloc(sizeof(int) * arg->total);
	free(temp);
}

void if_double_quote_2(int argc, char **argv, t_arg *arg)
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
		arg->num[k] = ft_atoi(temp[j]);
		k++;
		j++;
	}
	i++;
    }
	free(temp);
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

void check_duplicate(t_arg *arg)
{
	int	i;
	int	j;

	i = 0;
	while (i < arg->total -1)
	{
		j = i + 1;
		while (j < arg->total)
		{
			if (arg->num[i] == arg->num[j])
				ft_error("Error\nDuplicate here.");
			else
				j++;
		}
		i++;
	}
}


#include <stdio.h>

void check_arg(int argc, char **argv, t_arg *arg)
{
	
	check_argc(argc);
	if_double_quote_1(argc, argv, arg);
	if_double_quote_2(argc, argv, arg);
	check_duplicate(arg);
	if_satisfied(arg);
}