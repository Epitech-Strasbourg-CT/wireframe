/*
** mysf.h for libmysf.h in /home/cedric/delivery/MUL/libmysf
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 18:18:21 2016 Cédric Thomas
** Last update Mon Nov 21 08:45:28 2016 Cédric Thomas
*/
#ifndef MYSF_H_
# define MYSF_H_

#include <SFML/Graphics.h>

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
**draw
**
**draw_line.c
*/
void			put_line(t_pixelbuff *buff,
				 sfVector2f from,
				 sfVector2f to,
				 sfColor color);

/*
**draw_pixel.c
*/
void			put_pixel(t_pixelbuff *buf,
				  int x,
				  int y,
				  sfColor color);

/*
**draw_square.c
*/
int			put_square(sfVector2i *pos,
				   sfVector2i *size,
				   t_pixelbuff *buff,
				   sfColor color);
/*
**draw_vertex.c
*/
void	draw_vertex(t_vertex **vertex, t_pixelbuff *buff,
		    double angleH, double angleV);
/*
**type
**
**window.c
*/
sfRenderWindow		*window_create(char *n,
				       int w,
				       int h);

/*
**vectori.c
*/
sfVector2i		myVector2i(int x, int y);

/*
**vectorf.c
*/
sfVector2f		myVector2f(double x, double y);
sfVector3f		myVector3f(double x, double y, double z);

/*
**pixelbuff.c
*/
t_pixelbuff             *pixelbuff_create(int width, int height);
void			free_pixelbuff(t_pixelbuff *buffer);

/*
**vertex.c
*/
int	fill_vertex(t_vertex **ll, int size);
int	cat_vertex(t_vertex **la, t_vertex **lb);
int	rev_vertex(t_vertex **ll);
int	put_vertex(t_vertex **ll, sfVector3f vertex, int connect);
int	connect_vertex(t_vertex **ll, int index1, int index2, int connect);

/*
**convert
**
**image.c
*/
t_image			t_image_create(double x, double y);

/*
**point.c
*/
sfVector2f              point_to_iso(sfVector3f pos3d,
				     double angleH, double angleV);
sfVector2i		center(sfVector2i pos, t_pixelbuff buff);

#endif /* !MYSF_H_ */
