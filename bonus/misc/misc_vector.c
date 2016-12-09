/*
** misc_vector.c for wireframe in /home/cedric/delivery/MUL/libmysf/type
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 21:17:53 2016 Cédric Thomas
** Last update Sat Dec  3 13:45:51 2016 Cédric Thomas
*/
#include <SFML/Graphics.h>
#include "wireframe.h"

sfVector2f	myvector2f(double x, double y)
{
  sfVector2f	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfVector3f	myvector3f(double x, double y, double z)
{
  sfVector3f    vec;

  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}

sfVector2i	myvector2i(int x, int y)
{
  sfVector2i	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}
