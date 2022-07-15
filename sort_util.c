/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:13:08 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/15 18:41:21 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	put_instruction(char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "sb"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "ss"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "pa"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "pb"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "ra"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "rb"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "rr"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "rra"))
		ft_putendl_fd(str, 1);
	else if (!ft_strcmp(str, "rrb"))
		ft_putendl_fd(str, 1);
	else
		ft_putendl_fd(str, 1);
}

int	ft_median(t_arg *parg, t_a *ptr_a)
{
	int	i;
	int	j;
	int	k;

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
