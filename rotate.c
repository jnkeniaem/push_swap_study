#include "pushswap.h"

void ra(t_arg *arg, t_a *ptr_a)
{
	int	temp;

	temp = ptr_a->stack[ptr_a->front];
	ptr_a->front = (ptr_a->front + 1) % arg->total;
	ptr_a->rear = (ptr_a->rear + 1) % arg->total;
	ptr_a->stack[ptr_a->rear] = temp;
}

void rb(t_arg *arg, t_b *ptr_b)
{
	int	temp;
	temp = ptr_b->stack[ptr_b->front];
	ptr_b->front = (ptr_b->front + 1) % arg->total;
	ptr_b->rear = (ptr_b->rear + 1) % arg->total;
	ptr_b->stack[ptr_b->rear] = temp;
}

void rr(t_arg *arg, t_a *ptr_a, t_b *ptr_b)
{
	ra(arg, ptr_a);
	rb(arg, ptr_b);
}