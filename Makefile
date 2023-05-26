CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c

OBJ = $(SRC:.c=.o)

NAME = a.out

all : $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -L. -lft

$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a .
	ar rcs $(NAME) $(OBJ) 

clean :
	make fclean -C libft
	rm -f $(OBJ)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re