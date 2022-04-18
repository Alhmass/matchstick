#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library making file.
#

SRC	=	sources/main.c \
		sources/matchstick.c \
		sources/game_board.c \
		sources/game_init.c \
		sources/player_turn.c \
		sources/game_lib.c \
		sources/ai_turn.c \
		sources/matches_input.c


OBJ = 	$(SRC:.c=.o)

NAME = matchstick

LDFLAGS = -L./sources/lib/

LDLIBS = -lmy

CPPFLAGS = -I./includes

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	make -C sources/lib/

clean:
	make clean -C sources/lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C sources/lib/
	rm -f $(NAME)

re: fclean all

cc: re clean

.PHONY: all clean fclean re cc lib
