/*
** ia_commoner.c for com in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Mar  5 13:52:54 2015 moran-_d
** Last update Sun Mar  8 22:16:33 2015 moran-_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lemipc.h"
#include "ia.h"

int opportunist_kill(shared_t *shared, player_t *player)
{
  int **nearby;
  int size;

  size = 0;
  nearby = (int**)check_teams_in_radius(shared, (int[2]){player->x, player->y},
					2, &size);
  while (nearby != NULL && size >= 0)
    {
      if (nearby[size][2] != player->color &&
          distance(nearby[size][0], nearby[size][1],
                   player->x, player->y) == 2
          && check_entity_in_radius(shared, (int*)nearby[size],
                                    1, player->color * -1))
	if (move_safely(shared, player, (int*)nearby[size]) == 0)
	  {
	    free(nearby);
	    return (0);
	  }
      --size;
    }
  if (nearby != NULL)
    free(nearby);
  return (-1);
}

int exec_commoner(shared_t *shared, player_t *player)
{
  if (opportunist_kill(shared, player) == 0)
    return (0);
  if (player->x != player->objective[0] || player->y != player->objective[1])
    return (move_toward_objective(shared, player));
  return (0);
}
