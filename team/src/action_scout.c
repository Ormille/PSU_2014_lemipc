/*
** action_scout.c for action_scout in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 20:14:08 2015 moran-_d
** Last update Sat Mar  7 20:04:26 2015 moran-_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lemipc.h"

/* color > 0 : check for != color. color < 0 : check for == color * -1 */
int check_entity_in_radius(shared_t *shared, int pos[2], int radius, int color)
{
  int entities;
  int ymax;
  int xmax;
  int x;
  int y;

  entities = 0;
  if ((y = pos[1] - radius - 1) < 0)
    y = -1;
  if ((ymax = pos[1] + radius) > MAP_Y)
    ymax = MAP_Y;
  if ((xmax = (x = pos[0]) + radius) > MAP_X)
    xmax = MAP_X;
  while (++y <= ymax)
    {
      if ((x = pos[0] - radius - 1) < 0)
	x = -1;
      while (++x <= xmax)
	if (shared->map[x][y] > 0 &&
	    ((color > 0 && shared->map[x][y] != color)
	     || (color < 0 && shared->map[x][y] == color * -1)
	     || (color == 0)))
	  ++entities;
    }
  return (entities);
}

int **check_teams_in_radius(shared_t *shared, int pos[2],
			   int radius, int *size)
{
  int **enemies;
  int xy[2];
  int ymax;
  int xmax;

  *size = -1;
  xmax = sizeof(*enemies) * check_entity_in_radius(shared, pos, radius, 0);
  if (xmax > 0 && (enemies = malloc(xmax)) == NULL)
    return (NULL);
  memset(enemies, 0, xmax);
  if ((xy[1] = pos[1] - radius - 1) < 0)
    xy[1] = -1;
  if ((ymax = pos[1] + radius) > MAP_Y)
    ymax = MAP_Y;
  if ((xmax = (xy[0] = pos[0]) + radius) > MAP_X)
    xmax = MAP_X;
  while (++xy[1] <= ymax)
    {
      if ((xy[0] = pos[0] - radius - 1) < 0)
	xy[0] = -1;
      while (++xy[0] <= xmax)
	if (shared->map[xy[0]][xy[1]] > 0)
	  {
	    if ((enemies[++(*size)] = malloc(sizeof(int) * 3)) == NULL)
	      return (NULL);
	    enemies[*size][0] = xy[0];
	    enemies[*size][1] = xy[1];
	    enemies[*size][2] = shared->map[xy[0]][xy[1]];
	  }
    }
  return ((int**)enemies);
}
