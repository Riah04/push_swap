# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andriraz <andriraz@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 11:36:19 by andriraz          #+#    #+#              #
#    Updated: 2026/03/25 11:36:21 by andriraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap.a

HEADER = push_swap.h

SRCS =	ft_atol.c push_swap_utils.c ft_split.c parse.c push.c rotate.c swap.c reverse_rotate.c algo_simple.c compte_disorder.c ft_sqrt.c algo_medium.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
