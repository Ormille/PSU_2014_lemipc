/*
** formation.c for formation in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Sun Mar  8 19:06:25 2015 moran-_d
** Last update Sun Mar  8 19:08:52 2015 moran-_d
*/

#include "lemipc.h"

void    get_formation_right(int (*formation)[MAX_PLAYERS][2])
{
  int i;

  i = 0;
  (*formation)[i][0] = 1;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = 0;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = 0;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = 0;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = 1;
}

void    get_formation_left(int (*formation)[MAX_PLAYERS][2])
{
  int i;

  i = 0;
  (*formation)[i][0] = -1;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = 0;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = 0;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = 0;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = -1;
}

void    get_formation_down(int (*formation)[MAX_PLAYERS][2])
{
  int i;

  i = 0;
  (*formation)[i][0] = 1;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = 0;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = 2;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = 0;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = 0;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = -1;
}

void    get_formation_up(int (*formation)[MAX_PLAYERS][2])
{
  int i;

  i = 0;
  (*formation)[i][0] = -1;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = 0;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = -2;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = -1;
  (*formation)[++i][0] = 2;
  (*formation)[i][1] = 0;
  (*formation)[++i][0] = -2;
  (*formation)[i][1] = 0;
  (*formation)[++i][0] = 1;
  (*formation)[i][1] = 1;
  (*formation)[++i][0] = -1;
  (*formation)[i][1] = 1;
}
