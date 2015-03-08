/*
** lemipc.h for lemipc in /home/terran_j/rendu/PSU_2014_lemipc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Mar  4 11:13:21 2015 Julie Terranova
** Last update Sun Mar  8 19:24:49 2015 moran-_d
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define KEYWORD	"banane-citron"

#define CELL_SIZE	sizeof(int)
#define MAP_X		52
#define MAP_Y		52
#define MAP_SIZE	(CELL_SIZE * CELL_SIZE * MAP_X * MAP_Y)
#define DATA_SIZE	sizeof(int)
#define SHM_SIZE	(MAP_SIZE + DATA_SIZE)

#define GROUPING_TURN	50
#define TURN_TIME	1000

#define MAX_TEAM		12
#define MAX_PLAYERS		12
#define MAX_PLAYER_PLACE_TRY	500
#define GRAPH_TYPE		1337

typedef struct shared_s {
  key_t	key;
  int	shm_id;
  int	sem_id; /* sem 0 == SHM ACCESS -- sem 1 == TURN ACCESS */
  int	msg_id;
  int	(*map)[MAP_Y];
} shared_t;

typedef struct player_s {
  int x;
  int y;
  int regroup;
  int color;
  int flag;
  int objective[3];
} player_t;

typedef struct msg_s {
  long type;
  int val[6];
} msg_t;

#define MSG_SIZE		(sizeof(msg_t) - sizeof(long))

/* GET_SHARED */
shared_t *get_shared();

/* TEAM */
int init_team(shared_t *shared, int nb_players);

/* PLAYER */
int init_player(shared_t *shared, int color, int flag);
int create_player(shared_t *shared, int color);

/* MSG */
int msg_graph(shared_t *shared, player_t *player, int opcode, int xy[2]);

/* ACTION_SCOUT */
int check_entity_in_radius(shared_t *shared, int pos[2], int radius, int color);
int **check_teams_in_radius(shared_t *shared, int pos[2],
                            int radius, int *size);
int search_max_enemy_same_team(shared_t *shared, int pos[2],
                               int radius, int color);
void find_entity(shared_t *shared, int (*get)[2], int pos[2], int color);

#endif
