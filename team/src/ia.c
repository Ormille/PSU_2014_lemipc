/*
** ia.c for ia in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Thu Mar  5 13:31:46 2015 moran-_d
** Last update Sun Mar  8 22:16:16 2015 moran-_d
*/

#include <unistd.h>
#include <stdio.h>
#include "lemipc.h"
#include "ia.h"

int me_dead(shared_t *shared, player_t *player)
{
  int pos[2];
  msg_t msg;
  int winner;

  if (player->flag == 1)
    {
      printf("A FLAG IS DEAD!\n");
      find_entity(shared, &pos, (int[2]){player->x, player->y},
		  player->color * -1);
      if (pos[0] > -1)
	{
	  msg.type = pos[0];
	  msg.type = msg.type << sizeof(int);
	  msg.type += pos[1];
	  msg.val[0] = 3;
	  msgsnd(shared->msg_id, &msg, MSG_SIZE, IPC_NOWAIT);
	}
      if ((winner = is_team_alone(shared)) > 0)
	return (winner + 5);
    }
  return (1);
}

int check_mailbox(shared_t *shared, player_t *player, int *turn)
{
  msg_t msg;
  long id;
  int ret;

  ret = 0;
  id = player->x;
  id = id << sizeof(int);
  id += player->y;
  while (msgrcv(shared->msg_id, &msg, MSG_SIZE, id, IPC_NOWAIT) != -1)
    if (msg.val[0] == 0)
      {
	(*turn) = 0;
	player->objective[0] = msg.val[1];
	player->objective[1] = msg.val[2];
	player->objective[2] = msg.val[3];
      }
    else if (msg.val[0] == 2)
      ret = me_dead(shared, player);
    else if (msg.val[0] == 3)
      {
	player->flag = 1;
	player->objective[2] = GROUPING_TURN;
      }
  return (ret);
}

int exec_turn(shared_t *shared, player_t *player, int *turn)
{
  struct sembuf sops;
  int ret;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = (ret = -1);
  semop(shared->sem_id, &sops, 1);
  sops.sem_op = 1;
  if ((ret = check_mailbox(shared, player, turn)) != 0)
    {
      semop(shared->sem_id, &sops, 1);
      return (ret);
    }
  if ((*turn) > 75)
    player->flag = 1;
  if (shared->map[player->x][player->y] != player->color)
    return (1);
  if (player->flag == 0)
    ret = exec_commoner(shared, player);
  else
    ret = exec_flag(shared, player);
  ++(*turn);
  usleep(TURN_TIME);
  semop(shared->sem_id, &sops, 1);
  return (ret);
}
