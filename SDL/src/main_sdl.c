/*
** main.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:12:41 2015 Julie Terranova
** Last update Wed Mar  4 16:27:57 2015 Julie Terranova
*/

#include "lemisdl.h"

int	main()
{
  int	**map;
  // atej:
  map = malloc(sizeof(*map) * 100);
  int i = 0;
  while (i++ < 10)
    *map = malloc(sizeof(**map) * 100);


  //
  draw(map);
  // struct a free a la fin

  return (0);
}
