/*
** main.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:12:41 2015 Julie Terranova
** Last update Wed Mar  4 18:59:49 2015 Julie Terranova
*/

#include "lemisdl.h"
#include "lemipc.h"

int	main()
{
  shared_t *shared;

  if ((shared = get_shared()) == NULL)
    {
      printf("./lemipc is required before you start the graphic part\n");
      return (-1);
    }
  draw(shared->map);
  return (0);
}
