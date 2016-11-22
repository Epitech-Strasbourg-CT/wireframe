/*
** draw_pixel.c for draw_pixel.c in /home/cedric/delivery/MUL/libmysf/draw
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 20:32:11 2016 Cédric Thomas
** Last update Fri Nov 18 20:38:50 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mysf.h"

void	put_pixel(t_pixelbuff *buffer,
		  int x,
		  int y,
		  sfColor color)
{
  buffer->pixels[(buffer->x * y + x) * 4] = color.r;
  buffer->pixels[(buffer->x * y + x) * 4 + 1] = color.g;
  buffer->pixels[(buffer->x * y + x) * 4 + 2] = color.b;
  buffer->pixels[(buffer->x * y + x) * 4 + 3] = color.a;
}
