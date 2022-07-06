#include "pushswap.h"
#include <stdio.h>
void pa(t_arg *arg, t_a *pa, t_b *pb) // a에 뭔가 남아있을 경우와 없는 경우
{
	if (pb->current == 0)
	{
		ft_putstr_fd("No more in stack b.\n", 1);
		return;
	}
	if (pa->front == 0)
		pa->front = arg->total - 1;
	else
		pa->front = (pa->front - 1) % arg->total;
	pa->stack[pa->front] = pb->stack[pb->front];
	(pb->current)--;
	(pa->current)++;
	if (pb->front == pb->rear)
		return ;
	else
		pb->front = (pb->front + 1) % arg->total;
	pa->rear = (pa->front + pa->current - 1) % arg->total;
	//pb로 다 보냈다가 pa로 다 보냈을 경우를 생각해서.
}

void pb(t_arg *arg, t_a *pa, t_b *pb)
{
	if (pa->current == 0)
	{
		ft_putstr_fd("No more in stack a.\n", 1);
		return;
	}
	if (pb->front == 0)
		pb->front = arg->total -1;
	else
		pb->front = (pb->front - 1) % arg->total;
	pb->stack[pb->front] = pa->stack[pa->front];
	(pa->current)--;
	(pb->current)++;
	if (pa->front == pa->rear)
		return;
	else
		pa->front = (pa->front + 1) % arg->total;
	pb->rear = (pb->front + pb->current - 1) % arg->total;
	//rear를 맨 밑의 요소를 가리키게하공
}