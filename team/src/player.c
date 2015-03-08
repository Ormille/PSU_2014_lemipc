/*
** player.c for player in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Wed Mar  4 15:58:48 2015 moran-_d
** Last update Sun Mar  8 21:01:41 2015 moran-_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"
#include "ia.h"

int place_player(shared_t *shared, player_t *player)
{
  struct sembuf sops;
  int i;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  sops.sem_op = 1;
  i = -1;
  while (++i < MAX_PLAYER_PLACE_TRY)
    {
      player->x = rand() % MAP_X;
      player->y = rand() % MAP_Y;
      if (shared->map[player->x][player->y] == 0
	  && check_entity_in_radius(shared, (int[2]){player->x, player->y},
				    1, player->color) == 0)
	{
	  shared->map[player->x][player->y] = player->color;
	  semop(shared->sem_id, &sops, 1);
	  return (0);
	}
    }
  me_dead(shared, player);
  semop(shared->sem_id, &sops, 1);
  return (-1);
}

int exec_ia(shared_t *shared, player_t *player)
{
  int quit;
  int turn;

  quit = 0;
  shared = shared;
  player = player;
  while (quit == 0)
    {
      quit = exec_turn(shared, player, &turn);
    }
  printf("\t\t\tQUITTING %d\n", quit);
  return (quit);
}

int init_player(shared_t *shared, int color, int flag)
{
  player_t player;

  player.color = color;
  player.regroup = 1;
  if ((player.flag = flag) == 1)
    player.objective[2] = GROUPING_TURN;
  else
    player.objective[2] = 0;
  if (place_player(shared, &player) != 0)
    return (-1);
  printf("player %d --- x = %d --- y = %d\n", color, player.x, player.y);
  player.objective[0] = player.x;
  player.objective[1] = player.y;
  msg_graph(shared, &player, 1, (int[2]){0, 0});
  return (exec_ia(shared, &player));
}

int create_player(shared_t *shared, int color)
{
  int pid;

  if ((pid = fork()) == -1)
    {
      printf("Fork fail.\n");
      return (-1);
    }
  else if (pid > 0)
    return (0);
  return (init_player(shared, color, 0));
}
