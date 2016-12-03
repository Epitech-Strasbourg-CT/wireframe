##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Wed Nov 23 12:05:55 2016 Cédric Thomas
##

SRC	=	main.c				\
		draw/vertex.c			\
		misc/vertex_free.c		\
		src/my_draw_line.c		\
		src/my_isometric_projection.c	\
		src/my_parallel_projection.c	\
		src/my_put_pixel.c		\
		parse/parse.c 			\
		parse/link_wireframe.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wireframe

LIB_F	=	./lib/

LIB	=	-lm -lc_graph_prog -lmy -lmysf

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -g	


all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIB_F) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONE: all clean fclean re
