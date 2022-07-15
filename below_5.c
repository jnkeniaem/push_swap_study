/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:14:00 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/15 18:21:36 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	if_2(t_arg *parg, t_a *ptr_a, t_b *ptr_b, int flag)
{
	if (flag == 0 && ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
		sa(parg, ptr_a);
	else if (flag == 1
		&& ptr_b->stack[ptr_b->front] < ptr_b->stack[ptr_b->rear])
		sb(parg, ptr_b);
}

void	if_3_1(t_arg *parg, t_a *ptr_a)
{
	int	front_plus;

	front_plus = ptr_a->stack[(ptr_a->front + 1) % parg->total];
	if ((ptr_a->stack[ptr_a->front] < front_plus)
		&& (ptr_a->stack[ptr_a->front] < ptr_a->stack[ptr_a->rear])
		&& (front_plus > ptr_a->stack[ptr_a->rear]))
	{
		sa(parg, ptr_a);
		ra(parg, ptr_a);
	}
	else if ((ptr_a->stack[ptr_a->front] > front_plus)
		&& (ptr_a->stack[ptr_a->front] < ptr_a->stack[ptr_a->rear])
		&& (front_plus < ptr_a->stack[ptr_a->rear]))
		sa(parg, ptr_a);
	else if ((ptr_a->stack[ptr_a->front] < front_plus)
		&& (ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
		&& (front_plus > ptr_a->stack[ptr_a->rear]))
		rra(parg, ptr_a);
	else
		if_3_2(parg, ptr_a);
}

void	if_3_2(t_arg *parg, t_a *ptr_a)
{
	int	front_plus;

	front_plus = ptr_a->stack[(ptr_a->front + 1) % parg->total];
	if ((ptr_a->stack[ptr_a->front] > front_plus)
		&& (ptr_a->stack[ptr_a->front] > ptr_a->stack[ptr_a->rear])
		&& (front_plus < ptr_a->stack[ptr_a->rear]))
		ra(parg, ptr_a);
	else
	{
		ra(parg, ptr_a);
		sa(parg, ptr_a);
	}
}

void	if_4(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	int	median;

	median = ft_median(parg, ptr_a);
	while (ptr_a->current > 3)
	{
		while (ptr_a->stack[ptr_a->front] >= median)
			ra(parg, ptr_a);
		pb(parg, ptr_a, ptr_b);
	}
	if_3_1(parg, ptr_a);
	pa(parg, ptr_a, ptr_b);
}

void	if_below_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b)
{
	if (ptr_a->current == 2)
		if_2(parg, ptr_a, ptr_b, 0);
	else if (ptr_a->current == 3)
		if_3_1(parg, ptr_a);
	else if (ptr_a->current == 4)
		if_4(parg, ptr_a, ptr_b);
	else
		if_5(parg, ptr_a, ptr_b);
}
