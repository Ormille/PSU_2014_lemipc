/*
** lemipc.h for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:13:21 2015 Julie Terranova
** Last update Wed Mar  4 15:45:51 2015 moran-_d
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

#define KEYWORD	"banane-citron"

#define CELL_SIZE	sizeof(int)
#define MAP_X		15
#define MAP_Y		15
#define DATA_SIZE	sizeof(int)
#define SHM_SIZE	(CELL_SIZE * CELL_SIZE * MAP_X * MAP_Y + DATA_SIZE)

#include "X11/Xlib.h"

typedef struct shared_s {
  key_t	key;
  int	shm_id;
  int	sem_access;
  int	sem_turn;
  int	msg_id;
} shared_t;

#endif
