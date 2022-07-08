#include "pushswap.h"

#include <stdio.h>
//첫번째 분할
void split_to_b(t_arg *parg, t_a *ptr_a, t_b *ptr_b, t_merge *pmerge)
{//분할 정렬 다른스택에 넣어주기
	int	*temp;
	int	i;

	pmerge->quo = parg->total / 3;
	pmerge->remainder = parg->total % 3; // 가운데 삼각형에 붙여줘야해
	//(pmerge->quo * n - 1) - ptr_a->front == [0]~[pmerge->quo - 1] : quo
	//첫번째 그룹 정렬해주기
	temp = malloc(sizeof(int) * (pmerge->quo + pmerge->remainder));
	i = -1;
	while (++i < pmerge->quo)
		temp[i] = ptr_a->stack[ptr_a->front + i];
	ft_sort_descend(temp, pmerge->quo);
	i = -1;
	while (++i < pmerge->quo)
		ptr_a->stack[ptr_a->front + i] = temp[i];
	i = -1;
	while (++i < pmerge->quo)
		pb(parg, ptr_a, ptr_b);
	//
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		temp[i] = ptr_a->stack[ptr_a->front + i];
	ft_sort_ascend(temp, pmerge->quo + pmerge->remainder);
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		ptr_a->stack[ptr_a->front + i] = temp[i];
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		pb(parg, ptr_a, ptr_b);
	//////
	i = -1;
	while (++i < pmerge->quo)
		temp[i] = ptr_a->stack[ptr_a->front + i];
	ft_sort_ascend(temp, pmerge->quo);
	i = -1;
	while (++i < pmerge->quo)
		ptr_a->stack[ptr_a->front + i] = temp[i];
	i = -1;
	while (++i < pmerge->quo)
		pb(parg, ptr_a, ptr_b);
	free(temp);
}

void ft_merge_to_a(t_arg *parg, t_a *ptr_a, t_b *ptr_b, t_merge *pmerge)
{
	int	i;

	i = -1;
	while (++i < pmerge->quo)
		pa(parg, ptr_a, ptr_b);
	// 만들 삼각형 제일 밑에다 제일 큰수
	i = 0;
	
	// while (i < parg->total) // 3개의 삼각형이 다 넣어질때까지
	while (i < parg->total) // 3개의 삼각형이 다 넣어질때까지
	{
		if (ptr_a->stack[ptr_a->rear] == parg->max && ptr_b->current == 0)
			break;
		else if (ptr_b->front == ptr_b->rear)
		{
			//if (ptr_b->current == 0 && ptr_a->stack[ptr_a->rear] != parg->max)
			if (ptr_b->current && (ptr_a->stack[ptr_a->rear] == parg->max 
			|| (ptr_a->stack[ptr_a->rear] < ptr_b->stack[ptr_b->front])))
				pa(parg, ptr_a, ptr_b);
			else if (ptr_b->current == 0 || (ptr_b->current 
			&& (ptr_a->stack[ptr_a->rear] > ptr_b->stack[ptr_b->front])))
				//35872 1 경우
				rra(parg, ptr_a);
		}
		else if (ptr_a->stack[ptr_a->rear] == parg->max) //제일 큰게 밑에 가 있다면 b front b rear만 비교
		{
			if (ptr_b->stack[ptr_b->front] > ptr_b->stack[ptr_b->rear])
				pa(parg, ptr_a, ptr_b);
			else
			{
				if (ptr_b->current == 0)
					break;
				rrb(parg, ptr_b);
				pa(parg, ptr_a, ptr_b);
			}
		}
		else if ((ptr_a->stack[ptr_a->rear] > ptr_b->stack[ptr_b->front]) 
		&& (ptr_a->stack[ptr_a->rear] > ptr_b->stack[ptr_b->rear]))
			rra(parg, ptr_a);
		else if ((ptr_b->stack[ptr_b->front] > ptr_a->stack[ptr_a->rear]) 
		&& (ptr_b->stack[ptr_b->front] > ptr_b->stack[ptr_b->rear]))
			pa(parg, ptr_a, ptr_b);
		else
		{
			rrb(parg, ptr_b);
			pa(parg, ptr_a, ptr_b);
		}
		i++;
	}
	printf("ptr_a->front%d ptr_a->rear%d ptr_b->front%d ptr_b->rear%d\n", ptr_a->front, ptr_a->rear, ptr_b->front, ptr_b->rear);
}

