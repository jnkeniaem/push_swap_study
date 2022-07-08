#include "pushswap.h"

void sa(t_arg *arg, t_a *ptr_a)
{
	int	temp;

	temp = ptr_a->stack[ptr_a->front];
	ptr_a->stack[ptr_a->front] = ptr_a->stack[(ptr_a->front + 1) % arg->total];
	ptr_a->stack[ptr_a->front + 1] = temp;
}

void sb(t_arg *arg, t_b *ptr_b)
{
	int	temp;

	temp = ptr_b->stack[ptr_b->front];
	ptr_b->stack[ptr_b->front] = ptr_b->stack[(ptr_b->front + 1) % arg->total];
	ptr_b->stack[ptr_b->front + 1] = temp;
}

void ss(t_arg *arg, t_a *ptr_a, t_b *ptr_b)
{
	sa(arg, ptr_a);
	sb(arg, ptr_b);
}