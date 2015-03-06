/*
** draw.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:15:36 2015 Julie Terranova
** Last update Fri Mar  6 15:26:48 2015 Julie Terranova
*/

#include "lemisdl.h"

void    clean_surface(int xy[6], SDL_Surface* src, SDL_Surface* dest)
{
  SDL_Rect      srcrec;
  SDL_Rect      destrec;

  srcrec.x = xy[0];
  srcrec.y = xy[1];
  srcrec.w = xy[2];
  srcrec.h = xy[3];
  destrec.x = xy[4];
  destrec.y = xy[5];
  SDL_BlitSurface(src, &srcrec, dest, &destrec);
}

void    init(t_sdl *mine)
{
  mine->background = NULL;
  mine->screen = NULL;
}

int	init_colors(t_sdl *mine)
{
  int i;

  i = 1;
  mine->tab[i++] = optimize_img("SDL/pictures/rasta.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/japon.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/france.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/darkblue.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/ligthblue.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/purple.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/pink.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/white.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/red.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/orange.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/yellow.bmp");
  mine->tab[i++] = optimize_img("SDL/pictures/green.bmp");
  if (mine->tab[0] == NULL || mine->tab[1] == NULL || mine->tab[2] == NULL ||
      mine->tab[3] == NULL || mine->tab[4] == NULL || mine->tab[5] == NULL ||
      mine->tab[6] == NULL || mine->tab[7] == NULL || mine->tab[8] == NULL ||
      mine->tab[9] == NULL || mine->tab[10] == NULL || mine->tab[11] == NULL ||
      mine->tab[12] == NULL)
    return (-1);
  return (0);
}

int     draw(shared_t *shared, int (*map)[MAP_Y])
{
  t_sdl mine;
  int bool;

  init(&mine);
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  if ((mine.screen = SDL_SetVideoMode(1316, 800, 32, SDL_SWSURFACE)) == NULL)
    return (-1);
  SDL_WM_SetCaption("LemiPC", NULL);
  if ((mine.background = optimize_img("SDL/pictures/background.bmp")) == NULL)
    return (-1);
  if (init_colors(&mine) == -1)
    return (-1);
  if (SDL_Flip(mine.screen) == -1)
    return (-1);
  bool = 0;
  while (bool == 0)
    if ((show_map(shared, map, &mine, bool)) == 42)
      bool = 1;
  SDL_FreeSurface(mine.background);
  SDL_Quit();
  return (0);
}
