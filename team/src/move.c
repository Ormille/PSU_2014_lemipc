/*
** move.c for move in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Mar  5 14:07:35 2015 moran-_d
** Last update Fri Mar  6 14:47:15 2015 moran-_d
*/

#include "lemipc.h"

int move_to(shared_t *shared, player_t *player, int pos[2])
{
  struct sembuf sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  sops.sem_op = 1;
  if (shared->map[pos[0]][pos[1]] != 0)
    {
      semop(shared->sem_id, &sops, 1);
      return (-1);
    }
  shared->map[player->x][player->y] = 0;
  player->x = pos[0];
  player->y = pos[1];
  shared->map[pos[0]][pos[1]] = player->color;
  semop(shared->sem_id, &sops, 1);
  return (0);
}

int move_toward_objective(shared_t *shared, player_t *player)
{
  int try[2];
  int dangerous;

  try[0] = !!(player->objective[0] - player->x) + player->x;
  try[1] = !!(player->objective[1] - player->y) + player->y;
  // while possibilities
  if (player->objective[0] < player->x) // IF DIRECTION NOT AVAILABLE TRY ANOTHER
    try[0] *= -1;
  else if (player->objective[1] < player->y)
    try[1] *= -1;
  dangerous = check_enemy_in_radius(shared, (int[2]){try[0], try[1]},
				    1, player->color);
  if ((dangerous < 2 || player->objective[2] == 1))
    move_to(shared, player, (int[2]){try[0], try[1]});
  // end while if move_to is ok
  return (0);
}
