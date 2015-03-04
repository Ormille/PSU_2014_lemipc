/*
** lemipc.h for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:13:21 2015 Julie Terranova
** Last update Wed Mar  4 11:53:27 2015 Julie Terranova
*/

#ifndef LEMISDL_H__
# define LEMISDL_H__

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "X11/Xlib.h"

typedef struct s_sdl
{
  SDL_Surface *background;
  SDL_Surface *screen;
  SDL_Surface *colors;
  struct s_sdl *next;
} t_sdl;

typedef struct s_ttf
{
  SDL_Surface   *msg;
  TTF_Font      *font;
  SDL_Color     txtColor;
  char          *str;
} t_ttf;

#endif
