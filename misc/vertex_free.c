/*
** vertex_free.c for wireframe.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 21:24:38 2016 Cédric Thomas
** Last update Mon Nov 21 21:42:03 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "wireframe.h"

void		free_vertex(t_vertex **vertex, int recur)
{
  t_vertex	*temp;

  while (*vertex != NULL)
    {
      temp = *vertex;
      if (recur)
	free_vertex(&(*vertex)->linked, 0);
      *vertex = (*vertex)->next;
      free(temp);
    }

}
