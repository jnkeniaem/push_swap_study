#include "pushswap.h"

void a_to_b(t_arg *parg, t_a *ptr_a, t_b *ptr_b, int chunk)
{
	int	i;

	i = 0;
	while (ptr_a->current)//pb하면 i++해줌
	{
		if (ptr_a->stack[ptr_a->front] <= i)
		{
			pb(parg, ptr_a, ptr_b);
			i++;
		}
		else if (ptr_a->stack[ptr_a->front] > i && ptr_a->stack[ptr_a->front] <= chunk + i)
		{
			pb(parg, ptr_a, ptr_b);
			rb(parg, ptr_b);
			i++;
		}
		else
		{
			// if (i < ptr_a->current / 2)
			// 	rra(parg, ptr_a);
			// else
				ra(parg, ptr_a);//등호에따라 결과가 달라질까?
		}
		// 왜 절반으로 했는지?
	}
}//이거 다 끝나면 삐뚤빼뚤하지만 멀리서 보면 모래시계모양임
//이제 a로 옮겨주는 과정에서 큰거 골라서 넣어줄거에요
#include <stdio.h>
void find_max(t_arg *parg, t_b *ptr_b, int size)//깊이!!!
{
	int	i;

	i = 0;
	printf("ptr_b->current %d\n", ptr_b->current);
	printf("top %d\n", ptr_b->stack[(ptr_b->front + i) % parg->total]);
	// printf("!!!%d\n", ptr_b->stack[i]);
	printf("size %d\n", size);
	while (i < ptr_b->current && ptr_b->stack[(ptr_b->front + i) % parg->total] != size)
	{
		i++;
	}
	// printf("ptr_b->current2 %d\n", ptr_b->current);
	printf("ptr_b->front + i %d\n", ptr_b->front + i);
	while ((ptr_b->front + i) % parg->total < (ptr_b->front + ptr_b->current / 2) % parg->total 
	&& (ptr_b->front + i) % parg->total <= ptr_b->rear)
	{
		rb(parg, ptr_b);
		i++;
	}
	while ((ptr_b->front + i) % parg->total >= (ptr_b->front + ptr_b->current / 2) % parg->total 
	&& (ptr_b->front + i) % parg->total > ptr_b->front)
	{
		rrb(parg, ptr_b);
		i--;
	}
}

void b_to_a(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	int	size;

	size = ptr_b->current -1;
	while (ptr_b->current)
	{
		find_max(parg, ptr_b, size);
		pa(parg, ptr_a, ptr_b);
		size--;
		test_print_stack(ptr_a, ptr_b, parg);
	}
}

#include <stdio.h>

void if_exceed_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	int	chunk;

	chunk = 0.000000053 * ptr_a->current * ptr_a->current + 0.03 * ptr_a->current + 14.5;
	a_to_b(parg, ptr_a, ptr_b, chunk);
	test_print_stack(ptr_a, ptr_b, parg);
	b_to_a(parg, ptr_a, ptr_b); // 왜 b size 1/2이 기준일까?
}