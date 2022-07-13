/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:16:11 by jeekim            #+#    #+#             */
/*   Updated: 2022/07/13 20:55:04 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void test_print_stack(t_a *ptr_a, t_b *ptr_b, t_arg *parg)
{
    int i;

    i = 0;
    printf("==========\nstack a\n==========\n");
    while (i < ptr_a->current)
    {
        printf("%d\n", ptr_a->stack[(ptr_a->front + i) % parg->total]);
        i++;
    }
    printf("==========\nBOT    \n==========\n");
    i = 0;
    printf("==========\nstack b\n==========\n");
    while (i < ptr_b->current)
    {
        printf("%d\n", ptr_b->stack[(ptr_b->front + i) % parg->total]);
        i++;
    }
    printf("==========\nBOT    \n==========\n");
}
void test_print_stack_b(t_a *ptr_b, t_arg *parg)
{
    int i;

    i = 0;
    printf("==========\nstack b\n==========\n");
    while (i < ptr_b->current)
    {
        printf("%d\n", ptr_b->stack[(ptr_b->front + i) % parg->total]);
        i++;
    }
    printf("==========\nBOT    \n==========\n");
}