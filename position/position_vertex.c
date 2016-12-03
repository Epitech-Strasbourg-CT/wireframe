/*
** position_vertex.c for wireframe in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 14:25:03 2016 Cédric Thomas
** Last update Sat Dec  3 18:30:34 2016 Cédric Thomas
*/
#include "wireframe.h"
#include "my.h"

sfVector2i	get_coeff(sfVector2i dim)
{
  sfVector2i	coef;

  coef.x = WIDTH / dim.x;
  coef.y = HEIGHT / dim.y;
  return (coef);
}

static void	link_vert(t_vertex **bot, t_vertex **top, sfVector2i dim)
{
  int		i;

  i = 0;
  while (i < dim.x * (dim.y - 1))
    {
      connect_vertex(top, i, i + dim.x, 0);
      connect_vertex(bot, i, i + dim.x, 0);
      i += 1;     
    }
}

static void	link_hori(t_vertex **bot, t_vertex **top, sfVector2i dim)
{
  int		i;

  i = 0;
  while (i < dim.y)
    {
      connect_vertex(top, i * dim.x, i * dim.x + dim.x, 1);
      connect_vertex(bot, i * dim.x, i * dim.x + dim.x, 1);
      i += 1;
    }
}

static void	link_vertex(t_vertex **bot, t_vertex **top, sfVector2i dim)
{
  int		i;
  t_vertex	*tbot;
  t_vertex	*ttop;

  i = 0;
  tbot = *bot;
  ttop = *top;
  while (i < dim.x * dim.y)
    {
      put_vertex(&(tbot->linked), ttop->point, 0);
      ttop = ttop->next;
      tbot = tbot->next;
      i += 1;
    }
  link_hori(bot, top, dim);
  link_vert(bot, top, dim);
}

void		set_vertex_position(t_vertex **bot,
				    t_vertex **top, sfVector2i dim)
{
  int		i;
  sfVector2i	coef;
  t_vertex	*tbot;
  t_vertex	*ttop;
  sfVector3f	vector;

  i = 0;
  tbot = *bot;
  ttop = *top;
  coef = get_coeff(dim);
  while (i < dim.x * dim.y)
    {
      vector.x = coef.x * (i % dim.x) - (double)(dim.x / 2 * coef.x);
      vector.y = ttop->point.y * coef.y;
      vector.z = (coef.x + coef.y) / 2 *
	(i / dim.x) - (double)(dim.x / 2 * coef.y);
      tbot->point = vector;
      tbot->point.y = 0;
      ttop->point = vector;
      ttop = ttop->next;
      tbot = tbot->next;
      i += 1;
    }
  link_vertex(bot, top, dim);
}
