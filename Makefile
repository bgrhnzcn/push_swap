SRCS = main.c

OBJ = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) -Ilibft -Ift_printf $<

all: $(NAME)

$(NAME): libs $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a ft_printf/libftprintf.a

libs:
	cd libft && make
	cd ft_printf && make

clean:
	rm -f *.o
	cd libft && make fclean
	cd ft_printf && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean libs