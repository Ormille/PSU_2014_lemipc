/*
** sdl_base.c for lemipc in /home/terran_j/rendu/PSU_2014_lemipc/SDL/src
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Mar  6 15:25:57 2015 Julie Terranova
** Last update Fri Mar  6 15:26:58 2015 Julie Terranova
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
