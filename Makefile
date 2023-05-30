CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

NAME = a.out

all : $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -L. -lft

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