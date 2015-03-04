/*
** player.c for player in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 15:58:48 2015 moran-_d
** Last update Wed Mar  4 16:36:48 2015 moran-_d
*/

#include "lemipc.h"

int exec_ia(shared_t *shared, player_t *player)
{
  int quit;

  quit = 0;
  while (! quit)
    {
      exec_turn(shared, player);
    }
}

int create_player(shared_t *shared, int color)
{
  player_t player;
  int pid;

  if ((player.pid = fork()) == -1)
    {
      printf("Fork fail.\n");
      return (-1);
    }
  else if (player.pid > 0)
    return (0);
  player.color = color;
  player.regroup = 1;
  return (exec_ia(shared, &player));
}
