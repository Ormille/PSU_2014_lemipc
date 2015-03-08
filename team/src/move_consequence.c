/*
** move_consequence.c for move in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Sun Mar  8 11:29:53 2015 moran-_d
** Last update Sun Mar  8 12:27:15 2015 moran-_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

void kill_player(shared_t *shared, int x, int y)
{
  msg_t msg;

  printf("ONE FRAG\n");
  if (shared->map[x][y] == 0)
    {
      printf("You're trying to kill some air. Genius.\n");
      return;
    }
  shared->map[x][y] = 0;
  msg.type = x;
  msg.type = msg.type << sizeof(int);
  msg.type += y;
  msg.val[0] = 1;
  //  msgsnd(shared->msg_id, &msg, MSG_SIZE, IPC_NOWAIT);
  msg = msg;
}

void move_consequence(shared_t *shared, player_t *player)
{
  int **near;
  int i;
  int s;

  i = -1;
  near = check_teams_in_radius(shared, (int[2]){player->x, player->y}, 1, &s);
  while (near != NULL && ++i <= s)
    {
      if ((shared->map[near[i][0]][near[i][1]]) != player->color
	  && check_entity_in_radius(shared, (int[2]){near[i][0], near[i][1]},
				    1, player->color * -1) >= 2)
	near[i][2] = 0;
      else if (near[i][0] == player->x && near[i][1] == player->y
	       && search_max_enemy_same_team(shared,
					     (int[2]){near[i][0], near[i][1]},
					     1, player->color) >= 2)
	near[i][2] = 0;
    }
  while (--i >= 0)
    {
      if (near[i][2] == 0)
	kill_player(shared, near[i][0], near[i][1]);
    }
  if (near != NULL)
    free(near);
}
