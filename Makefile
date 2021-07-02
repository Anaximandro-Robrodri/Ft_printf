LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRC =	ft_printf.c \
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
		ft_placeholders.c

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all re m clean fclean bonus
