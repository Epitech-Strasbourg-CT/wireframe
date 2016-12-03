/*
** point.c for mysf in /home/cedric/delivery/MUL/libmysf/convert
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 21:35:37 2016 Cédric Thomas
** Last update Mon Nov 21 08:39:53 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mysf.h"

sfVector2f	point_to_iso(sfVector3f pos3d, double angleH, double angleV)
{
  sfVector2f	pos2d;

  pos2d.x = pos3d.x - cos(angleH * M_PI / 180) * pos3d.z - cos(angleV * M_PI / 180) * pos3d.y; //#TOCHANGE
  pos2d.y = pos3d.y + sin(angleH * M_PI / 180) * pos3d.z + sin(angleV * M_PI / 180) * pos3d.y; //#TOCHANGE
  return (pos2d);
}

sfVector2i	center(sfVector2i pos, t_pixelbuff buff)
{
  pos.x += buff.x / 2;
  pos.y += buff.x / 2;
  return (pos);
}
