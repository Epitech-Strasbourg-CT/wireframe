/*
** draw_line.c for mysf in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:21:53 2016 Cédric Thomas
** Last update Wed Nov 23 19:53:54 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wireframe.h"

void		my_draw_line(t_pixelbuff *buff,
			 sfVector2i from,
			 sfVector2i to,
			 sfColor color)
{
  sfVector2f    dir;
  sfVector2f    pixel;
  double        i;
  double        norme;

  i = 0;
  dir.x = to.x - from.x;
  dir.y = to.y - from.y;
  norme = sqrt(pow(dir.y, 2) + pow(dir.x, 2));
  dir.x /= norme;
  dir.y /= norme;
  while (i < norme)
    {
      pixel.x = from.x + i * dir.x;
      pixel.y = from.y + i * dir.y;
      if (pixel.x < buff->x && pixel.y < buff->y
	  && pixel.x >= 0 && pixel.y >= 0)
	put_pixel(buff, pixel.x, pixel.y, color);
      i += 1;
    }
}
