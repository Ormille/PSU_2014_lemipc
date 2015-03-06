/*
** ia_commoner.c for com in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Mar  5 13:52:54 2015 moran-_d
** Last update Fri Mar  6 14:45:40 2015 moran-_d
*/

#include "lemipc.h"
#include "ia.h"

int parse_rcv(shared_t *shared, player_t *player)
{
  shared = shared;
  player = player;
  return (0);
}

int exec_commoner(shared_t *shared, player_t *player)
{
  parse_rcv(shared, player);
  if (player->flag == 1)
    return (exec_flag(shared, player));
  return (move_toward_objective(shared, player));
}
