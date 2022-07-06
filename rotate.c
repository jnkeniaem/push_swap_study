#include "pushswap.h"

void ra(t_arg *arg, t_a *pa)
{
	int	temp;

	temp = pa->stack[pa->front];
	pa->front = (pa->front + 1) % arg->total;
	pa->rear = (pa->rear + 1) % arg->total;
	pa->stack[pa->rear] = temp;
}

void rb(t_arg *arg, t_b *pb)
{
	int	temp;
	temp = pb->stack[pb->front];
	pb->front = (pb->front + 1) % arg->total;
	pb->rear = (pb->rear + 1) % arg->total;
	pb->stack[pb->rear] = temp;
}

void rr(t_arg *arg, t_a *pa, t_b *pb)
{
	ra(arg, pa);
	rb(arg, pb);
}