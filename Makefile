# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmariah <nmariah@student.42antananarivo    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 11:36:19 by andriraz          #+#    #+#              #
#    Updated: 2026/04/12 15:18:57 by nmariah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker
HEADER = push_swap.h

PRINTF_DIR = printf
BONUS_DIR = bonus
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
	check_flag.c \
	push_swap_util_02.c \
	adaptive.c \
	push_swap.c \
	bench.c \
	ft_three_and_five.c \
	algo_utils.c 

MAIN_PS = main.c

SRC_BONUS = $(BONUS_DIR)/get_next_line_bonus.c \
	$(BONUS_DIR)/get_next_line_utils_bonus.c \
	$(BONUS_DIR)/checker.c \
	$(BONUS_DIR)/bonus_utils.c \
	$(BONUS_DIR)/parse_bonus.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -I$(PRINTF_DIR) -I$(BONUS_DIR)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
OBJS_COMMON = $(filter-out main.o, $(OBJS))
OBJ_MAIN_PS   = $(MAIN_PS:.c=.o)

all: $(PRINTF) $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME) : $(OBJS) $(OBJ_MAIN_PS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(OBJ_MAIN_PS) $(PRINTF) -o $(NAME)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(OBJS_BONUS) $(OBJS_COMMON) $(PRINTF)
	$(CC) $(CFLAGS) -g $(OBJS_BONUS) $(OBJS_COMMON) $(PRINTF) -o $(CHECKER_NAME)

clean:
	rm -f $(OBJS) $(OBJ_MAIN_PS) $(OBJS_BONUS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY : all clean fclean re bonus
