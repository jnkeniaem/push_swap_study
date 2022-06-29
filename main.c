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
#include <stdio.h>
int main(int argc, char **argv)
{
	t_circular_ary ca;
	t_a	a;
	t_b b;

	//check_arg(argc, argv);
	init_stack(argc, argv, &ca, &a, &b);
	int i = 0;
	
	
	// pb(&ca, &a, &b);
	// pb(&ca, &a, &b);
	// pb(&ca, &a, &b);
	// ss(&a, &b);
	//  sb(&b);
	ra(&ca, &a);
	current_arg(&a, &b);
	printf("------ra-------\n");
	printf("%d %d\n", a.front, a.rear);
	printf("%d\n", a.current);
	while (i < a.current)
	{
		printf("%d\n", a.stack[a.front]);
		a.front = (a.front + 1) % ca.max_arg;
		i++;
	}
	i = 0;
	printf("------rb-------\n");
	while (i < argc - 1)
	{
		printf("%d\n", b.stack[i]);
		i++;
	}
}