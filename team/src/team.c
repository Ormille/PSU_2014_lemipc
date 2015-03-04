/*
** team.c for team in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Wed Mar  4 15:54:16 2015 moran-_d
** Last update Wed Mar  4 18:07:31 2015 moran-_d
*/

#include <sys/sem.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

int check_color(shared_t *shared)
{
  struct sembuf sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  /*
     read map and return lowest number not found
     (if nbr >= MAX_TEAM, no team available)
  */
  sops.sem_op = 1;
  semop(shared->sem_id, &sops, 1);
  return (1);
}

int init_team(shared_t *shared, int nb_players)
{
  int i;
  int color;

  srand(time(NULL));
  if ((color = check_color(shared)) < 0)
    return (-1);
  for (i = 1; i < nb_players; i++)
    {
      if ((create_player(shared, color)) != 0)
	return (0);
    }
  init_player(shared, color, 1);
  return (0);
}
