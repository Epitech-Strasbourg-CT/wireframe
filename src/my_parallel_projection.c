/*
** my_parralel_projection.c for my_parralel_projection.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov 22 16:43:20 2016 Cédric Thomas
** Last update Sat Dec 10 11:06:39 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wireframe.h"

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i    pos2d;

  pos2d.x = pos3d.x + cos(angle * M_PI / 180) * pos3d.y;
  pos2d.y = -pos3d.z + sin(angle * M_PI / 180) * pos3d.y;
  return (pos2d);
}
