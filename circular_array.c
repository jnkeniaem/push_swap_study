#include "pushswap.h"
#include <stdio.h>

void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb)//a stack 만들기?
{
	int	i;

	i = 1;
	p_ca -> max_arg = argc - 1;
	pa->stack = malloc(p_ca -> max_arg * sizeof(int));
	pb->stack = malloc(p_ca -> max_arg * sizeof(int));
	pa -> front = 0;
	pa -> rear = 0;
	while (i < argc)
	{
		pa->stack[pa->rear] = ft_atoi(argv[i]);//ft_atoi.. 다른 문자열을 정수로 바꿔주는것도 생각해보자 지금은 그냥 이게 생각나서 바로 하는거궁
		if (pa->rear == p_ca -> max_arg -1)
			break;
		pa->rear = (pa->rear + 1) % (p_ca->max_arg);
		i++;
	}
	pb -> front = 0;
	pb -> rear = p_ca->max_arg -1;
	pa->current = argc -1;
	pb->current = 0;
}

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