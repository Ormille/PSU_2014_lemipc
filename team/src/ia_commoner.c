/*
** ia_commoner.c for com in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Thu Mar  5 13:52:54 2015 moran-_d
** Last update Fri Mar  6 16:06:25 2015 moran-_d
*/

#include "lemipc.h"
#include "ia.h"

int exec_commoner(shared_t *shared, player_t *player)
{
  return (move_toward_objective(shared, player));
}
