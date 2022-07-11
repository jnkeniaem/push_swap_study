#include "pushswap.h"

#include <stdio.h>

void indexing(t_arg *parg, t_a *ptr_a)
{
	int *temp;
	int	i;
	int	j;

	temp = malloc(sizeof(int) * parg->total);
	i = 0;
	temp[i] = 0;
	while (i < parg->total)
	{
		j = 0;
		while (j < parg->total)
		{
			if (parg->num[i] > parg->num[j])
				temp[i]++;
			j++;
		}
		i++;
	}
	free(ptr_a->stack);
	ptr_a->stack = NULL;
	ptr_a->stack = temp;
}

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

void ft_max(t_arg *parg)
{
	int	i;

	i = 0;
	parg->max = parg->num[i];
	while (i < parg->total - 1)
	{
		if (parg->max < parg->num[i + 1])
			parg->max = parg->num[i + 1];
		i++;
	}
}
