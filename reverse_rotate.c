#include "pushswap.h"

void rra(t_arg *arg, t_a *pa)
{
	int	temp;

	temp = pa->stack[pa->rear];
	pa->front = (pa->front - 1) % arg->total;
	pa->rear = (pa->rear - 1) % arg->total;
	pa->stack[pa->front] = temp;
}

void rrb(t_arg *arg, t_b *pb)
{
	int	temp;

	temp = pb->stack[pb->rear];
	pb->front = (pb->front - 1) % arg->total;
	pb->rear = (pb->rear - 1) % arg->total;
	pb->stack[pb->front] = temp;
}

void rrr(t_arg *arg, t_a *pa, t_b *pb)
{
	rra(arg, pa);
	rrb(arg, pb);
}