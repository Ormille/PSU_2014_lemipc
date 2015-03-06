/*
** move.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:26:53 2015 Julie Terranova
** Last update Fri Mar  6 15:46:13 2015 Julie Terranova
*/

#include <unistd.h>
#include "lemisdl.h"
#include "lemipc.h"

void    init_picture(t_ttf *sent)
{
  sent->font = NULL;
  sent->msg = NULL;
  sent->txtColor.r = 255;
  sent->txtColor.b = 255;
  sent->txtColor.g = 255;
}

int	show_map(shared_t *shared, int (*map)[MAP_Y], t_sdl *mine, int bool)
{
  t_ttf sent;

  init_picture(&sent);
  if ((sent.str = malloc(sizeof(*sent.str) * 100)) == NULL)
    return (-1);
  if (TTF_Init() == -1)
    return (-1);
  if ((sent.font = TTF_OpenFont("SDL/pictures/police.ttf", 20)) == NULL)
    return (-1);
  if (SDL_Flip(mine->screen) == -1)
    return (-1);
  if (bool == 0)
    move_picture(map, mine);
  else
    if ((move_msg(shared, sent, mine)) == 42)
      return (42);
  free(sent.str);
  TTF_CloseFont(sent.font);
  TTF_Quit();
  return (0);
}

void	pop(msg_t msg, t_sdl *mine)
{
  apply_surface(msg.val[2] * 15, msg.val[3] * 15, mine->tab[msg.val[1]],
		mine->screen);
}

void	destroy(msg_t msg, t_sdl *mine)
{
   clean_surface((int[6]){msg.val[4], msg.val[5], 13, 13, msg.val[4],
	 msg.val[5]}, mine->background, mine->screen);
}

void	move(msg_t msg, t_sdl *mine)
{
  clean_surface((int[6]){msg.val[4], msg.val[5], 13, 13, msg.val[4],
	msg.val[5]}, mine->background, mine->screen);
  apply_surface(msg.val[2] * 15, msg.val[3] * 15, mine->tab[msg.val[1]],
		mine->screen);
}

int	move_msg(shared_t *shared, t_ttf sent, t_sdl *mine)
{
  static int msg_nb = 0;
  msg_t msg;

  while (msgrcv(shared->msg_id, &msg, MSG_SIZE, GRAPH_TYPE, IPC_NOWAIT) != -1)
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
	}
      else if (msg.val[0] == 0)
	move(msg, mine);
      else if (msg.val[0] == 666)
	{
	  sprintf(sent.str, "Game is over");
	  return (42);
	}
      send_to_print(sent, mine, &msg_nb);
    }
  return (0);
}

void	send_to_print(t_ttf sent, t_sdl *mine, int *msg_nb)
{
  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  if (*msg_nb == 0)
    apply_surface(925, 200, sent.msg, mine->screen);
  if (*msg_nb == 1)
    apply_surface(925, 300, sent.msg, mine->screen);
  if (*msg_nb == 2)
    apply_surface(925, 400, sent.msg, mine->screen);
  if (*msg_nb == 3)
    apply_surface(925, 500, sent.msg, mine->screen);
  if (*msg_nb >= 4)
    {
      apply_surface(925, 600, sent.msg, mine->screen);
      *msg_nb = -1;
      clean_surface((int[6]){925, 200, 500, 600, 925, 200},
		    mine->background, mine->screen);
    }
  *msg_nb += 1;
}

void    move_picture(int (*map)[MAP_Y], t_sdl *mine)
{
  int x;
  int y;

  x = 0;
  y = 0;
  apply_surface(0, 0, mine->background, mine->screen);
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
}
