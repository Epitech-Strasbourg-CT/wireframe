/*
** vertex_free.c for wireframe.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 21:24:38 2016 Cédric Thomas
** Last update Wed Nov 23 21:27:11 2016 Cédric Thomas
*/
#include <math.h>
#include <stdlib.h>
#include "wireframe.h"

sfVector2i      my_3d_projection(sfVector3f pos3d,
				 sfVector3f camera)
{
  sfVector2i    pos2d;

  pos2d.x = WIDTH / 2 + pos3d.x - cos(camera.x * M_PI / 180) * pos3d.z;
  pos2d.y = HEIGHT  / 2 - pos3d.y + sin(camera.x * M_PI / 180) * pos3d.z;
  return (pos2d);
}

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
