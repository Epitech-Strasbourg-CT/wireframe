/*
** disp.c for wireframe in /home/cedric/delivery/wireframe/propre
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 11:13:09 2016 Cédric Thomas
** Last update Sat Dec  3 11:19:58 2016 Cédric Thomas
*/
#include "wireframe.h"
#include "my.h"

int		main(int ac, char **av)
{
  t_vertex	*top;
  t_vertex	*bot;
  sfVector2i	dim;

  if (ac != 2)
    return (84);
  dim = wireparse(&bot, &top, av[1]);
  if (dim.x == -1)
    return (84);
  //set_vertex_position(&bot, &top, dim);
  //draw_this(&bot, &top, dim);
  free_vertex(&top, 1);
  free_vertex(&bot, 1);
}
