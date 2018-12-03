##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC 	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

all:		$(OBJ)
	ar -rc libyocsfml.a *.o
	cp libyocsfml.a ../../

lib:		$(OBJ)
	ar -rc libyocsfml.a *.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f libyocsfml.a
	rm -f ../../libyocsfml.a

re:	clean all
