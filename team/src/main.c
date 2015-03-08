/*
** main.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:12:41 2015 Julie Terranova
** Last update Sun Mar  8 22:01:59 2015 moran-_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

void harakiri_winner(shared_t *shared, int **near, int s)
{
  msg_t msg;

  if (near == NULL)
    return;
  while (s >= 0)
    {
      printf("WE HAVE A WINNER\n");
      msg.type = near[s][0];
      msg.type = msg.type << sizeof(int);
      msg.type += near[s][1];
      msg.val[0] = 2;
      msgsnd(shared->msg_id, &msg, MSG_SIZE, IPC_NOWAIT);
      --s;
    }
}

void clean_all(shared_t *shared, int winner)
{
  int **near;
  msg_t msg;
  int s;

  msg.type = GRAPH_TYPE;
  near = check_teams_in_radius(shared, (int[2]){0, 0}, MAP_X, &s);
  harakiri_winner(shared, near, s);
  if (near != NULL)
    free(near);
  sleep(1);
  msg.val[0] = 666;
  msg.val[1] = winner - 5;
  msgsnd(shared->msg_id, &msg, MSG_SIZE, IPC_NOWAIT);
  sleep(1);
  shmctl(shared->shm_id, IPC_RMID, NULL);
  semctl(shared->msg_id, 2, IPC_RMID);
  msgctl(shared->sem_id, IPC_RMID, NULL);
}

int	main(int argc, char **argv)
{
  shared_t *shared;
  int nb_players;

  if (argc < 2)
    nb_players = MAX_PLAYERS;
  else if (argc > 2)
    {
      printf("Usage : %s [nb_players]\n", argv[0]);
      return (-1);
    }
  else
    if ((nb_players = atoi(argv[1])) < 0 || nb_players > MAX_PLAYERS)
      nb_players = MAX_PLAYERS;
  if ((shared = get_shared()) == NULL)
    return (-1);
  if ((nb_players = init_team(shared, nb_players)) > 1)
    clean_all(shared, nb_players);
  free(shared);
  return (0);
}
