#include "pushswap.h"
#include <stdio.h>

void init_stack(t_arg *arg, t_a *pa, t_b *pb)//a stack 만들기?
{
	int	i;

	i = 0;
	pa->stack = malloc(arg->total * sizeof(int));
	pb->stack = malloc(arg->total * sizeof(int));
	pa -> front = 0;
	pa -> rear = 0;
	while (i < arg->total)
	{
		pa->stack[pa->rear] = arg->num[i];
		if (pa->rear == arg->total -1)
			break;
		pa->rear = (pa->rear + 1) % (arg->total);
		i++;
	}
	pb -> front = 0;
	pb->rear = arg->total - 1;
	pa->current = arg->total;
	pb->current = 0;
	// i = 0;
	// while (i < pa->current)
	// {
	// 	printf("%d\n", pa->stack[(pa->front + i) % arg->total]);
	// 	i++;
	// }
}