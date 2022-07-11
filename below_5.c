#include "pushswap.h"

void put_instruction(t_arg *parg, t_a *ptr_a, t_b *ptr_b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		sa(parg, ptr_a);
	else if (!ft_strcmp(str, "sb"))
		sb(parg, ptr_b);
	else if (!ft_strcmp(str, "ss"))
		ss(parg, ptr_a, ptr_b);
	else if (!ft_strcmp(str, "pa"))
		pa(parg, ptr_a, ptr_b);
	else if (!ft_strcmp(str, "pb"))
		pb(parg, ptr_a, ptr_b);
	else if (!ft_strcmp(str, "ra"))
		ra(parg, ptr_a);
	else if (!ft_strcmp(str, "rb"))
		rb(parg, ptr_b);
	else if (!ft_strcmp(str, "rr"))
		rr(parg, ptr_a, ptr_b);
	else if (!ft_strcmp(str, "rra"))
		rra(parg, ptr_a);
	else if (!ft_strcmp(str, "rrb"))
		rrb(parg, ptr_b);
	else
		rrr(parg, ptr_a, ptr_b);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}

void if_2(t_arg *parg, t_a *ptr_a, t_b *ptr_b, int flag)
{
	if (flag == 0 && ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
		put_instruction(parg, ptr_a, ptr_b, "sa");
	else if (flag == 1 && ptr_b->stack[ptr_b->front] > ptr_b->stack[ptr_b->rear])
		put_instruction(parg, ptr_a, ptr_b, "sb");
}

void if_3(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	if ((ptr_a->stack[ptr_a->front] < ptr_a->stack[(ptr_a->front + 1) % parg->total])
		&& (ptr_a->stack[ptr_a->front] < ptr_a->stack[ptr_a->rear])
		&& (ptr_a->stack[(ptr_a->front + 1) % parg->total] > ptr_a->stack[ptr_a->rear]))//1 3 2
	{
		put_instruction(parg, ptr_a, ptr_b, "sa");
		put_instruction(parg, ptr_a, ptr_b, "ra");
	}
	else if ((ptr_a->stack[ptr_a->front] > ptr_a->stack[(ptr_a->front + 1) % parg->total])
		&& (ptr_a->stack[ptr_a->front] < ptr_a->stack[ptr_a->rear])
		&& (ptr_a->stack[(ptr_a->front + 1) % parg->total] < ptr_a->stack[ptr_a->rear])) //213
		put_instruction(parg, ptr_a, ptr_b, "sa");
	else if ((ptr_a->stack[ptr_a->front] < ptr_a->stack[(ptr_a->front + 1) % parg->total])
	&& (ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
	&& (ptr_a->stack[(ptr_a->front + 1) % parg->total] > ptr_a->stack[ptr_a->rear]))//231
		put_instruction(parg, ptr_a, ptr_b, "rra");
	else if ((ptr_a->stack[ptr_a->front] > ptr_a->stack[(ptr_a->front + 1) % parg->total])
	&& (ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
	&& (ptr_a->stack[(ptr_a->front + 1) % parg->total] < ptr_a->stack[ptr_a->rear]))//312
		put_instruction(parg, ptr_a, ptr_b, "ra");
	else if ((ptr_a->stack[ptr_a->front] > ptr_a->stack[(ptr_a->front + 1) % parg->total])
	&& (ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
	&& (ptr_a->stack[(ptr_a->front + 1) % parg->total] > ptr_a->stack[ptr_a->rear]))//321
	{
		put_instruction(parg, ptr_a, ptr_b, "ra");
		put_instruction(parg, ptr_a, ptr_b, "sa");
	}
}

int median(t_arg *parg, t_a *ptr_a) // 중간값 구하기
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < parg->total)
	{
		j = 0;
		k = 0;
		while (j < parg->total)
		{
			if (ptr_a->stack[j] > ptr_a->stack[i])
				k++;
			j++;
		}
		if (k == 2)
			return (ptr_a->stack[i]);
		i++;
	}
	return (0);
}

void if_4(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	while (ptr_a->current > 3)
	{
		while (ptr_a->stack[ptr_a->front] >= median(parg, ptr_a))
			put_instruction(parg, ptr_a, ptr_b, "ra");
		put_instruction(parg, ptr_a, ptr_b, "pb");
	}
	if_3(parg, ptr_a, ptr_b);
	put_instruction(parg, ptr_a, ptr_b, "pa");
}
void if_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	while (ptr_a->current > 3)
	{
		while (ptr_a->stack[ptr_a->front] >= median(parg, ptr_a))
			put_instruction(parg, ptr_a, ptr_b, "ra");
		put_instruction(parg, ptr_a, ptr_b, "pb");
	}
	if_3(parg, ptr_a, ptr_b);
	if_2(parg, ptr_a, ptr_b, 1);
	put_instruction(parg, ptr_a, ptr_b, "pa");
	put_instruction(parg, ptr_a, ptr_b, "pa");
}

void if_below_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	if (ptr_a->current == 2)
		if_2(parg, ptr_a, ptr_b, 0);
	else if (ptr_a->current == 3)
		if_3(parg, ptr_a, ptr_b);
	else if (ptr_a->current == 4)
		if_4(parg, ptr_a, ptr_b);
	else
		if_5(parg, ptr_a, ptr_b);
}