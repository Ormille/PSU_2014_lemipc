/*
** maths.c for maths in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Sat Mar  7 13:22:53 2015 moran-_d
** Last update Sat Mar  7 17:54:37 2015 moran-_d
*/

#include <math.h>

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
  if (pattern == 2)
    (*pos)[0] = !(*pos)[0];
  else if (pattern == 3)
    (*pos)[0] = !(*pos)[0] * -1 * try[0];
  else if (pattern == 4)
    {
      (*pos)[0] = try[0];
      (*pos)[1] = !(*pos)[1];
    }
  else if (pattern == 5)
    (*pos)[1] = !(*pos)[1] * -1 * try[1];
}
