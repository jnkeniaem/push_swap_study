#include "pushswap.h"



void ft_error(char *message)
{
		ft_putstr_fd(message, 1);
		exit(EXIT_FAILURE);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	t_a	a;
	t_b b;
	t_arg	arg;

	check_arg(argc, argv, &arg);
	int i = 0;
	// while (i < arg.total)
	// {
	// 	printf("arg->num[i] %d\n", arg.num[i]);
	// 	i++;
	// }
	// init_stack(argc, argv, &arg, &a, &b);
	init_stack(&arg, &a, &b);
		i = 0;
		printf("------b1-------\n");
		while (i < b.current)
		{
			printf("%d\n", b.stack[(b.front + i) % arg.total]);
			i++;
		}
	pb(&arg, &a, &b);
	pb(&arg, &a, &b);
	pb(&arg, &a, &b);
	pb(&arg, &a, &b);
	pa(&arg, &a, &b);
	pa(&arg, &a, &b);
	pa(&arg, &a, &b);
	pa(&arg, &a, &b);
	rrr(&arg, &a, &b);
	// pb(&arg, &a, &b);
	// pb(&arg, &a, &b);
	// pb(&arg, &a, &b);
	// pb(&arg, &a, &b);
	// printf("f%d r%d\n", a.front, a.rear);
	// rrr(&arg, &a, &b);
	i = 0;
	//명령어하고 인덱스에 맞게 스택에 넣어주는 작업 필요할것같아	
	//  pa(&arg, &a, &b);
	// ss(&a, &b);
	// ra(&arg, &a);
	// rb(&arg, &b);
	// rra(&arg, &a);
	// rrb(&arg, &b);
	//printf("cur a %d\n", a.current);
	
	// while (i < a.current)
	// {
	// 	printf("%d\n", a.stack[(a.front + i) % ca.max_arg]);
	// 	i++;
	// }
	// sb(&arg, &b);
	
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
	// free(a.stack); 이게 문제가 아님
	// free(b.stack);
	system("leaks push_swap");
}