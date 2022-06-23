#include "pushswap.h"

void check_argc(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\nNeed more than 1 argument.", 1);
		exit(EXIT_FAILURE);
	}
}

void check_int(char **argv, int h)
{
	int			minus;
	int			flag;
	int	i;

	minus = 1;
	flag = 0;
	i = 0;
	argv += h;
	while (ft_available(*(*argv + i), "+-"))
	{
		if (*(*argv + i) == '-')
			minus *= -1;
		i++;
	}
	while (ft_available(*(*argv + i), "0123456789"))
	{
		flag = 1;
		i++;
	}
	if (!((flag == 1) && (*(*argv + i) == '\0')))
		ft_error(1);
}

void check_int_range(char **argv, int h)
{
	int			minus;
	long long	result;
	int	i;

	minus = 1;
	result = 0;
	i = 0;
	argv += h;
	while (ft_available(*(*argv + i), "+-"))
	{
		if (*(*argv + i) == '-')
			minus *= -1;
		i++;
	}
	while (ft_available(*(*argv + i), "0123456789"))
	{
		result *= 10;
		result += *(*argv + i) - '0';
		if ((result > 2147483647 && minus == 1)
		|| (result > 2147483648 && minus == -1))
			ft_error(2);
		i++;
	}
}

void check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				{
					ft_putstr_fd("Error\nDuplicate here.", 1);
					exit(EXIT_FAILURE);
				}
			else
				j++;
		}
		i++;
	}
}



void check_arg(int argc, char **argv)
{
	check_argc(argc);
	if_satisfied(argc, argv);
	repetitive_statement(argc, argv);
	check_duplicate(argc, argv);
}