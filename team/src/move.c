/*
** move.c for move in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Mar  5 14:07:35 2015 moran-_d
** Last update Sat Mar  7 20:55:37 2015 moran-_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lemipc.h"
#include "ia.h"

int __move_to(shared_t *shared, player_t *player, int pos[2])
{
  int prev[2];

  printf("Terminus\n");
  if (shared->map[pos[0]][pos[1]] != 0 || pos[0] > MAP_X || pos[1] > MAP_Y
      || pos[0] < 0 || pos[1] < 0)
    return (-1);
  shared->map[(prev[0] = player->x)][(prev[1] = player->y)] = 0;
  player->x = pos[0];
  player->y = pos[1];
  shared->map[pos[0]][pos[1]] = player->color;
  msg_graph(shared, player, 0, prev);
  return (0);
}

int move_to(shared_t *shared, player_t *player, int pos[2])
{
  struct sembuf sops;
  int ret;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  sops.sem_op = 1;
  ret = __move_to(shared, player, pos);
  semop(shared->sem_id, &sops, 1);
  return (ret);
}

int move_safely(shared_t *shared, player_t *player, int pos[2])
{
  printf("Here 4 -- pos0 = %d -- pos1 = %d\n", pos[0], pos[1]);
  if (shared->map[pos[0]][pos[1]] == 0 &&
      (player->objective[2] == 1 ||
       check_entity_in_radius(shared, pos, 1, player->color) < 2))
    if (__move_to(shared, player, pos) == 0)
      return (0);
  return (-1);
}

int advance_safely(shared_t *shared, player_t *player, int try[2])
{
  int pos[2];
  int tryagain;

  tryagain = 0;
  printf(" POS INITIALE : === %d === === %d ===\n", player->x, player->y);
  while (++tryagain < 6)
    {
      pos[0] = player->x;
      pos[1] = player->y;
      get_pattern(try, &pos, tryagain);
      printf(" === %d === === %d ===\n", pos[0], pos[1]);
      if (move_safely(shared, player, pos) == 0)
	return (0);
    }
  return (-1);
}

int move_toward_objective(shared_t *shared, player_t *player)
{
  int try[2];

  try[0] = !!(player->objective[0] - player->x);
  try[1] = !!(player->objective[1] - player->y);
  if (player->objective[0] < player->x)
    try[0] *= -1;
  else if (player->objective[1] < player->y)
    try[1] *= -1;
  return (advance_safely(shared, player, try));
}
