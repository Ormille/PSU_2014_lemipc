/*
** lemipc.h for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:13:21 2015 Julie Terranova
** Last update Thu Mar  5 14:00:07 2015 Julie Terranova
*/

#ifndef LEMISDL_H__
# define LEMISDL_H__

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "X11/Xlib.h"
#include "lemipc.h"

typedef struct s_sdl
{
  SDL_Surface *background;
  SDL_Surface *screen;
  SDL_Surface *tab[MAX_TEAM];
} t_sdl;

typedef struct s_ttf
{
  SDL_Surface   *msg;
  TTF_Font      *font;
  SDL_Color     txtColor;
  char          *str;
} t_ttf;

int     draw(shared_t *shared, int (*map)[MAP_Y]);
int     show_map(shared_t *shared, int (*map)[MAP_Y], t_sdl *mine, int bool);
void    move_picture(int (*map)[MAP_Y], t_sdl *mine);
void    apply_surface(int x, int y, SDL_Surface* src, SDL_Surface* dest);
void    move_msg(shared_t *shared, t_ttf sent, t_sdl *mine);
void    clean_surface(int xy[6], SDL_Surface* src, SDL_Surface* dest);

#endif
