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
    int max_arg;
}t_circular_ary;

typedef struct
{
    int total;
    int *num;
}t_arg;

void check_arg(int argc, char **argv, t_arg *arg);
void if_double_quote(int argc, char **argv, t_arg *arg);
void check_argc(int argc);
void check_int(char *str);
void check_int_range(char *str);
void check_duplicate(t_arg *arg);
int	ft_available(char c, char *str);
int	ft_strcmp(char *s1, char *s2);
void ft_error(char *message);
void if_satisfied(t_arg *arg);
// void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb);
void init_stack(t_arg *arg, t_a *pa, t_b *pb);
void sa(t_arg *arg, t_a *pa);
void sb(t_arg *arg, t_b *pb);
void ss(t_arg *arg, t_a *pa, t_b *pb);
void pa(t_arg *arg, t_a *pa, t_b *pb);
void pb(t_arg *arg, t_a *pa, t_b *pb);
void ra(t_arg *arg, t_a *pa);
void rb(t_arg *arg, t_b *pb);
void rr(t_arg *arg, t_a *pa, t_b *pb);
void rra(t_arg *arg, t_a *pa);
void rrb(t_arg *arg, t_b *pb);
void rrr(t_arg *arg, t_a *pa, t_b *pb);

#endif