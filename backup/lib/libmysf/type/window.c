/*
** window.c for mysf in /home/cedric/delivery/MUL/libmysf/type
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:59:55 2016 Cédric Thomas
** Last update Fri Nov 18 21:00:29 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysf.h"

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
