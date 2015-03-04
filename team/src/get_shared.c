/*
** get_shared.c for get_shared in /home/moran-_d/rendu/PSU_2014_lemipc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Wed Mar  4 15:27:57 2015 moran-_d
** Last update Wed Mar  4 15:51:18 2015 moran-_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

shared_t *get_shm(shared_t *shared)
{
  shared->shm_id = shmget(shared->key, SHM_SIZE, SHM_R | SHM_W);
  if (shared->shm_id == -1)
    {
      shared->shm_id = shmget(shared->key, SHM_SIZE,
                              IPC_CREAT | SHM_R | SHM_W);
      if (shared->shm_id == -1)
        {
          printf("Error during SHM creation\n");
          free(shared);
          return (NULL);
        }
      /* TODO MEMSET EVERYTHING !!! */
    }
  return (shared);
}

shared_t *get_sem(shared_t *shared)
{
  shared->sem_access = semget(shared->key, 1, SHM_R | SHM_W);
  if (shared->shm_access == -1)
    {
      shared->sem_access = semget(shared->key, 1,
				  IPC_CREAT | SHM_R | SHM_W);
      if (shared->sem_access == -1)
        {
          printf("Error during SEM creation\n");
          free(shared);
          return (NULL);
        }
    }
  shared->sem_turn = semget(shared->key, 2, SHM_R | SHM_W);
  if (shared->sem_turn == -1)
    {
      shared->sem_turn = semget(shared->key, 2,
				IPC_CREAT | SHM_R | SHM_W);
      if (shared->sem_turn == -1)
        {
          printf("Error during SEM creation\n");
          free(shared);
          return (NULL);
        }
    }
  return (shared);  
}

shared_t *get_msg(shared_t *shared)
{
  shared->msg_id = msgget(shared->key, SHM_R | SHM_W);
  if (shared->msg_id == -1)
    {
      shared->msg_id = msgget(shared->key, IPC_CREAT | SHM_R | SHM_W);
      if (shared->msg_id == -1)
        {
          printf("Error during MSG creation\n");
          free(shared);
          return (NULL);
        }
    }
  return (shared);
}

shared_t *get_shared()
{
  shared_t *shared;

  if ((shared = malloc(sizeof(*shared))) == NULL)
    return (NULL);
  shared->key =ftok(KEYWORD, 0);
  if (get_shm(shared) == NULL)
    return (NULL);
  else if (get_sem(shared) == NULL)
    return (NULL);
  else if (get_msg(shared) == NULL)
    return (NULL);
  return (shared);
}
