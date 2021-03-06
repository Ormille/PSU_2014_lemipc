/*
** action_scout.c for action_scout in /home/moran-_d/rendu/PSU_2014_lemipc
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Wed Mar  4 20:14:08 2015 moran-_d
** Last update Sun Mar  8 22:20:55 2015 moran-_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lemipc.h"
#include "ia.h"

/* color > 0 : check for != color */
/* color < 0 : check for == color * -1 */
/* color == 0 : check for every entities */
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

int **pass_by_me(int ***enemies, shared_t *shared, int *size, int xy[2])
{
  if (shared->map[xy[0]][xy[1]] > 0)
  {
    if (((*enemies)[++(*size)] = malloc(sizeof(int) * 3)) == NULL)
      return (NULL);
    (*enemies)[*size][0] = xy[0];
    (*enemies)[*size][1] = xy[1];
    (*enemies)[*size][2] = shared->map[xy[0]][xy[1]];
  }
  return (0);
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
	if ((pass_by_me(&enemies, shared, size, xy)) == NULL)
	  return (NULL);
    }
  return ((int**)enemies);
}

int search_max_enemy_same_team(shared_t *shared, int pos[2],
			       int radius, int color)
{
  int i;
  int max;
  int tmp_max;

  i = 0;
  max = 0;
  while (++i < MAX_TEAM)
    {
      if (i != color)
	if ((tmp_max = check_entity_in_radius(shared, pos,
					      radius, i * -1)) > max)
	  max = tmp_max;
    }
  return (max);
}

/* color > 0 : check for != color */
/* color < 0 : check for == color * -1 */
/* color == 0 : check for every entities */
void find_entity(shared_t *shared, int (*get)[2], int pos[2], int color)
{
  int tmp_dist;
  int dist;
  int x;
  int y;

  y = -1;
  dist = 2147483647;
  (*get)[0] = -1;
  while (++y < MAP_Y && (x = -1) < 0)
    while (++x < MAP_X)
      if (shared->map[x][y] != 0 &&
	  (pos[0] != x || pos[1] != y) &&
	  ((color == 0) ||
	   (color < 0 && shared->map[x][y] == color * -1) ||
	   (color > 0 && shared->map[x][y] != color)))
        if ((tmp_dist = distance(x, y, pos[0], pos[1])) < dist)
	  {
	    dist = tmp_dist;
	    (*get)[0] = x;
	    (*get)[0] = y;
	  }
}

int is_team_alone(shared_t *shared)
{
  int last_col;
  int x;
  int y;

  last_col = 0;
  y = -1;
  while (++y < MAP_Y && (x = -1) < 0)
    while (++x < MAP_X)
      if (shared->map[x][y] != 0 && last_col == 0)
	last_col = shared->map[x][y];
      else if (shared->map[x][y] != 0 && last_col != 0)
	return (-1);
  return (last_col);
}
