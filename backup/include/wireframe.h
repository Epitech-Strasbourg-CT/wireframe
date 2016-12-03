/*
** wireframe.h for wireframe in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 19 10:30:00 2016 Cédric Thomas
** Last update Sat Dec  3 11:25:57 2016 Cédric Thomas
*/
#include "mysf.h"

#ifndef WIREFRAME_H_
# define WIREFRAME_H_

#define BUFF_SIZE 4096000
#define X_SQ 2
#define Y_SQ 2
#define Z_SQ 2

#define WIDTH 1200
#define HEIGHT 960

typedef struct		s_pixelbuff
{
  sfUint8		*pixels;
  int			x;
  int			y;
}			t_pixelbuff;

typedef struct		s_image
{
  sfTexture             *tex;
  sfSprite              *spri;
}			t_image;

typedef struct          s_vertex
{
  sfVector3f            point;
  struct s_vertex       *linked;
  struct s_vertex       *next;
}                       t_vertex;

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
void		free_vertex(t_vertex **vertex, int recur);
sfVector2i	my_3d_projection(sfVector3f pos3d,
				       sfVector3f camera);

/*
**draw
**
**vertex.c
*/
void	my_draw_vertex(t_vertex **vertex,
		       t_pixelbuff *buff,
		       sfVector3f angle, sfColor color);
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
