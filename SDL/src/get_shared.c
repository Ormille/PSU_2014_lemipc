/*
** get_shared.c for get_shared in /home/moran-_d/rendu/PSU_2014_lemipc
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Wed Mar  4 15:27:57 2015 moran-_d
** Last update Fri Mar  6 16:39:59 2015 moran-_d
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

shared_t *get_shm(shared_t *shared)
{
  void *addr;

  shared->shm_id = shmget(shared->key, SHM_SIZE, SHM_R | SHM_W);
  if (shared->shm_id == -1)
    {
      printf("Error during SHM recuperation\n");
      free(shared);
      return (NULL);
    }
  if ((addr = shmat(shared->shm_id, NULL, SHM_R)) == NULL)
    return (NULL);
  shared->map = (int (*)[MAP_Y]) addr;
  return (shared);
}

shared_t *get_sem(shared_t *shared)
{
  shared->sem_id = semget(shared->key, 2, SHM_R | SHM_W);
  if (shared->sem_id == -1)
    {
      printf("Error during SEM recuperation\n");
      free(shared);
      return (NULL);
    }
  return (shared);
}

shared_t *get_msg(shared_t *shared)
{
  shared->msg_id = msgget(shared->key, SHM_R | SHM_W);
  if (shared->msg_id == -1)
    {
      printf("Error during MSG recuperation\n");
      free(shared);
      return (NULL);
    }
  return (shared);
}

shared_t *get_shared()
{
  shared_t *shared;

  if ((shared = malloc(sizeof(*shared))) == NULL)
    return (NULL);
  shared->key = ftok(KEYWORD, 0);
  if (get_shm(shared) == NULL)
    return (NULL);
  else if (get_sem(shared) == NULL)
    return (NULL);
  else if (get_msg(shared) == NULL)
    return (NULL);
  return (shared);
}
