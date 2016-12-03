/*
** wireframe.h for wireframe in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 19 10:30:00 2016 Cédric Thomas
** Last update Sat Dec  3 16:28:06 2016 Cédric Thomas
*/
#ifndef WIREFRAME_H_
# define WIREFRAME_H_

#include <SFML/Graphics.h>

# define X_SQ 2
# define Y_SQ 2
# define Z_SQ 2

# define WIDTH 1200
# define HEIGHT 960

typedef struct		s_cam
{
  sfVector3f		angle;
  sfVector2i		position;
  double			zoom;
}			t_cam;

typedef struct		s_framebuffer
{
  sfUint8		*pixels;
  int			x;
  int			y;
}			t_framebuffer;

typedef t_framebuffer t_pixelbuff;

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
**WIREFRAME
*/

/*
**WIREFRAME_PARSE
*/

/*
**parse.c
*/
char	*my_read(char *path);

/*
**parse_wireframe.c
*/
sfVector2i	wireparse(t_vertex **bot, t_vertex **top, char *path);

/*
**WIREFRAME_MISC
*/

/*
**misc_vector.c
*/
sfVector2f	myvector2f(double x, double y);
sfVector3f	myvector3f(double x, double y, double z);
sfVector2i	myvector2i(int x, int y);

/*
**misc_vertex.c
*/
int	rev_vertex(t_vertex **ll);
int	put_vertex(t_vertex **ll, sfVector3f vertex, int connect);
int	connect_vertex(t_vertex **ll, int index1, int index2, int connect);
int	fill_vertex(t_vertex **ll, int size);
void	free_vertex(t_vertex **vertex, int recur);

/*
**misc_pixelbuff.c
*/
t_pixelbuff	*pixelbuff_create(int width, int height);
void		free_pixelbuff(t_pixelbuff *buffer);

/*
**mic_win.c
*/
sfRenderWindow	*window_create(char *n, int w, int h);
t_image		t_image_create(double x, double y);

/*
**WIREFRAME_POSITION
*/

/*
**position_vertex.c
*/
sfVector2i	get_coeff(sfVector2i dim);
void		set_vertex_position(t_vertex **bot,
				    t_vertex **top, sfVector2i dim);

/*
**WIREFRAME_DISP
*/

/*
**disp.c 
*/
void    draw_this(t_vertex **bot, t_vertex **top, sfVector2i dim);

/*
**disp_vertex.c
*/
void		my_draw_vertex(t_vertex **vertex, t_pixelbuff *buff,
		       t_cam cam, sfColor color);
sfVector2i	my_3d_projection(sfVector3f pos3d,
				 t_cam cam);
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
