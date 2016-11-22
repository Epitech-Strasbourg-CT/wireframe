/*
** draw_line.c for mysf in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:21:53 2016 Cédric Thomas
** Last update Fri Nov 18 20:39:26 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mysf.h"

void		put_line(t_pixelbuff *buff,
			 sfVector2f from,
			 sfVector2f to,
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
      put_pixel(buff, pixel.x, pixel.y, color);
      i += 1;
    }
}
