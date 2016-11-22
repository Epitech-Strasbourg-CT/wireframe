##
## Makefile for mysf in /home/cedric/delivery/MUL/libmysf/draw
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Fri Nov 18 20:34:17 2016 Cédric Thomas
## Last update Mon Nov 21 08:38:35 2016 Cédric Thomas
##

SRC     =	draw/draw_line.c	\
		draw/draw_pixel.c	\
		draw/draw_square.c	\
		draw/draw_vertex.c	\
		type/window.c		\
		type/vectori.c		\
		type/vectorf.c		\
		type/vertex.c		\
		type/pixelbuff.c	\
		convert/image.c		\
		convert/point.c

OBJ     =       $(SRC:.c=.o)

INCLUDE =       mysf.h

NAME    =       libmysf.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(INCLUDE) ../../include
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all                 
