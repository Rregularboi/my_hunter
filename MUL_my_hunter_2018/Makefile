##
## EPITECH PROJECT, 2018
## make
## File description:
## no
##

SRC	=	src/my_strlen.c	\
		src/my_putinstr.c	\
		src/my_digits.c	\
		src/hud_functions.c	\
		src/my_long_putbase.c	\
		src/game.c	\
		src/game_two.c	\
		src/flags_two.c	\
		src/flags_one.c	\
		src/my_printf.c	\
		src/my_getnbr.c	\
		src/my_putbase.c    \
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c	\
		src/param.c	\
		src/param_two.c	\
		src/param_three.c	\
		src/param_four.c	\
		src/other.c	\
		src/analyse_events.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)
CFLAGS = -g3
NAME	=	my_hunter

all:		$(OBJ)
	make -C./bonus/lib/yo_csfml/
	gcc -o $(NAME) -g3 $(OBJ) bonus/libyocsfml.a -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean:
	make clean -C./bonus/lib/yo_csfml/
	rm -f $(OBJ)

fclean: clean
	make fclean -C./bonus/lib/yo_csfml/
	rm -f my_hunter

re: fclean all
