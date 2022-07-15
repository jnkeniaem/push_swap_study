/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:25:23 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/15 18:26:42 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	if_satisfied(t_arg *parg)
{
	int	i;

	i = 0;
	if (parg->total == 1)
		exit(EXIT_SUCCESS);
	while (i < parg->total - 1)
	{
		if (parg->num[i] < parg->num[i + 1])
			i++;
		else
			return ;
	}
	exit(EXIT_SUCCESS);
}

void	check_int(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (ft_available(*(str + i), "+-"))
		i++;
	while (ft_available(*(str + i), "0123456789"))
	{
		flag = 1;
		i++;
	}
	if (!((flag == 1) && (*(str + i) == '\0')))
		ft_error("Error\nNot an integer.");
}

void	check_int_range(char *str)
{
	int			minus;
	long long	result;
	int			i;

	minus = 1;
	result = 0;
	i = 0;
	while (ft_available(*(str + i), "+-"))
	{
		if (*(str + i) == '-')
			minus *= -1;
		i++;
	}
	while (ft_available(*(str + i), "0123456789"))
	{
		result *= 10;
		result += *(str + i) - '0';
		if ((result > 2147483647 && minus == 1)
			|| (result > 2147483648 && minus == -1))
			ft_error("Error\nOut of int range.");
		i++;
	}
}

void	check_duplicate(t_arg *parg)
{
	int	i;
	int	j;

	i = 0;
	while (i < parg->total - 1)
	{
		j = i + 1;
		while (j < parg->total)
		{
			if (parg->num[i] == parg->num[j])
				ft_error("Error\nDuplicate here.");
			else
				j++;
		}
		i++;
	}
}
