/*
** draw.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 15:15:36 2015 Julie Terranova
** Last update Wed Mar  4 16:35:49 2015 Julie Terranova
*/

#include "lemisdl.h"

SDL_Surface     *optimize_img(char *file)
{
  SDL_Surface   *first_one;
  SDL_Surface   *opti_one;

  first_one = NULL;
  opti_one = NULL;
  first_one = SDL_LoadBMP(file);
  if (first_one != NULL)
    {
      opti_one = SDL_DisplayFormat(first_one);
      SDL_FreeSurface(first_one);
    }
  return (opti_one);
}

void    apply_surface(int x, int y, SDL_Surface* src, SDL_Surface* dest)
{
  SDL_Rect      offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, dest, &offset);
}

void    init(t_sdl *mine)
{
  mine->background = NULL;
  mine->screen = NULL;
}

int     draw(int **map)
{
  t_sdl mine;

  init(&mine);
  //  XInitThreads();
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return (-1);
  if ((mine.screen = SDL_SetVideoMode(1316, 800, 32, SDL_SWSURFACE)) == NULL)
    return (-1);
  SDL_WM_SetCaption("LemiPC", NULL);

  if ((mine.background = optimize_img("SDL/pictures/background.bmp")) == NULL)
    return (-1);

  if (SDL_Flip(mine.screen) == -1)
    return (-1);
  show_map(map, &mine);

  SDL_FreeSurface(mine.background);
  SDL_Quit();
  return (0);
}
