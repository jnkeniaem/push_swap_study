#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "libft/libft.h"
#include <stdlib.h> // exit

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

#endif