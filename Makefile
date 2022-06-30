# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 10:42:41 by jeekim            #+#    #+#              #
#    Updated: 2022/06/30 19:40:05 by jeekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
CC	=	gcc
CCFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f
LIBFT_IFLAG	=	-I./libft

LIBFT_PATH	=	./libft/
LIBFT_SRCS	=	$(addprefix $(LIBFT_PATH), ft_putstr_fd.c ft_strlen.c ft_putchar_fd.c ft_putnbr_fd.c ft_atoi.c)
LIBFT_OBJS	=	$(LIBFT_SRCS:.c=.o)

SRCS	=	main.c check_arg.c utils.c check_arg2.c init_stack.c \
			swap.c push.c rotate.c reverse_rotate.c
SRCS_B	=	
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

ifdef	WITH_BONUS
	OBJECTS	=	$(OBJS_B)
else
	OBJECTS	=	$(OBJS)
endif

all	:	$(NAME)

bonus	:
	make WITH_BONUS=1 all

.c.o	:
	$(CC) $(CCFLAGS) $(LIBFT_IFLAG) -c $< -o $@

$(NAME)	:	$(LIBFT_OBJS) $(OBJECTS)
	make all -C ./libft
	$(CC) $(CCFLAGS) $(LIBFT_IFLAG) $^ -o $@

clean	:
	$(RM) $(LIBFT_OBJS) $(OBJS_B) $(OBJS)
	make clean -C ./libft

fclean	: clean
	$(RM) $(NAME) 
	make fclean -C ./libft

re	:	fclean all

.PHONY	:	all bonus clean fclean re