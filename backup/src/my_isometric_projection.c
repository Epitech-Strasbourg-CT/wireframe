/*
** my_parralel_projection.c for my_parralel_projection.c in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Nov 22 16:43:20 2016 Cédric Thomas
** Last update Tue Nov 22 17:22:12 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include <math.h>

sfVector2i	my_isometric_projection(sfVector3f pos3d)
{
  sfVector2i	pos2d;

  pos2d.x = pos3d.x - sin(30 * M_PI / 180) * pos3d.z;
  pos2d.y = pos3d.y - cos(30 * M_PI / 180) * pos3d.z;
  return (pos2d);
}
