#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library making file.
#

SRC	=	my_strlen.c \
		my_putstr.c \
		my_strchr.c \
		str_compare/str_compare.c \
		parser/parser.c \
		memory.c \
		my_strcpy.c \
		my_getnbr.c \
		my_put_nbr.c \
		my_putchar.c

OBJ = 	$(SRC:.c=.o)

NAME = library

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libmy.a

re: fclean all

cc: re clean

.PHONY: all clean fclean re cc lib