#include "pushswap.h"
#include <stdio.h>

void init_stack(t_arg *parg, t_a *pa, t_b *pb)//a stack 만들기?
{
	int	i;

	i = 0;
	pa->stack = malloc(parg->total * sizeof(int));
	pb->stack = malloc(parg->total * sizeof(int));
	pa -> front = 0;
	pa -> rear = 0;
	while (i < parg->total)
	{
		pa->stack[pa->rear] = parg->num[i];
		if (pa->rear == parg->total -1)
			break;
		pa->rear = (pa->rear + 1) % (parg->total);
		i++;
	}
	pb -> front = 0;
	pb->rear = parg->total - 1;
	pa->current = parg->total;
	pb->current = 0;
	// i = 0;
	// while (i < pa->current)
	// {
	// 	printf("%d\n", pa->stack[(pa->front + i) % arg->total]);
	// 	i++;
	// }
}