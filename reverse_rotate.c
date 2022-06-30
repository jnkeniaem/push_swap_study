#include "pushswap.h"

void rra(t_circular_ary *p_ca, t_a *pa)
{
	int	temp;

	temp = pa->stack[pa->rear];
	pa->front = (pa->front - 1) % p_ca->max_arg;
	pa->rear = (pa->rear - 1) % p_ca->max_arg;
	pa->stack[pa->front] = temp;
}

void rrb(t_circular_ary *p_ca, t_b *pb)
{
	int	temp;

	temp = pb->stack[pb->rear];
	pb->front = (pb->front - 1) % p_ca->max_arg;
	pb->rear = (pb->rear - 1) % p_ca->max_arg;
	pb->stack[pb->front] = temp;
}

void rrr(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	rra(p_ca, pa);
	rrb(p_ca, pb);
}