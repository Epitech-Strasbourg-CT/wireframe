/*
** disp_vertex.c for wireframe in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 15:32:39 2016 Cédric Thomas
** Last update Sat Dec 10 17:33:49 2016 Cédric Thomas
*/
#include <stdlib.h>
#include <math.h>
#include "wireframe.h"
#include "my.h"

static void	rotate_x(sfVector3f *vec, double deg)
{
  double	alpha;
  double	tmp;

  tmp = vec->y;
  alpha = deg * M_PI / 180;
  vec->y = tmp * cos(alpha) - vec->z * sin(alpha);
  vec->z = tmp * sin(alpha) + vec->z * cos(alpha);
}

static void	rotate_y(sfVector3f *vec, double deg)
{
  double	alpha;
  double	tmp;

  tmp = vec->x;
  alpha = deg * M_PI / 180;
  vec->x = tmp * cos(alpha) + vec->z * sin(alpha);
  vec->z = tmp * -sin(alpha) + vec->z * cos(alpha);
}

static void	rotate_z(sfVector3f *vec, double deg)
{
  double	alpha;
  double	tmp;

  tmp = vec->x;
  alpha = deg * M_PI / 180;
  vec->x = tmp * cos(alpha) - vec->y * sin(alpha);
  vec->y = tmp * sin(alpha) + vec->y * cos(alpha);
}

sfVector2i	my_3d_projection(sfVector3f pos3d,
				 t_cam cam)
{
  sfVector2i    pos2d;

  rotate_x(&pos3d, cam.angle.x);
  rotate_z(&pos3d, cam.angle.z);
  rotate_y(&pos3d, cam.angle.y);
  pos2d.x = pos3d.x + cos(220 * M_PI / 180) * pos3d.y;
  pos2d.y = -pos3d.z + sin(220 * M_PI / 180) * pos3d.y;
  pos2d.x += cam.position.x;
  pos2d.y -= cam.position.y;
  pos2d.x *= cam.zoom;
  pos2d.y *= cam.zoom;
  return (pos2d);
}

void		my_draw_vertex(t_vertex **vertex, t_pixelbuff *buff,
			       t_cam cam, sfColor color)
{
  t_vertex      *temp;
  t_vertex      *in_temp;
  sfVector2i	pos1;
  sfVector2i	pos2;

  temp = *vertex;
  while (temp != NULL)
    {
      in_temp = temp->linked;
      while (in_temp != NULL)
	{
	  pos1 = my_3d_projection(temp->point, cam);
	  pos1.x = WIDTH / 2 + pos1.x;
	  pos1.y = HEIGHT / 2 + pos1.y;
	  pos2 = my_3d_projection(in_temp->point, cam);
	  pos2.x = WIDTH / 2 + pos2.x;
	  pos2.y = HEIGHT / 2 + pos2.y;
	  my_draw_line(buff, pos1, pos2, color);
	  in_temp = in_temp->next;
	}
      temp = temp->next;
    }
}
