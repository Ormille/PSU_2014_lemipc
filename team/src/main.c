/*
** main.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:12:41 2015 Julie Terranova
** Last update Wed Mar  4 15:54:41 2015 moran-_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

int	main(int argc, char **argv)
{
  shared_t *shared;
  int nb_players;

  if (argc < 2)
    nb_players = 15;
  else if (argc > 2)
    {
      printf("Usage : %s [nb_players]\n", argv[0]);
      return (-1);
    }
  else
    if ((nb_players = atoi(argv[1])) < 0 || nb_players > 15)
      nb_players = 15;
  if ((shared = get_shared()) == NULL)
    return (-1);
  init_team(shared, nb_players);
  return (0);
}
