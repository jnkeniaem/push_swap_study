#include "pushswap.h"



void ft_error(char *message)
{
		ft_putstr_fd(message, 1);
		exit(EXIT_FAILURE);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_a		a;
	t_b		b;
	t_arg	arg;
	// t_merge	merge;

	check_arg(argc, argv, &arg);
	int i = 0;
	init_stack(&arg, &a, &b);
	// ft_max(&arg);
	ft_putstr_fd("------a-------\n", 1);
	i = 0;
	while (i < a.current)
	{
		printf("%d\n", a.stack[(a.front + i) % arg.total]);
		i++;
	}
	indexing(&arg, &a);
	ft_putstr_fd("---after indexing a---\n", 1);
	i = 0;
	while (i < a.current)
	{
		printf("%d\n", a.stack[(a.front + i) % arg.total]);
		i++;
	}
	if (a.current <= 5)
		if_below_5(&arg, &a, &b);
	else
		if_exceed_5(&arg, &a, &b);
	ft_putstr_fd("------a-------\n", 1);
	i = 0;
	while (i < a.current)
	{
		printf("%d\n", a.stack[(a.front + i) % arg.total]);
		i++;
	}
	i = 0;
	ft_putstr_fd("------b-------\n", 1);
	while (i < b.current)
	{
		printf("%d\n", b.stack[(b.front + i) % arg.total]);
		i++;
	}
	free(arg.num);
	free(a.stack);
	free(b.stack);
	// system("leaks push_swap");
}