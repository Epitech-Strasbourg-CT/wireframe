/*
** link_wireframe.c for link_wireframe.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 19 11:38:50 2016 Cédric Thomas
** Last update Wed Nov 23 16:14:46 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "wireframe.h"
#include "my.h"

static sfVector2i	getdim(char **tab)
{
  sfVector2i		dim;
  int			i;
  int			count;

  dim.x = 0;
  dim.y = 0;
  while (tab[dim.y])
    {
      i = 0;
      count = 0;
      while (tab[dim.y][i])
	{
	  if (is_nb(tab[dim.y][i]) &&
	      (i == 0 || !is_nb(tab[dim.y][i - 1])))
	    count += 1;
	  i += 1;
	}
      if (dim.x == 0)
	dim.x = count;
      else if (dim.x != count)
      	dim.x = -1;
      dim.y += 1;
    }
  return (dim);
}

static t_vertex		*fillheight(char **split)
{
  int			i;
  int			j;
  sfVector3f		position;
  t_vertex		*wire;

  i = -1;
  wire = NULL;
  while (split[++i])
    {
      j = -1;
      while (split[i][++j])
	{
	  position = myVector3f( 0, split[i][j] - '0', 0);
	  if (j > 0)
	    position.y *= (split[i][j - 1] == '-' ? -1 : 1 );
	  if (is_in(split[i][j], "0123456789"))
	    {
	      if (j == 0 || !is_in(split[i][j - 1], "0123456789"))
		put_vertex(&wire, position, 0);
	      else
		wire->point.y = wire->point.y * 10 + split[i][j] - '0';
	    }
	}
    }
  return (wire);
}

sfVector2i	wireparse(t_vertex **bot, t_vertex **top, char *path)
{
  char			**split;
  char			*readed;
  sfVector2i		dim;

  dim.x = -1;
  dim.y = -1;
  if ((readed = my_read(path)) == NULL)
    return (dim);
  if ((split = my_split(readed, '\n')) == NULL)
    return (dim);
  dim = getdim(split);
  if (dim.x == -1)
    {
      my_puterror("incorrect input\n");
      return (dim);
    }
  *top = fillheight(split);
  fill_vertex(bot, dim.x * dim.y);
  rev_vertex(top);
  free(readed);
  free_tab(split);
  return (dim);
}
