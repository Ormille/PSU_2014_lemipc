/*
** ia_flag.c for flag in /home/moran-_d/rendu/PSU_2014_lemipc/team/src
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Thu Mar  5 14:02:15 2015 moran-_d
** Last update Sun Mar  8 15:21:06 2015 moran-_d
*/

#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"
#include "ia.h"

int	find_player(shared_t *shared, player_t *player, int pair[MAX_PLAYERS][2])
{
  int tmp_dist;
  int dist;
  int nb_players;
  int x;
  int y;

  y = (nb_players = 0) - 1;
  dist = 2147483647;
  while (++y < MAP_Y && (x = -1) < 0)
    while (++x < MAP_X)
      if (shared->map[x][y] == player->color
	  && (x != player->x || y != player->y))
	{
	  pair[nb_players][0] = x;
	  pair[nb_players++][1] = y;
	}
      else if (shared->map[x][y] != 0 && shared->map[x][y] != player->color)
	if ((tmp_dist = distance(player->x, player->y, x, y)) < dist)
	  {
	    dist = tmp_dist;
	    player->objective[0] = x;
	    player->objective[1] = y;
	  }
  return (nb_players);
}

void	get_formation_right(int (*formation)[MAX_PLAYERS][2])
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

void	get_formation_left(int (*formation)[MAX_PLAYERS][2])
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

void	get_formation_down(int (*formation)[MAX_PLAYERS][2])
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

void	get_formation_up(int (*formation)[MAX_PLAYERS][2])
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

void   find_formation(player_t *player, int nb_players, int (*formation)[MAX_PLAYERS][2])
{
  int formation_pattern[MAX_PLAYERS][2];
  int i;

  i = 0;
  if (player->x - player->objective[0] < 0)
    get_formation_right(&formation_pattern);
  else if (player->x - player->objective[0] > 0)
    get_formation_left(&formation_pattern);
  else if (player->y - player->objective[1] < 0)
    get_formation_down(&formation_pattern);
  else if (player->y - player->objective[1] >= 0)
    get_formation_up(&formation_pattern);
  while (i < nb_players)
    {
      (*formation)[i][0] = player->x + formation_pattern[i][0];
      (*formation)[i][1] = player->y + formation_pattern[i][1];
      if ((*formation)[i][0] > MAP_X)
	(*formation)[i][0] = MAP_X;
      else if ((*formation)[i][0] < 0)
	(*formation)[i][0] = 0;
      if ((*formation)[i][1] > MAP_Y)
	(*formation)[i][1] = MAP_Y;
      else if ((*formation)[i][1] < 0)
	(*formation)[i][1] = 0;
      i++;
    }
}

void give_formation(int (*pair)[2][MAX_PLAYERS][2],
		    int formation[MAX_PLAYERS][2], int nb_players)
{
  int tmp_dist;
  int dist;
  int i;
  int k;
  int kperm;

  i = 0;
  while (i < nb_players)
    {
      dist = 2147483647;
      k = 0;
      while (k < nb_players)
	{
	  if (formation[k][0] != -1 &&
	      (tmp_dist = distance((*pair)[0][i][0], (*pair)[0][i][1],
				   formation[k][0], formation[k][1])) < dist)
	    {
	      dist = tmp_dist;
	      (*pair)[1][i][0] = formation[k][0];
	      (*pair)[1][i][1] = formation[k][1];
	      kperm = k;
	    }
	  k++;
	}
      formation[kperm][0] = -1;
      i++;
    }
}

void send_players_formations(shared_t *shared, int pair[2][MAX_PLAYERS][2], int nb_players)
{
  int i;
  msg_t msg;

  i = -1;
  while (++i < nb_players)
    {
      msg.type = pair[0][i][0];
      msg.type = msg.type << sizeof(int);
      msg.type += pair[0][i][1];
      msg.val[0] = 0;
      msg.val[1] = pair[1][i][0];
      msg.val[2] = pair[1][i][1];
      msg.val[3] = 0;
      /*      printf("player %d is in x: %d and y: %d and wanna go to x: %d and y: %d -- Color %d -- Id %ld\n", i, pair[0][i][0], pair[0][i][1], pair[1][i][0], pair[1][i][1], shared->map[pair[0][i][0]][pair[0][i][1]], msg.type); */
      msgsnd(shared->msg_id, &msg, MSG_SIZE, 0);
    }
}

int pair_players_objectives(shared_t *shared, player_t *player)
{
  int pair[2][MAX_PLAYERS][2];
  int formation[MAX_PLAYERS][2];
  int nb_players;

  // memset(pair[0], -1, sizeof(int) * 2 *MAX_PLAYERS);
  nb_players = find_player(shared, player, pair[0]); // recup pos joueurs
  find_formation(player, nb_players, &formation); // definir emplacements ou aller
  give_formation(&pair, formation, nb_players); // donner a chaque joueur sa position

  send_players_formations(shared, pair, nb_players); // pour envoyer les objectifs aux joueurs via msgq

  return (0);
}

int exec_flag(shared_t *shared, player_t *player)
{
  pair_players_objectives(shared, player);
  //  print_map(shared);
  return (0);
}
