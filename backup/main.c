/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Thu Nov 24 09:49:19 2016 Cédric Thomas
*/
#include <stdio.h> //#ADELETE
#include "wireframe.h"
#include "my.h"

void	show_vertex(t_vertex **ll, int ception)
{
  t_vertex	*tmp;

  tmp = *ll;
  while (tmp != NULL)
    {
      if (ception)
	{
	  printf("main : %f, %f, %f\n", tmp->point.x, tmp->point.y, tmp->point.z);
	  show_vertex(&(*ll)->linked, 0);
	}
      else
	printf("            sub : %f, %f, %f\n", tmp->point.x, tmp->point.y, tmp->point.z);
      tmp = tmp->next;
    }
}

static int	checkevent(sfRenderWindow *window, sfEvent *event, sfVector3f *camera)
{
  if(sfRenderWindow_pollEvent(window, event))
    {
      if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
	sfRenderWindow_close(window);
      if (event->key.code == sfKeyUp)
	camera->x += 0.5;
      else if (event->key.code == sfKeyDown)
	camera->x -= 0.5;
      if (event->key.code == sfKeyLeft)
	camera->y += 0.5;
      else if (event->key.code == sfKeyRight)
	camera->y -= 0.5;
      if (event->key.code == sfKeyZ)
	camera->z += 0.5;
      else if (event->key.code == sfKeyS)
	camera->z -= 0.5;
      return (1);
    }
  return (0);
}

static void	clean(t_pixelbuff **buff)
{
  int	i;

  i = 0;
  while (i < (*buff)->x * (*buff)->y * 4)
    {
      (*buff)->pixels[i] = 0;
      i += 1;
    }
}

void	draw_this(t_vertex **bot, t_vertex **top, sfVector2i dim)
{
  sfRenderWindow        *window;
  sfEvent               event;
  t_image               image;
  t_pixelbuff           *buff;
  sfVector3f		angle;

  window = window_create("Wireframe", WIDTH, HEIGHT);
  image = t_image_create(WIDTH, HEIGHT);
  buff = pixelbuff_create(WIDTH, HEIGHT);
  angle.x = 40;
  angle.y = 0;
  angle.z = 0;
  my_draw_vertex(bot, buff, angle, sfBlue);
  my_draw_vertex(top, buff, angle, sfWhite);
  sfTexture_updateFromPixels(image.tex, buff->pixels, WIDTH, HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      if (checkevent(window, &event, &angle))
	{
	  clean(&buff);
	  my_draw_vertex(bot, buff, angle, sfBlue);
	  my_draw_vertex(top, buff, angle, sfWhite);
	  sfTexture_updateFromPixels(image.tex, buff->pixels, WIDTH, HEIGHT, 0, 0);
	}
      sfRenderWindow_drawSprite(window, image.spri, NULL);
      sfRenderWindow_display(window);
      sfRenderWindow_clear(window, sfBlack);
    }
  sfRenderWindow_destroy(window);
  free_pixelbuff(buff);
}

int		main(int ac, char **av)
{
  t_vertex	*top;
  t_vertex	*bot;
  sfVector2i	dim;

  if (ac != 2)
    return (84);
  dim = wireparse(&bot, &top, av[1]);
  if (dim.x == -1)
    return (84);
  set_vertex_position(&bot, &top, dim);
  draw_this(&bot, &top, dim);
  free_vertex(&top, 1);
  free_vertex(&bot, 1);
}
