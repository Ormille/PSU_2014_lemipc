/*
** msg.c for msg in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 19:38:24 2015 moran-_d
** Last update Sun Mar  8 12:30:08 2015 moran-_d
*/

#include <stdio.h>
#include "lemipc.h"

int msg_graph(shared_t *shared, player_t *player, int opcode, int xy[2])
{
  msg_t msg;
  int i;

  i = 0;
  msg.type = GRAPH_TYPE;
  msg.val[i++] = opcode;
  msg.val[i++] = player->color;
  msg.val[i++] = player->x;
  msg.val[i++] = player->y;
  msg.val[i++] = xy[0];
  msg.val[i++] = xy[1];
  if ((i = msgsnd(shared->msg_id, &msg, MSG_SIZE, 0)) < 0)
    printf("Message send to %d failed.\n", GRAPH_TYPE);
  shared = shared;
  msg = msg;
  return (i);
}
