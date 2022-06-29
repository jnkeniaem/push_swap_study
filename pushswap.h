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

void check_arg(int argc, char **argv);
void check_argc(int argc);
void check_int(char **argv, int h);
void check_int_range(char **argv, int h);
void check_duplicate(int argc, char **argv);
int	ft_available(char c, char *str);
int	ft_strcmp(char *s1, char *s2);
void ft_error(int i);
void repetitive_statement(int argc, char **argv);
int if_satisfied(int argc, char **argv);
void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb);
void current_arg(t_a *pa, t_b *pb);
void sa(t_a *pa, t_b *pb);
void sb(t_a *pa, t_b *pb);
void ss(t_a *pa, t_b *pb);
void pa(t_circular_ary *p_ca, t_a *pa, t_b *pb);
void pb(t_circular_ary *p_ca, t_a *pa, t_b *pb);
void ra(t_circular_ary *p_ca, t_a *pa);
#endif