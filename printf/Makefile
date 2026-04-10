NAME =  libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_dig_count.c \
	ft_check_format.c \
	ft_printf.c \
	ft_conv_base.c \
	ft_putnbr.c \
	ft_printfs.c \
	ft_2d.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
