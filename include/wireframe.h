/*
** wireframe.h for wireframe in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 19 10:30:00 2016 Cédric Thomas
** Last update Tue Nov 22 23:07:26 2016 Cédric Thomas
*/
#include "mysf.h"

#ifndef WIREFRAME_H_
# define WIREFRAME_H_

#define BUFF_SIZE 4096
#define X_SQ 10
#define Y_SQ 15
#define Z_SQ 10

/*
**parse
**
**parse.c
*/
char		*my_read(char *path);

/*
**link_wireframe.c
*/
sfVector2i	wireparse(t_vertex **bot, t_vertex **top, char *path);

/*
**misc
**
**vertex.c
*/
void	free_vertex(t_vertex **vertex, int recur);

/*
**draw
**
**vertex.c
*/
void	my_draw_vertex(t_vertex **vertex,
		       t_pixelbuff *buff,
		       double angle, sfColor color);
void	set_vertex_position(t_vertex **bot,
			    t_vertex **top,
			    sfVector2i dim);

/*
**src
*/
void		my_put_pixel(t_pixelbuff *buffer,
			     int x,
			     int y,
			     sfColor color);
void		my_draw_line(t_pixelbuff *buff,
			     sfVector2i from,
			     sfVector2i to,
			     sfColor color);
sfVector2i	my_parallel_projection(sfVector3f pos3d,
				       float angle);
sfVector2i	my_isometric_projection(sfVector3f pos3d);

#endif /* !WIREFRAME_H_ */
