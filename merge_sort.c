#include "pushswap.h"

#include <stdio.h>
//첫번째 분할
void m_split(t_arg *arg, t_a *ptr_a, t_b *ptr_b, t_merge *pmerge)
{
	int	*temp;
	int	i;

	pmerge->quo = arg->total / 3;
	pmerge->remainder = arg->total % 3; // 가운데 삼각형에 붙여줘야해
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
		pb(arg, ptr_a, ptr_b);
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		temp[i] = ptr_a->stack[ptr_a->front + i];
	ft_sort_ascend(temp, pmerge->quo);
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		ptr_a->stack[ptr_a->front + i] = temp[i];
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		pb(arg, ptr_a, ptr_b);
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		temp[i] = ptr_a->stack[ptr_a->front + i];
	ft_sort_ascend(temp, pmerge->quo);
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		ptr_a->stack[ptr_a->front + i] = temp[i];
	i = -1;
	while (++i < pmerge->quo + pmerge->remainder)
		pb(arg, ptr_a, ptr_b);
	free(temp);
}

void ft_merge(t_arg *arg, t_a *ptr_a, t_b *ptr_b, t_merge *pmerge)
{
	int	i;

	i = -1;
	while (++i < pmerge->quo)
		pa(arg, ptr_a, ptr_b);
	pmerge->p1 = ptr_a->rear;
	pmerge->p2 = ptr_b->front;
	pmerge->p3 = ptr_b->rear;
	(ptr_a->front - 1) % arg->total = the_highest_is // 만들 삼각형 제일 밑에다 제일 큰수
}

