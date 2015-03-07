/*
** ia.c for ia in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Thu Mar  5 13:31:46 2015 moran-_d
** Last update Sat Mar  7 19:07:52 2015 moran-_d
*/

#include <stdio.h>
#include "lemipc.h"
#include "ia.h"

void check_mailbox(shared_t *shared, player_t *player)
{
  msg_t msg;
  long id;

  id = player->x;
  id = id << sizeof(int);
  id += player->y;
  while (msgrcv(shared->msg_id, &msg, MSG_SIZE, id, IPC_NOWAIT) != -1)
    {
      id = id;
    }
}

int exec_turn(shared_t *shared, player_t *player)
{
  struct sembuf sops;
  int ret;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  printf("Player from team %d entered the lock\n", player->color);
  sops.sem_op = 1;
  ret = -1;

  check_mailbox(shared, player);

  printf("AFTER CHECKBOX, ENTRY WITH FLAG %d\n", player->flag);
  if (player->flag == 0)
    ret = exec_commoner(shared, player);
  else
    ret = exec_flag(shared, player);

  printf("Player from team %d exited the lock\n", player->color);
  semop(shared->sem_id, &sops, 1);
  return (ret);
}
