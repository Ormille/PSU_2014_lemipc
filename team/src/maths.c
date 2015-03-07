/*
** maths.c for maths in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Sat Mar  7 13:22:53 2015 moran-_d
** Last update Sat Mar  7 13:23:09 2015 moran-_d
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
