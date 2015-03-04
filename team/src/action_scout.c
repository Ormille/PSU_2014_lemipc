/*
** action_scout.c for action_scout in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 20:14:08 2015 moran-_d
** Last update Wed Mar  4 20:34:10 2015 moran-_d
*/

#include "lemipc.h"

int check_enemy_in_radius(shared_t *shared, player_t *player, int radius)
{
  int enemies;
  int ymax;
  int xmax;
  int x;
  int y;

  y = player->y;
  x = player->x;
  enemies = 0;
  if ((y -= radius) < 0)
    y = 0;
  if ((ymax = y + radius) > MAP_Y)
    ymax = MAP_Y;
  if ((xmax = x + radius) > MAP_X)
    xmax = MAP_X;
  while (y < ymax)
    {
      x = player->x;
      if ((x -= radius) < 0)
	x = 0;
      while (x < xmax)
	{
	  if (shared->map[x][y] > 0 &&
	      shared->map[x][y] != player->color)
	    ++enemies;
	  ++x;
	}
      ++y;
    }
  return (enemies);
}
