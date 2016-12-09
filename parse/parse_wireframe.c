/*
** parse_wireframe.c for parse_wireframe.c in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 11:57:42 2016 Cédric Thomas
** Last update Fri Dec  9 14:14:50 2016 Cédric Thomas
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "wireframe.h"

static int	check_str(char *str)
{
  int		i;
  int		bool;

  bool = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	bool = 0;
      else if (is_in(str[i], "0123456789"))
	bool = 1;
      i += 1;
    }
  return (bool);
}

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
	  if (is_in(tab[dim.y][i], "0123456789-") &&
	      (i == 0 || !is_in(tab[dim.y][i - 1], "0123456789-")))
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
	  position = myvector3f( 0, split[i][j] - '0', 0);
	  if (j > 0 && split[i][j])
	    position.y *= (split[i][j - 1] == '-' ? -1 : 1);
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
  if (!check_str(readed))
    return (dim);
  if ((split = my_split(readed, '\n')) == NULL)
    return (dim);
  dim = getdim(split);
  if (dim.x <= 0)
    {
      dim.x = -1;
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
