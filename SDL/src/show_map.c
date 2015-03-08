/*
** show_map.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Mar  6 15:50:11 2015 Julie Terranova
** Last update Sun Mar  8 15:05:01 2015 moran-_d
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

int     show_map(shared_t *shared, int (*map)[MAP_Y], t_sdl *mine, int bool)
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
    {
      move_picture(shared, map, mine);
      bool = 1;
    }
  else
    if ((move_msg(shared, sent, mine)) == 42)
      return (42);
  free(sent.str);
  TTF_CloseFont(sent.font);
  TTF_Quit();
  return (bool);
}

void    pop(msg_t msg, t_sdl *mine)
{
  apply_surface(msg.val[2] * 15, msg.val[3] * 15, mine->tab[msg.val[1]],
                mine->screen);
}

void    destroy(msg_t msg, t_sdl *mine)
{
  clean_surface((int[6]){msg.val[4] * 15, msg.val[5] * 15, 13, 13,
	msg.val[4] * 15, msg.val[5] * 15}, mine->background, mine->screen);
}
