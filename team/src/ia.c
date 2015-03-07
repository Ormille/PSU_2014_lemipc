/*
** ia.c for ia in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Thu Mar  5 13:31:46 2015 moran-_d
** Last update Fri Mar  6 22:11:34 2015 Julie Terranova
*/

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
  // sem turn
  //  check_mailbox(shared, player); // tmp a remettre
  if (player->flag == 0)
    return (exec_commoner(shared, player));
  else
    return (exec_flag(shared, player));
  // endsem turn
}
