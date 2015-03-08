/*
** move.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:26:53 2015 Julie Terranova
** Last update Sun Mar  8 15:43:29 2015 moran-_d
*/

#include <unistd.h>
#include "lemisdl.h"
#include "lemipc.h"

void	move(msg_t msg, t_sdl *mine)
{
  destroy(msg, mine);
  pop(msg, mine);
  /*
  clean_surface((int[6]){msg.val[4] * 15, msg.val[5] * 15, 13, 13,
	msg.val[4] * 15, msg.val[5] * 15}, mine->background, mine->screen);
  apply_surface(msg.val[2] * 15, msg.val[3] * 15, mine->tab[msg.val[1]],
		mine->screen);
  */
}

int treat_msg(t_sdl *mine, t_ttf sent, msg_t msg)
{
  if (msg.val[0] == 1)
    {
      pop(msg, mine);
      sprintf(sent.str, "A player from team %d came in game", msg.val[1]);
    }
  else if (msg.val[0] == 2)
    {
      destroy(msg, mine);
      sprintf(sent.str, "A player from team %d just lost", msg.val[1]);
      printf("A player from team %d just lost", msg.val[1]);
    }
  else if (msg.val[0] == 0)
    move(msg, mine);
  else if (msg.val[0] == 666)
    {
      sprintf(sent.str, "Game is over");
      printf("Game Over ! \n");
      return (42);
    }
  send_to_print(sent, mine);
  return (0);
}

int	move_msg(shared_t *shared, t_ttf sent, t_sdl *mine)
{
  msg_t msg;

  while (msgrcv(shared->msg_id, &msg, MSG_SIZE, GRAPH_TYPE, IPC_NOWAIT) != -1)
    if (treat_msg(mine, sent, msg) == 42)
      return (42);
  usleep(TURN_TIME);
  return (0);
}

void	send_to_print(t_ttf sent, t_sdl *mine)
{
  static int msg_nb = 0;

  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  if (msg_nb == 0)
    apply_surface(925, 200, sent.msg, mine->screen);
  if (msg_nb == 1)
    apply_surface(925, 300, sent.msg, mine->screen);
  if (msg_nb == 2)
    apply_surface(925, 400, sent.msg, mine->screen);
  if (msg_nb == 3)
    apply_surface(925, 500, sent.msg, mine->screen);
  if (msg_nb >= 4)
    {
      apply_surface(925, 600, sent.msg, mine->screen);
      msg_nb = -1;
      clean_surface((int[6]){925, 200, 500, 600, 925, 200},
		    mine->background, mine->screen);
    }
  ++msg_nb;
}

void    move_picture(shared_t *shared, int (*map)[MAP_Y], t_sdl *mine)
{
  struct sembuf sops;
  int x;
  int y;

  x = 0;
  y = 0;
  apply_surface(0, 0, mine->background, mine->screen);
  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(shared->sem_id, &sops, 1);
  sops.sem_op = 1;
  shared = shared;
  sops = sops;
  while (y < MAP_Y)
    {
      x = 0;
      while (x < MAP_X)
	{
	  if (map[x][y] != 0)
	    apply_surface(x * 15, y * 15, mine->tab[map[x][y]], mine->screen);
	  x++;
	}
      y++;
    }
  semop(shared->sem_id, &sops, 1);
}
