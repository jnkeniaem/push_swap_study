#include "pushswap.h"
#include <stdio.h>
void pa(t_arg *arg, t_a *ptr_a, t_b *ptr_b) // a에 뭔가 남아있을 경우와 없는 경우
{
	if (ptr_b->current == 0)
	{
		ft_putstr_fd("No more in stack b.\n", 1);
		return;
	}
	if (ptr_a->front == 0)
		ptr_a->front = arg->total - 1;
	else
		ptr_a->front = (ptr_a->front - 1) % arg->total;
	ptr_a->stack[ptr_a->front] = ptr_b->stack[ptr_b->front];
	(ptr_b->current)--;
	(ptr_a->current)++;
	if (ptr_b->front == ptr_b->rear)
		return ;
	else
		ptr_b->front = (ptr_b->front + 1) % arg->total;
	ptr_a->rear = (ptr_a->front + ptr_a->current - 1) % arg->total;
	//ptr_b로 다 보냈다가 ptr_a로 다 보냈을 경우를 생각해서.
}

void pb(t_arg *arg, t_a *ptr_a, t_b *ptr_b)
{
	if (ptr_a->current == 0)
	{
		ft_putstr_fd("No more in stack a.\n", 1);
		return;
	}
	if (ptr_b->front == 0)
		ptr_b->front = arg->total -1;
	else
		ptr_b->front = (ptr_b->front - 1) % arg->total;
	ptr_b->stack[ptr_b->front] = ptr_a->stack[ptr_a->front];
	(ptr_a->current)--;
	(ptr_b->current)++;
	if (ptr_a->front == ptr_a->rear)
		return;
	else
		ptr_a->front = (ptr_a->front + 1) % arg->total;
	ptr_b->rear = (ptr_b->front + ptr_b->current - 1) % arg->total;
	//rear를 맨 밑의 요소를 가리키게하공
}