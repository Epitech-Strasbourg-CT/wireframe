/*
** misc_vertex.c for misc_vertex in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 13:48:06 2016 Cédric Thomas
** Last update Sat Dec  3 14:10:15 2016 Cédric Thomas
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

int		rev_vertex(t_vertex **ll)
{
  t_vertex	*n_list;
  t_vertex	*last;
  t_vertex	*temp;

  if (ll == NULL)
    return (-1);
  last = NULL;
  temp = *ll;
  while (temp != NULL)
    {
      n_list = temp->next;
      temp->next = last;
      last = temp;
      temp = n_list;
    }
  *ll = last;
  return (0);
}

int             put_vertex(t_vertex **ll, sfVector3f vertex, int connect)
{
  t_vertex      *memory;

  if ((memory = malloc(sizeof(*memory))) == NULL)
    return (0);
  memory->point = vertex;
  memory->next = *ll;
  memory->linked = NULL;
  if (memory->next != NULL && connect)
    put_vertex(&(memory->linked), (*ll)->point, 0);
  *ll = memory;
  return (1);
}

int		connect_vertex(t_vertex **ll, int index1, int index2, int connect)
{
  int		i;
  t_vertex      *temp;
  t_vertex      *vertex1;

  temp = *ll;
  i = 0;
  while (temp != NULL)
    {
      if (connect && temp->next != NULL)
	{
	  if (i >= index1 && i < index2 - 1)
	    put_vertex(&(temp->linked), temp->next->point, 0);
	}
      else
	{
	  if (i == index1)
	    vertex1 = temp;
	  if (i == index2)
	    put_vertex(&(vertex1->linked), temp->point, 0);
	}
      i += 1;
      temp = temp->next;
    }
}

int		fill_vertex(t_vertex **ll, int size)
{
  int	i;

  i = 0;
  *ll = NULL;
  while (i < size)
    {
      put_vertex(ll, myvector3f(0, 0, 0), 0);
      i += 1;
    }
}

