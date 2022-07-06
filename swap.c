#include "pushswap.h"

void sa(t_arg *arg, t_a *pa)
{
	int	temp;

	temp = pa->stack[pa->front];
	pa->stack[pa->front] = pa->stack[(pa->front + 1) % arg->total];
	pa->stack[pa->front + 1] = temp;
}

void sb(t_arg *arg, t_b *pb)
{
	int	temp;

	temp = pb->stack[pb->front];
	pb->stack[pb->front] = pb->stack[(pb->front + 1) % arg->total];
	pb->stack[pb->front + 1] = temp;
}

void ss(t_arg *arg, t_a *pa, t_b *pb)
{
	sa(arg, pa);
	sb(arg, pb);
}