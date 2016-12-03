/*
** vectorf.c for mmysf in /home/cedric/delivery/MUL/libmysf/type
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Nov 18 21:17:53 2016 Cédric Thomas
** Last update Fri Nov 18 21:25:08 2016 Cédric Thomas
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mysf.h"

sfVector2f      myVector2f(double x, double y)
{
  sfVector2f    vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfVector3f      myVector3f(double x, double y, double z)
{
  sfVector3f    vec;

  vec.x = x;
  vec.y = y;
  vec.z = z;
  return (vec);
}
