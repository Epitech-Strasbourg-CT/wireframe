##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Fri Dec  9 21:11:17 2016 Cédric Thomas
##

SRC	=	main.c				\
		position/position_vertex.c	\
		misc/misc_vector.c		\
		misc/misc_pixelbuff.c		\
		misc/misc_vertex.c		\
		misc/misc_win.c			\
		disp/disp.c			\
		disp/disp_vertex.c		\
		disp/disp_spec.c		\
		parse/parse.c			\
		parse/parse_wireframe.c		\
		src/my_draw_line.c		\
		src/my_put_pixel.c		\
		src/my_parallel_projection.c	\
		src/my_isometric_projection.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wireframe

LIB_F	=	./lib/

LIB	=	-lm -lc_graph_prog -lmy

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
