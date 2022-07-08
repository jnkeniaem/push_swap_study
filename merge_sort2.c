#include "pushswap.h"

#include <stdio.h>
void split_to_a(t_arg *parg, t_a *ptr_a, t_b *ptr_b, t_merge *pmerge)
{
    int *temp;
    int i;
    int quo_temp;

    pmerge->quo = pmerge->quo / 3;
    quo_temp = pmerge->quo;
    pmerge->remainder = quo_temp % 3;
    temp = malloc(sizeof(int) * (pmerge->quo + pmerge->remainder));
    
}