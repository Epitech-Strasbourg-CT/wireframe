/*
** vertex.c for vertex.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov 22 16:17:23 2016 Cédric Thomas
** Last update Thu Nov 24 13:04:16 2016 Cédric Thomas
*/
#include "wireframe.h"
#include "my.h"

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

void		set_vertex_position(t_vertex **bot, t_vertex **top, sfVector2i dim)
{
  int		i;
  t_vertex	*tbot;
  t_vertex	*ttop;
  sfVector3f	vector;

  i = 0;
  tbot = *bot;
  ttop = *top;
  while (i < dim.x * dim.y)
    {
      vector.x = X_SQ * (i % dim.x) - (double)(dim.x / 2 * X_SQ);
      vector.y = ttop->point.y * Y_SQ;
      vector.z = Z_SQ * (i / dim.x) - (double)(dim.x / 2 * Y_SQ);
      tbot->point = vector;
      tbot->point.y = 0;
      ttop->point = vector;
      ttop = ttop->next;
      tbot = tbot->next;
      i += 1;
    }
    link_vertex(bot, top, dim);
}

void		my_draw_vertex(t_vertex **vertex, t_pixelbuff *buff,
			       sfVector3f angle, sfColor color)
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
	  pos1 = my_3d_projection(temp->point, angle);
	  pos1.x = WIDTH / 2 + pos1.x;
	  pos1.y = HEIGHT / 2 - pos1.y;
	  pos2 = my_3d_projection(in_temp->point, angle);
	  pos2.x = WIDTH / 2 + pos2.x;
	  pos2.y = HEIGHT / 2 - pos2.y;
	  //	  printf("x1 : %d, y1 : %d ->> x2 : %d, y2 : %d\n",pos1.x, pos1.y,pos2.x, pos2.y);
	  my_draw_line(buff, pos1, pos2, color);
	  in_temp = in_temp->next;
	}
      temp = temp->next;
    }
}

