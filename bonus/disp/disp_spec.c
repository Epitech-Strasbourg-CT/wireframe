/*
** disp_spec.c for bonus in /home/cedric/delivery/MUL/wireframe/bonus
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Dec  9 20:23:51 2016 Cédric Thomas
** Last update Fri Dec  9 23:00:11 2016 Cédric Thomas
*/
#include <math.h>
#include "wireframe.h"

static void	rotate_y(sfVector3f *vec, double deg)
{
  double        alpha;
  double        tmp;

  tmp = vec->x;
  vec->x = tmp * cos(alpha) + vec->z * sin(alpha);
  vec->z = tmp * -sin(alpha) + vec->z * cos(alpha);
}

static void		add_circle(t_vertex **ll, double rayon, int precision, double angle)
{
  double	i;
  sfVector3f	vec;

  i = 0;
  while (i <= rayon * M_PI)
    {
      vec.z = rayon * sinf(i);
      vec.x = rayon * cosf(i);
      vec.y = 0;
      rotate_y(&vec, angle);
      put_vertex(ll, vec, i);
      i += rayon * M_PI * 25 / 100;
    }
}

void	form(t_vertex **bot, t_vertex **top)
{
  int	i;
  int	rayon;
  int	precision;

  i = 0;
  rayon = 300;
  precision = 100;
  *bot = NULL;
  *top = NULL;
  while (i < M_PI)
    {
      add_circle(bot, rayon, precision, i);
      add_circle(top, rayon, precision, -i);
      i += M_PI * 5 / 100;
    }
}
