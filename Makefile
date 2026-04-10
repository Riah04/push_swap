# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 11:36:19 by andriraz          #+#    #+#              #
#    Updated: 2026/04/10 14:02:14 by nmariah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap
HEADER = push_swap.h

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS =	ft_atol.c \
	push_swap_utils.c \
	ft_split.c \
	parse.c \
	push.c \
	rotate.c \
	swap.c \
	reverse_rotate.c \
	algo_simple.c \
	count_disorder.c \
	algo_medium.c \
	get_max.c \
	algo_complex.c \
	main.c \
	check_flag.c \
	push_swap_util_02.c \
	adaptive.c \
	push_swap.c \
	bench.c \
	ft_three_and_five.c \
	algo_utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I. -I$(PRINTF_DIR)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME) 

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) clean

re: fclean all

.PHONY : all clean fclean re
