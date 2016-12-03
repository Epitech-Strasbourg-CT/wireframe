/*
** draw_vertex.c for draw_vertex.c in /home/cedric/delivery/MUL/libmysf
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Nov 21 08:37:03 2016 Cédric Thomas
** Last update Mon Nov 21 08:41:21 2016 Cédric Thomas
*/
#include "mysf.h"

void		draw_vertex(t_vertex **vertex, t_pixelbuff *buff,
			    double angleH, double angleV)
{
  t_vertex      *temp;
  t_vertex      *in_temp;
  sfVector2f	pos1;
  sfVector2f	pos2;

  temp = *vertex;
  while (temp != NULL)
    {
      in_temp = temp->linked;
      while (in_temp != NULL)
	{
	  pos1 = point_to_iso(temp->point, angleH, angleV); //#TOCHANGE
	  pos2 = point_to_iso(in_temp->point, angleH, angleV); //#TOCHANGE
	  put_line(buff, pos1, pos2, sfBlue);
	  in_temp = in_temp->next;
	}
      temp = temp->next;
    }
}
