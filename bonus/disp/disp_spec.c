/*
** disp_spec.c for bonus in /home/cedric/delivery/MUL/wireframe/bonus
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Dec  9 20:23:51 2016 Cédric Thomas
** Last update Sat Dec 10 11:29:34 2016 Cédric Thomas
*/
#include <stdio.h>
#include <math.h>
#include "wireframe.h"
#include "my.h"

static void	rotate(sfVector3f *vec, double deg)
{
  double	tmp;

  tmp = vec->x;
  vec->x = tmp * cos(deg) + vec->z * sin(deg);
  vec->z = tmp * -sin(deg) + vec->z * cos(deg);
}

static void		add_circley(t_vertex **ll, double rayon,
				    int precision, double angle)
{
  double	i;
  sfVector3f	vec;

  i = 1;
  while (i <= M_PI * 2 + 1.01)
    {
      vec.z = 0;
      vec.x = rayon * cosf(i);
      vec.y = rayon * sinf(i);
      rotate(&vec, angle);
      if (i == 1)
	put_vertex(ll, vec, 0);
      else
	put_vertex(ll, vec, 1);
      i += M_PI / precision;
    }
}

void	form(t_vertex **bot, t_vertex **top, char *prec, char *r)
{
  double	i;
  double	rayon;
  double	precision;

  i = 0;
  rayon = my_getnbr(r);
  precision = my_getnbr(prec);
  *bot = NULL;
  *top = NULL;
  while (i < M_PI)
    {
      add_circley(bot, rayon, precision, i);
      i += M_PI * 5 / precision;
    }
}
