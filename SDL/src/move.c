/*
** move.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:26:53 2015 Julie Terranova
** Last update Wed Mar  4 18:52:23 2015 Julie Terranova
*/

#include "lemisdl.h"

void    init_picture(t_ttf *sent)
{
  sent->font = NULL;
  sent->msg = NULL;
  sent->txtColor.r = 255;
  sent->txtColor.b = 255;
  sent->txtColor.g = 255;
}

int	show_map(int (*map)[MAP_Y], t_sdl *mine)
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
  move_picture(map, mine, sent);
  free(sent.str);
  TTF_CloseFont(sent.font);
  TTF_Quit();
  return (0);
}

void	move_msg(t_ttf sent, t_sdl *mine)
{
  static int msg_nb = 0;

  // si je recois un msg j'incremente
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

#include <unistd.h>
void    move_picture(int (*map)[MAP_Y], t_sdl *mine, t_ttf sent)
{
  apply_surface(0, 0, mine->background, mine->screen);

  // carrés colorés ici en fction de la map:
  // if id player == 1, utiliser x et y recus
  apply_surface(20, 20, mine->rasta, mine->screen);
  // id == 2
  apply_surface(55, 180, mine->japon, mine->screen);
  // id == 3
  apply_surface(500, 300, mine->france, mine->screen);

  move_msg(sent, mine);

  sleep(2);

  // atej:
  map = map;
  //
}
