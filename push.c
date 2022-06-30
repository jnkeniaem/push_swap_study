#include "pushswap.h"

void pa(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	if (pb->current == 0)
		return ;
	pa->front = (pa->front - 1) % p_ca->max_arg;
	if (pa->front == 0)
		pa->front = p_ca->max_arg -1;
	pa->stack[pa->front] = pb->stack[pb->front];
	if (pb->front == pb->rear)
		return ;
	else
		pb->front = (pb->front + 1) % p_ca->max_arg;
	(pb->current)--;
	(pa->current)++;
}

void pb(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	if (pa->current == 0)
		return ;
	if (pb->front == 0)
		pb->front = p_ca->max_arg -1;
	else
		pb->front = (pb->front - 1) % p_ca->max_arg;
	if (pb->front == 0)
		pb->front = p_ca->max_arg -1;
	pb->stack[pb->front] = pa->stack[pa->front];
	if (pa->front == pa->rear)
		return ;
	else
		pa->front = (pa->front + 1) % p_ca->max_arg;
	(pa->current)--;
	(pb->current)++;
}//pa에 남은게 없는데 pb하라그러면 메시지 날릴까?