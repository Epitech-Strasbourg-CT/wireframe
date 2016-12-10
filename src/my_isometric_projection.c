/*
** my_parralel_projection.c for my_parralel_projection.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov 22 16:43:20 2016 Cédric Thomas
** Last update Sat Dec 10 17:44:51 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wireframe.h"

double          deg_rad(double angle)
{
  return (angle * M_PI / 180);
}

sfVector2i	my_isometric_projection(sfVector3f pos3d)
{
  sfVector2i	pos2d;

  pos2d.x = cos(deg_rad(-30)) * pos3d.x + cos(deg_rad(-150)) * pos3d.y;
  pos2d.y = -pos3d.z - sin(deg_rad(-30))
    * pos3d.x - cos(deg_rad(-150)) * pos3d.y;
  return (pos2d);
}
