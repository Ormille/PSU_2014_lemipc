/*
** ia.c for ia in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Thu Mar  5 13:31:46 2015 moran-_d
** Last update Sun Mar  8 15:42:52 2015 moran-_d
*/

#include <unistd.h>
#include <stdio.h>
#include "lemipc.h"
#include "ia.h"

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
	{
	  printf("Oh, i'm dead :'( My position is already cleared on map, BTW\n");
	  ret = 1;
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

  if (check_mailbox(shared, player) == 1)
    {
      semop(shared->sem_id, &sops, 1);
      return (1);
    }
  if (player->flag == 0)
    ret = exec_commoner(shared, player);
  else
    ret = exec_flag(shared, player);

  usleep(TURN_TIME);
  semop(shared->sem_id, &sops, 1);
  return (ret);
}
