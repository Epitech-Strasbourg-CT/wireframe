/*
** parse.c for wireframe_parse in /home/cedric/delivery/MUL/wireframe
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Nov 19 10:32:09 2016 Cédric Thomas
** Last update Tue Nov 22 16:40:06 2016 Cédric Thomas
*/
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "wireframe.h"
#include "my.h"

char	*my_read(char *path)
{
  char  *buff;
  int   offset;
  int   len;
  int	fd;

  if ((buff = malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
    return (NULL);
  offset = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_puterror("invalid file.");
      return (NULL);
    }
  while ((len = read(fd, buff + offset, BUFF_SIZE - offset)) > 0)
    {
      offset += len;
    }
  buff[offset] = '\0';
  if (len < 0)
    return (NULL);
  close(fd);
  return (buff);
}
