NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Werror -Wall -c
SRC = ft_printf.c hexadecimal_tools.c
OBJ = libft/libft.a $(SRC:.c=.o) 

libft/libft.a :
	cd libft && make bonus && cd ../
$(NAME) : all
all: $(OBJ)
	ar -rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all






test :
	cd libft && make bonus && cd ../
	cp libft/libft.a .
