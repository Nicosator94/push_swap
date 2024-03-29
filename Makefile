CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -g3

SRC = push_swap.c \
		parsing_int.c \
		long_atoi.c \
		init_list.c \
		rule_push.c \
		rule_reverse_rotate.c \
		rule_rotate.c \
		rule_swap.c \
		sorting.c \
		mini_sorting.c \
		sorting_utils.c \
		part_1.c \
		part_2.c \
		wheel.c

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

NAME = push_swap

all : $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. -lft

$(NAME) : $(OBJ) 
	make -C libft
	cp libft/libft.a .

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	make fclean -C libft
	rm -f $(OBJ) $(DEP)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re