/*
** action_scout.c for action_scout in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 20:14:08 2015 moran-_d
** Last update Fri Mar  6 15:51:47 2015 moran-_d
*/

#include "lemipc.h"

int check_enemy_in_radius(shared_t *shared, int pos[2], int radius, int color)
{
  int enemies;
  int ymax;
  int xmax;
  int x;
  int y;

  enemies = 0;
  if ((y = pos[1] - radius) < 0)
    y = 0;
  if ((ymax = pos[1] + radius) > MAP_Y)
    ymax = MAP_Y;
  if ((xmax = (x = pos[0]) + radius) > MAP_X)
    xmax = MAP_X;
  while (y <= ymax)
    {
      if ((x = pos[0] - radius - 1) < 0)
	x = -1;
      while (++x <= xmax)
	if (shared->map[x][y] > 0 &&
	    shared->map[x][y] != color)
	  ++enemies;
      ++y;
    }
  return (enemies);
}
