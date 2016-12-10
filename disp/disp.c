/*
** disp.c for wireframe in /home/cedric/delivery/wireframe/propre
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Dec  3 11:13:09 2016 Cédric Thomas
** Last update Sat Dec 10 09:53:54 2016 Cédric Thomas
*/
#include "wireframe.h"
#include "my.h"

static int	checkevent(sfRenderWindow *window, sfEvent *event, t_cam *cam)
{
  if (sfRenderWindow_pollEvent(window, event)
      && event->type == sfEvtKeyPressed)
    {
      if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
	sfRenderWindow_close(window);
      if (event->key.code == sfKeyUp || event->key.code == sfKeyDown)
	cam->position.y += 10 * (event->key.code == sfKeyDown ? -1 : 1);
      if (event->key.code == sfKeyLeft || event->key.code == sfKeyRight)
	cam->position.x += 10 * (event->key.code == sfKeyLeft ? -1 : 1);
      if (event->key.code == sfKeyP || event->key.code == sfKeyM)
	cam->zoom += 0.1 * (event->key.code == sfKeyP ? 1 : -1);
      if (event->key.code == sfKeyQ || event->key.code == sfKeyD)
	cam->angle.y += 1 * (event->key.code == sfKeyQ ? 1 : -1);
      if (event->key.code == sfKeyZ || event->key.code == sfKeyS)
	cam->angle.x += 1 * (event->key.code == sfKeyS ? 1 : -1);
      if (event->key.code == sfKeyA || event->key.code == sfKeyE)
	cam->angle.z += 1 * (event->key.code == sfKeyE ? 1 : -1);
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

static void	init_cam(t_cam *cam)
{
  cam->angle = myvector3f(0, 0, 0);
  cam->zoom = 1;
  cam->position = myvector2i(0, 0);
}

static void	redraw(t_vertex **bot, t_vertex **top,
		       t_cam cam, t_pixelbuff **buff)
{
  clean(buff);
  my_draw_vertex(bot, *buff, cam, sfRed);
  my_draw_vertex(top, *buff, cam, sfWhite);
}

void	draw_this(t_vertex **bot, t_vertex **top, sfVector2i dim)
{
  sfRenderWindow        *window;
  sfEvent               event;
  t_image		image;
  t_pixelbuff           *buff;
  t_cam			cam;

  window = window_create("Wireframe", WIDTH, HEIGHT);
  image = t_image_create(WIDTH, HEIGHT);
  buff = pixelbuff_create(WIDTH, HEIGHT);
  init_cam(&cam);
  redraw(bot, top, cam, &buff);
  sfTexture_updateFromPixels(image.tex, buff->pixels, WIDTH, HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      if (checkevent(window, &event, &cam))
	{
	  redraw(bot, top, cam, &buff);
	  sfTexture_updateFromPixels(image.tex, buff->pixels, WIDTH, HEIGHT, 0, 0);
	}
      sfRenderWindow_drawSprite(window, image.spri, NULL);
      sfRenderWindow_display(window);
      sfRenderWindow_clear(window, sfBlack);
    }
  sfRenderWindow_destroy(window);
  free_pixelbuff(buff);
}
