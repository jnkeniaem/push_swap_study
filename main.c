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
	pb(&ca, &a, &b);
	pb(&ca, &a, &b);
	rrr(&ca, &a, &b);
	int i = 0;
	//명령어하고 인덱스에 맞게 스택에 넣어주는 작업 필요할것같아	
	//  pa(&ca, &a, &b);
	// ss(&a, &b);
	// ra(&ca, &a);
	// rb(&ca, &b);
	// rra(&ca, &a);
	// rrb(&ca, &b);
	//printf("cur a %d\n", a.current);
	// printf("f%d r%d\n", a.front, a.rear);
	// while (i < a.current)
	// {
	// 	printf("%d\n", a.stack[(a.front + i) % ca.max_arg]);
	// 	i++;
	// }
	// sb(&ca, &b);
	printf("------a-------\n");
	
	i = 0;
	while (i < a.current)
	{
		printf("%d\n", a.stack[(a.front + i) % ca.max_arg]);
		i++;
	}
	i = 0;
	printf("------b-------\n");
	while (i < b.current)
	{
		printf("%d\n", b.stack[(b.front + i) % ca.max_arg]);
		i++;
	}
}