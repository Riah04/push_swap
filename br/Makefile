# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 11:36:19 by andriraz          #+#    #+#              #
#    Updated: 2026/03/29 14:59:06 by nmariah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap

HEADER = push_swap.h

SRCS =	ft_atol.c push_swap_utils.c ft_split.c parse.c push.c rotate.c swap.c reverse_rotate.c algo_simple.c compte_disorder.c algo_medium.c get_max.c algo_complexe.c main.c check_flag.c push_swap_util_02.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
