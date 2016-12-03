/*
** draw_square.c for csfml.c in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:48:57 2016 Cédric Thomas
** Last update Fri Nov 18 20:50:55 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mysf.h"

int     put_square(sfVector2i *pos, sfVector2i *size,
		      t_pixelbuff *buff, sfColor color)
{
  int   i;
  int   j;

  i = 0;
  if (pos->x + size->x > buff->x)
    return (-1);
  else if (pos->y + size->y > buff->y)
    return (-1);
  while (i < size->x)
    {
      j = 0;
      while (j < size->y)
	{
	  put_pixel(buff,  pos->x + i, pos->y + j, color);
	  j += 1;
	}
      i += 1;
    }
}
