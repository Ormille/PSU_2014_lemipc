/*
** move.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:26:53 2015 Julie Terranova
** Last update Wed Mar  4 16:50:28 2015 Julie Terranova
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

int	show_map(int **map, t_sdl *mine)
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

#include <unistd.h>
void    move_picture(int **map, t_sdl *mine, t_ttf sent)
{
  int quit;

  quit = 0;
  apply_surface(0, 0, mine->background, mine->screen);
  while (quit == 0)
    {
      // ici les cases colorées

      sprintf(sent.str, "Not implemented yet");
      if ((sent.msg = TTF_RenderText_Solid(sent.font, sent.str, sent.txtColor))
	  == NULL)
	return;
      apply_surface(250, 50, sent.msg, mine->screen);

      sleep(5);
      // quit = 1 ssi jeu est fini
      quit = 1;
    }
  // atej:
  map = map;
  //
}
