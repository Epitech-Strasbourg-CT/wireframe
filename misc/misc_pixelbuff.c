/*
** misc_pixelbuff.c for pixelbuff in /home/cedric/delivery/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 15:13:33 2016 Cédric Thomas
** Last update Sat Dec  3 15:29:20 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "wireframe.h"

t_pixelbuff		*pixelbuff_create(int width, int height)
{
  int			i;
  t_pixelbuff		*buffer;

  buffer = malloc(sizeof(t_pixelbuff));
  if (buffer == NULL)
    return (NULL);
  buffer->pixels = malloc(width * height * 4 * sizeof(buffer->pixels));
  if (buffer->pixels == NULL)
    return (NULL);
  i = 0;
  while (i < (width * height * 4))
    {
      buffer->pixels[i] = 0;
      i += 1;
    }
  buffer->y = height;
  buffer->x = width;
  return (buffer);
}

void    free_pixelbuff(t_pixelbuff *buffer)
{
  free(buffer->pixels);
  free(buffer);
}
