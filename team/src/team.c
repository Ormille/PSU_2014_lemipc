/*
** team.c for team in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Wed Mar  4 15:54:16 2015 moran-_d
** Last update Sun Mar  8 18:15:19 2015 moran-_d
*/

#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

int check_color(shared_t *shared)
{
  struct sembuf sops;
  int team[MAX_TEAM + 1];
  int x;
  int y;

  memset(team, 0, (MAX_TEAM + 1) * sizeof(int));
  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  y = -1;
  while (++y < MAP_Y)
    {
      x = -1;
      while (++x < MAP_X)
	team[shared->map[x][y]]++;
    }
  sops.sem_op = 1;
  semop(shared->sem_id, &sops, 1);
  y = -1;
  x = 0;
  while (++x < MAX_TEAM + 1 && y == -1)
    if (team[x] == 0)
      y = x;
  return (y);
}

int init_team(shared_t *shared, int nb_players)
{
  int i;
  int color;
  int ret;

  srand(time(NULL));
  if ((color = check_color(shared)) < 0)
    {
      printf("Max team reached. Can't add another one.\n");
      return (-1);
    }
  for (i = 1; i < nb_players; i++)
    {
      if ((ret = (create_player(shared, color))) != 0)
	return (ret);
    }
  sleep(1);
  return (init_player(shared, color, 1));
}
