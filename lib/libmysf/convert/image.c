/*
** position.c for mysf in /home/cedric/delivery/MUL/libmysf/convert
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 21:27:17 2016 Cédric Thomas
** Last update Fri Nov 18 21:32:09 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mysf.h"

t_image       t_image_create(double x, double y)
{
  t_image     image;

  image.spri = sfSprite_create();
  image.tex = sfTexture_create(x, y);
  sfSprite_setTexture(image.spri, image.tex, sfTrue);
  return (image);
}
