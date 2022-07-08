#include "pushswap.h"

int	ft_available(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
        else
            break;
	}
    return (s1[i] - s2[i]);
}

void ft_sort_ascend(int *tab, int size)
{
	int i;
	int j;
	int	temp;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		j++;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
	}
}

void ft_sort_descend(int *tab, int size)
{
	int i;
	int j;
	int temp;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		j++;
		while (i < size - 1)
		{
			if (tab[i] < tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
	}
}

//숫자 3개 비교해서 제일 큰거 고르는 함수
int the_highest_is(t_a *ptr_a, t_b *ptr_b)
{
	int	h;
	int	i;

	if (ptr_a->rear > ptr_a->front)
		h = pmerge->p1;
	else
		h = pmerge->p3;
	if (pmerge->p1 < ptr_a->rear)
		h = pmerge->p3;
	else
		h = pmerge->p1;
	if (pmerge->p2 > pmerge->p3)
		i = pmerge->p2;
	else
		i = pmerge->p3;
	if	(h > i)
		return (h);
	else
		return (i);
}