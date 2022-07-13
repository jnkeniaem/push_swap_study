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
}t_merge;

typedef struct
{
	int total;
	int *num;
	int	max;
}t_arg;

typedef struct
{
	int	end_a;
	int	end_b;
	int	ascen;
	int descen;
	int size;
}t_map;

void check_arg(int argc, char **argv, t_arg *parg);
void if_double_quote(int argc, char **argv, t_arg *parg);
void check_argc(int argc);
void check_space(int argc, char **argv);
void check_int(char *str);
void check_int_range(char *str);
void check_duplicate(t_arg *parg);
int	ft_available(char c, char *str);
int	ft_strcmp(char *s1, char *s2);
void ft_error(char *message);
void if_satisfied(t_arg *parg);
// void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb);
void init_stack(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void sa(t_arg *parg, t_a *ptr_a);
void sb(t_arg *parg, t_b *ptr_b);
void ss(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void pa(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void pb(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void ra(t_arg *parg, t_a *ptr_a);
void rb(t_arg *parg, t_b *ptr_b);
void rr(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void rra(t_arg *parg, t_a *ptr_a);
void rrb(t_arg *parg, t_b *ptr_b);
void rrr(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void ft_sort_ascend(int *tab, int size);
void ft_sort_descend(int *tab, int size);
void ft_max(t_arg *parg);
void if_below_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void if_2(t_arg *parg, t_a *ptr_a, t_b *ptr_b, int flag);
// void if_2(t_arg *parg, t_a *ptr_a);
void put_instruction(t_arg *parg, t_a *ptr_a, t_b *ptr_b, char *str);
void indexing(t_arg *parg, t_a *ptr_a);
void if_exceed_5(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void a_to_b(t_arg *parg, t_a *ptr_a, t_b *ptr_b, int chunk);
void find_max(t_arg *parg, t_b *ptr_b, int size);
void b_to_a(t_arg *parg, t_a *ptr_a, t_b *ptr_b);
void test_print_stack(t_a *ptr_a, t_b *ptr_b, t_arg *parg);
void test_print_stack_b(t_a *ptr_b, t_arg *parg);

#endif

