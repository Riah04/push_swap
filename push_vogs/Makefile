# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 11:36:19 by andriraz          #+#    #+#              #
#    Updated: 2026/04/08 15:27:35 by nmariah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap

HEADER = push_swap.h

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
	bench.c \
	adaptive.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY : all clean fclean re
