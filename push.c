#include "pushswap.h"
#include <stdio.h>
void pa(t_arg *parg, t_a *ptr_a, t_b *ptr_b) // a에 뭔가 남아있을 경우와 없는 경우
{
	if (ptr_b->current == 0)
	{
		ft_putstr_fd("No more in stack b.\n", 1);
		return;
	}
	if (ptr_a->front == 0)
		ptr_a->front = parg->total - 1;
	else if ((ptr_a->front == ptr_a->rear) && (ptr_a->current == 0))
	//pb로 인해 a에 아무것도 안남아 있는 상태
		ptr_a->front = ptr_a->rear; // 그대로 남아 있어라
	else
		ptr_a->front = (ptr_a->front - 1) % parg->total;
	ptr_a->stack[ptr_a->front] = ptr_b->stack[ptr_b->front];
	(ptr_b->current)--;
	(ptr_a->current)++;
	if (ptr_b->front == ptr_b->rear)
		return ;
	else
		ptr_b->front = (ptr_b->front + 1) % parg->total;
	//ptr_a->rear = (ptr_a->front + ptr_a->current - 1) % parg->total;
	//ptr_b로 다 보냈다가 ptr_a로 다 보냈을 경우를 생각해서.
}

void pb(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	if (ptr_a->current == 0)
	{
		ft_putstr_fd("No more in stack a.\n", 1);
		return;
	}
	if (ptr_b->front == 0)
		ptr_b->front = parg->total -1;//조건문을 탈출하는 그런게 없으니까
	else if ((ptr_b->front == ptr_b->rear) && (ptr_b->current == 0))
		ptr_b->front = ptr_b->rear;
	else
		ptr_b->front = (ptr_b->front - 1) % parg->total;
	ptr_b->stack[ptr_b->front] = ptr_a->stack[ptr_a->front];
	(ptr_a->current)--;
	(ptr_b->current)++;
	if (ptr_a->front == ptr_a->rear)
		return;
	else
		ptr_a->front = (ptr_a->front + 1) % parg->total;
}