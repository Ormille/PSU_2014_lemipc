/*
** move.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:26:53 2015 Julie Terranova
** Last update Wed Mar  4 20:39:14 2015 Julie Terranova
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
  if ((sent.font = TTF_OpenFont("SDL/pictures/police.ttf", 28)) == NULL)
    return (-1);
  if (SDL_Flip(mine->screen) == -1)
    return (-1);
  if (bool == 0)
    move_picture(map, mine, sent);
  else
    move_msg(shared, sent, mine);
  free(sent.str);
  TTF_CloseFont(sent.font);
  TTF_Quit();
  return (0);
}

void	pop(msg_t msg, t_sdl *mine)
{
  apply_surface(msg.val[2] * 20, msg.val[3] * 20, mine->tab[msg.val[1]], mine->screen);
}

void	move_msg(shared_t *shared, t_ttf sent, t_sdl *mine)
{
  static int msg_nb = 0;
  msg_t msg;

  while (msgrcv(shared->msg_id, &msg, MSG_SIZE, GRAPH_TYPE, IPC_NOWAIT) != -1)
    {
      if (msg.val[0] == 1)
	pop(msg, mine);

      /* msg.val[0];// type de la fonction (1 pop, 2 destroy,  0 move, 666 quitter) */
      /* msg.val[1]; // couleur equipe (pop voire move) */
      /* msg.val[2]; // x ou la couleur doit etre ---> */
      /* msg.val[3]; // y ou la couleur doit etre */
      /* msg.val[4]; // x' --> destroy */
      /* msg.val[5]; // y'---> destroy */

      msg_nb += 1;
    }
  sprintf(sent.str, "Not implemented yet");
  if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
      == NULL)
    return;
  if (msg_nb == 0)
    apply_surface(950, 200, sent.msg, mine->screen);
  if (msg_nb == 1)
    apply_surface(950, 300, sent.msg, mine->screen);
  if (msg_nb == 2)
    apply_surface(950, 400, sent.msg, mine->screen);
  if (msg_nb == 3)
    apply_surface(950, 500, sent.msg, mine->screen);
  if (msg_nb == 4)
    {
      msg_nb = 0;
      // clear tous les msgs
      apply_surface(950, 600, sent.msg, mine->screen);
    }
}

void    move_picture(int (*map)[MAP_Y], t_sdl *mine, t_ttf sent)
{
  int x;
  int y;

  // atej
  sent = sent;
  //

  x = 0;
  y = 0;
  apply_surface(0, 0, mine->background, mine->screen);
  while (y < MAP_Y)
    {
      x = 0;
      while (x < MAP_X)
	{
	  if (map[x][y] != 0)
	    apply_surface(x * 20, y * 20, mine->tab[map[x][y]], mine->screen);
	  x++;
	}
      y++;
    }
}
