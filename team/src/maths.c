/*
** maths.c for maths in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Sat Mar  7 13:22:53 2015 moran-_d
** Last update Sun Mar  8 22:20:00 2015 moran-_d
*/

#include <stdio.h>
#include <math.h>
#include "lemipc.h"

int distance(int xa, int ya, int xb, int yb)
{
  int ret;

  ret = fabs(xa - xb);
  if (fabs(ya - yb) < ret)
    ret = fabs(ya - yb);
  return (ret);
}

void get_pattern(int try[2], int (*pos)[2], int pattern)
{
  if (pattern == 1)
    {
      (*pos)[0] += try[0];
      (*pos)[1] += try[1];
    }
  if (pattern == 2)
    (*pos)[0] += !try[0];
  else if (pattern == 3)
    (*pos)[0] += -1 * try[0];
  else if (pattern == 4)
    {
      (*pos)[0] += try[0];
      (*pos)[1] += !try[1];
    }
  else if (pattern == 5)
    (*pos)[1] += -1 * try[1];
}

void print_map(shared_t *shared)
{
  int x;
  int y;

  y = 0;
  while (y < MAP_Y)
    {
      x = 0;
      while (x < MAP_X)
	{
	  printf("%d ", shared->map[x][y]);
	  ++x;
	}
      printf("<===\n");
      ++y;
    }
}
