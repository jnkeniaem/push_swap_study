#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "libft/libft.h"
#include <stdlib.h> // exit

typedef struct 
{
	int	*stack;
	int front;
	int rear;
	int current;
}t_a;

typedef struct 
{
	int	*stack;
	int front;
	int rear;
	int current;
}t_b;

typedef struct // s_안써도 되나?
{
	int remainder;
	int	quo;
	int	*p1;
	int	*p2;
	int	*p3;
}t_merge;

typedef struct
{
	int total;
	int *num;
}t_arg;

void check_arg(int argc, char **argv, t_arg *arg);
void if_double_quote(int argc, char **argv, t_arg *arg);
void check_argc(int argc);
void check_space(int argc, char **argv);
void check_int(char *str);
void check_int_range(char *str);
void check_duplicate(t_arg *arg);
int	ft_available(char c, char *str);
int	ft_strcmp(char *s1, char *s2);
void ft_error(char *message);
void if_satisfied(t_arg *arg);
// void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb);
void init_stack(t_arg *arg, t_a *ptr_a, t_b *ptr_b);
void sa(t_arg *arg, t_a *ptr_a);
void sb(t_arg *arg, t_b *ptr_b);
void ss(t_arg *arg, t_a *ptr_a, t_b *ptr_b);
void pa(t_arg *arg, t_a *ptr_a, t_b *ptr_b);
void pb(t_arg *arg, t_a *ptr_a, t_b *ptr_b);
void ra(t_arg *arg, t_a *ptr_a);
void rb(t_arg *arg, t_b *ptr_b);
void rr(t_arg *arg, t_a *ptr_a, t_b *ptr_b);
void rra(t_arg *arg, t_a *ptr_a);
void rrb(t_arg *arg, t_b *ptr_b);
void rrr(t_arg *arg, t_a *ptr_a, t_b *ptr_b);
void ft_sort_ascend(int *tab, int size);
void ft_sort_descend(int *tab, int size);
void m_split(t_arg *arg, t_a *ptr_a, t_b *ptr_b, t_merge *pmerge);
int the_highest_is(t_merge *pmerge);

#endif