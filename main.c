#include "pushswap.h"

void repetitive_statement(int argc, char **argv)
{
	int	h;

	h = 1;
	while (h <= argc - 1)
	{
		check_int(argv, h);
		h++;
	}
	h = 1;
	while (h <= argc - 1)
	{
		check_int_range(argv, h);
		h++;
	}
}

void ft_error(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("Error\nNot an integer.", 1);
		exit(EXIT_FAILURE);
	}
	else if (i == 2)
	{
		ft_putstr_fd("Error\nOut of int range.", 1);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	check_arg(argc, argv);

}