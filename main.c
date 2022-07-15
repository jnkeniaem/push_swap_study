/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:39:27 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/15 19:40:28 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_a		a;
	t_b		b;
	t_arg	arg;
	int		i;

	i = 0;
	check_arg(argc, argv, &arg);
	init_stack(&arg, &a, &b);
	indexing(&arg, &a);
	if (a.current <= 5)
		if_below_5(&arg, &a, &b);
	else
		if_exceed_5(&arg, &a, &b);
	free(arg.num);
	free(a.stack);
	free(b.stack);
	// system("leaks push_swap");
}
