/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:29:38 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/15 18:30:05 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack(t_arg *parg, t_a *pa, t_b *pb)
{
	int	i;

	i = 0;
	pa->stack = malloc(parg->total * sizeof(int));
	pb->stack = malloc(parg->total * sizeof(int));
	pa -> front = 0;
	pa -> rear = 0;
	while (i < parg->total)
	{
		pa->stack[pa->rear] = parg->num[i];
		if (pa->rear == parg->total -1)
			break ;
		pa->rear = (pa->rear + 1) % (parg->total);
		i++;
	}
	pb -> front = 0;
	pb->rear = parg->total - 1;
	pa->current = parg->total;
	pb->current = 0;
}
