/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:24:52 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/15 18:25:02 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_argc(int argc)
{
	if (argc == 1)
		ft_error("Error\nNeed more than 1 argument.");
}

void	check_space(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j])
		{
			if (argv[i + 1][j] == ' ')
				j++;
			else
				break ;
		}
		if (argv[i + 1][j] == 0)
			ft_error("Error\nWhite-spaced argument.");
		i++;
	}
}

void	if_double_quote_1(int argc, char **argv, t_arg *parg)
{
	int				i;
	int				j;
	char			**temp;
	unsigned int	new_idx;

	i = 0;
	parg->total = 0;
	new_idx = 0;
	while (i < argc -1)
	{
		j = 0;
		temp = ft_new_split(argv[i + 1], ' ', new_idx);
		while (temp[j])
		{
			check_int(temp[j]);
			check_int_range(temp[j]);
			j++;
			parg->total++;
		}
		free(temp);
		i++;
	}
	parg->num = malloc(sizeof(int) * parg->total);
}

void	if_double_quote_2(int argc, char **argv, t_arg *parg)
{
	int				i;
	int				j;
	int				k;
	char			**temp;
	unsigned int	new_idx;

	i = 0;
	k = 0;
	new_idx = 0;
	while (i < argc - 1)
	{
		j = 0;
		temp = ft_new_split(argv[i + 1], ' ', new_idx);
		while (temp[j])
		{
			parg->num[k] = ft_atoi(temp[j]);
			k++;
			j++;
		}
		free(temp);
		i++;
	}
}

void	check_arg(int argc, char **argv, t_arg *parg)
{
	check_argc(argc);
	check_space(argc, argv);
	if_double_quote_1(argc, argv, parg);
	if_double_quote_2(argc, argv, parg);
	check_duplicate(parg);
	if_satisfied(parg);
}
