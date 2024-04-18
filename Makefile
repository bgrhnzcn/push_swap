SRCS = main.c iterators.c parser.c pushes.c reverse_rotates.c rotates.c \
	swaps.c target.c sorting.c do_operations.c ft_atol.c

OBJ = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBFTPRINTF)

$(LIBFT):
	cd libft && make

$(LIBFTPRINTF):
	cd ft_printf && make

clean:
	rm -f *.o
	cd libft && make fclean
	cd ft_printf && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean libs