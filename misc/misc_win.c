/*
** misc_win.c for wireframe in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 15:20:28 2016 Cédric Thomas
** Last update Sat Dec  3 15:28:32 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include "wireframe.h"
#include "my.h"

sfRenderWindow          *window_create(char *n, int w, int h)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = w;
  mode.height = h;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, n, sfResize | sfClose, NULL);
  return (window);
}

t_image       t_image_create(double x, double y)
{
  t_image     image;

  image.spri = sfSprite_create();
  image.tex = sfTexture_create(x, y);
  sfSprite_setTexture(image.spri, image.tex, sfTrue);
  return (image);
}
