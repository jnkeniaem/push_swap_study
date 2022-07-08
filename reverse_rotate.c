#include "pushswap.h"

void rra(t_arg *parg, t_a *ptr_a)
{
	int	temp;

	temp = ptr_a->stack[ptr_a->rear];
	ptr_a->front = (ptr_a->front - 1) % parg->total;
	ptr_a->rear = (ptr_a->rear - 1) % parg->total;
	ptr_a->stack[ptr_a->front] = temp;
}

void rrb(t_arg *parg, t_b *ptr_b)
{
	int	temp;

	temp = ptr_b->stack[ptr_b->rear];
	ptr_b->front = (ptr_b->front - 1) % parg->total;
	ptr_b->rear = (ptr_b->rear - 1) % parg->total;
	ptr_b->stack[ptr_b->front] = temp;
}

void rrr(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	rra(parg, ptr_a);
	rrb(parg, ptr_b);
}