/*
** ia.h for ia in /home/moran-_d/rendu/PSU_2014_lemipc
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Fri Mar  6 14:40:38 2015 moran-_d
** Last update Sun Mar  8 22:21:21 2015 moran-_d
*/

#ifndef IA_H_
#define IA_H_

int exec_turn(shared_t *shared, player_t *player, int *turn);
int move_toward_objective(shared_t *shared, player_t *player);
int move_to(shared_t *shared, player_t *player, int pos[2]);
int move_safely(shared_t *shared, player_t *player, int pos[2]);
int exec_commoner(shared_t *shared, player_t *player);
int exec_flag(shared_t *shared, player_t *player);

int me_dead(shared_t *shared, player_t *player);
int is_team_alone(shared_t *shared);

/* Move Consequence */
void move_consequence(shared_t *shared, player_t *player);

/* Maths */
int distance(int xa, int ya, int xb, int yb);
void get_pattern(int try[2], int (*pos)[2], int pattern);
void print_map(shared_t *shared);

/* Formation Pattern */
void    get_formation_right(int (*formation)[MAX_PLAYERS][2]);
void    get_formation_left(int (*formation)[MAX_PLAYERS][2]);
void    get_formation_down(int (*formation)[MAX_PLAYERS][2]);
void    get_formation_up(int (*formation)[MAX_PLAYERS][2]);

#endif
