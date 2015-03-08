/*
** ia.c for ia in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Thu Mar  5 13:31:46 2015 moran-_d
** Last update Sun Mar  8 20:57:02 2015 moran-_d
*/

#include <unistd.h>
#include <stdio.h>
#include "lemipc.h"
#include "ia.h"

int me_dead(shared_t *shared, player_t *player)
{
  int pos[2];
  msg_t msg;

  if (player->flag == 1)
    {
      find_entity(shared, &pos, (int[2]){player->x, player->y},
		  player->color * -1);
      if (pos[0] > -1)
	{
	  msg.type = pos[0];
	  msg.type = msg.type << sizeof(int);
	  msg.type += pos[1];
	  msg.val[0] = 3;
	  msgsnd(shared->msg_id, &msg, MSG_SIZE, 0);
	}
      else
	{
	  find_entity(shared, &pos, (int[2]){player->x, player->y},
		      player->color);
	  if (pos[0] == -1)
	    return (2);
	}
    }
  return (1);
}

int check_mailbox(shared_t *shared, player_t *player)
{
  msg_t msg;
  long id;
  int ret;

  ret = 0;
  id = player->x;
  id = id << sizeof(int);
  id += player->y;
  while (msgrcv(shared->msg_id, &msg, MSG_SIZE, id, IPC_NOWAIT) != -1)
    {
      if (msg.val[0] == 0) /* move */
	{
	  player->objective[0] = msg.val[1];
	  player->objective[1] = msg.val[2];
	  player->objective[2] = msg.val[3];
	}
      else if (msg.val[0] == 2 && ret != 1) /* dead */
	ret = me_dead(shared, player);
      else if (msg.val[0] == 3) /* promotion */
	{
	  player->flag = 1;
	  player->objective[2] = GROUPING_TURN;
	}
    }
  return (ret);
}

int exec_turn(shared_t *shared, player_t *player)
{
  struct sembuf sops;
  int ret;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  sops.sem_op = 1;
  ret = -1;

  if ((ret = check_mailbox(shared, player)) != 0)
    {
      semop(shared->sem_id, &sops, 1);
      return (ret);
    }
  if (player->flag == 0)
    ret = exec_commoner(shared, player);
  else
    ret = exec_flag(shared, player);

  usleep(TURN_TIME);
  semop(shared->sem_id, &sops, 1);
  return (ret);
}
