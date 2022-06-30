#include "pushswap.h"

void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb)//a stack 만들기?
{
	int	i;

	i = 1;
	p_ca -> max_arg = argc - 1;
	pa->stack = malloc(p_ca -> max_arg * sizeof(int));
	pb->stack = malloc(p_ca -> max_arg * sizeof(int));
	pa -> front = 0;
	pa -> rear = 0;
	while (i < argc)
	{
		pa->stack[pa->rear] = ft_atoi(argv[i]);//ft_atoi.. 다른 문자열을 정수로 바꿔주는것도 생각해보자 지금은 그냥 이게 생각나서 바로 하는거궁
		if (pa->rear == p_ca -> max_arg -1)
			break;
		pa->rear = (pa->rear + 1) % (p_ca->max_arg);
		i++;
	}
	pb -> front = 0;
	pb -> rear = p_ca->max_arg -1;
	pa->current = argc -1;
	pb->current = 0;
}