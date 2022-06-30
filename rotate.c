#include "pushswap.h"

void ra(t_circular_ary *p_ca, t_a *pa)
{
	int	temp;

	temp = pa->stack[pa->front];
	pa->front = (pa->front + 1) % p_ca->max_arg;
	pa->rear = (pa->rear + 1) % p_ca->max_arg;
	pa->stack[pa->rear] = temp;
}

void rb(t_circular_ary *p_ca, t_b *pb)
{
	int	temp;
	temp = pb->stack[pb->front];
	pb->front = (pb->front + 1) % p_ca->max_arg;
	pb->rear = (pb->rear + 1) % p_ca->max_arg;
	pb->stack[pb->rear] = temp;
}

void rr(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	ra(p_ca, pa);
	rb(p_ca, pb);
}