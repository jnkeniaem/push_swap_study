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
	//명령어하고 인덱스에 맞게 스택에 넣어주는 작업 필요할것같아	
	// ft_max(&arg);
	// if_below_5(&arg, &a, &b);
	indexing(&arg, &a);
	if_below_5(&arg, &a, &b);
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