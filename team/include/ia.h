/*
** ia.h for ia in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Fri Mar  6 14:40:38 2015 moran-_d
** Last update Sat Mar  7 19:38:29 2015 moran-_d
*/

#ifndef IA_H_
#define IA_H_

int exec_turn(shared_t *shared, player_t *player);
int move_toward_objective(shared_t *shared, player_t *player);
int move_to(shared_t *shared, player_t *player, int pos[2]);
int move_safely(shared_t *shared, player_t *player, int pos[2]);
int exec_commoner(shared_t *shared, player_t *player);
int exec_flag(shared_t *shared, player_t *player);

/* Maths */
int distance(int xa, int ya, int xb, int yb);
void get_pattern(int try[2], int (*pos)[2], int pattern);

#endif
