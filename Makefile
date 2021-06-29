NAME = libftprintf.a

SRC = ft_printf.c \
		ft_print_string.c \
		ft_print_char.c \
		ft_print_int.c \
		ft_print_unsigned_int.c \
		ft_print_hex.c \
		ft_print_address.c \
		ft_print_percent.c \
		ft_print_unsigned_hexa.c \
		ft_printf_utils.c \
		ft_printf_utils_num.c \
		ft_printf_big_utils.c \
		ft_placeholders.c

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all re m clean fclean bonus


