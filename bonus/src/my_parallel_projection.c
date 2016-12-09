/*
** my_parralel_projection.c for my_parralel_projection.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov 22 16:43:20 2016 Cédric Thomas
** Last update Fri Dec  9 18:10:34 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>
#include "wireframe.h"

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i    pos2d;

  pos2d.x = pos3d.x + 0.7 * cos(angle * M_PI / 180) * pos3d.z;
  pos2d.y = pos3d.y + 0.7 * sin(angle * M_PI / 180) * pos3d.z;
  return (pos2d);
}
