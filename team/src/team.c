/*
** team.c for team in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 15:54:16 2015 moran-_d
** Last update Wed Mar  4 16:05:03 2015 moran-_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

int check_color(shared_t *shared)
{
  /*                                                                                   
     TODO                                                                              
     semaphore access,                                                                 
     read map and return lowest number not found (if nbr >= 15, no team available      
     && leave                                                                          
  */
  return (1);
}

int init_team(shared_t *shared, int nb_players)
{
  int i;
  int color;

  if ((color = check_color(shared)) < 0)
    return (-1);
  for (i = 1; i < nb_players; i++)
    {
      if ((create_player(shared, color)) == 1)
	return (0);
    }
  create_flagship_player(shared, color);
  return (0);
}
