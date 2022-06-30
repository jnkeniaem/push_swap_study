#include "pushswap.h"

void sa(t_circular_ary *p_ca, t_a *pa)
{
	int	temp;

	temp = pa->stack[pa->front];
	pa->stack[pa->front] = pa->stack[(pa->front + 1) % p_ca->max_arg];
	pa->stack[pa->front + 1] = temp;
}

void sb(t_circular_ary *p_ca, t_b *pb)
{
	int	temp;

	temp = pb->stack[pb->front];
	pb->stack[pb->front] = pb->stack[(pb->front + 1) % p_ca->max_arg];
	pb->stack[pb->front + 1] = temp;
}

void ss(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	sa(p_ca, pa);
	sb(p_ca, pb);
}