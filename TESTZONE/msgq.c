#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TYPE1 1
#define TYPE2 2
#define N 7
#define STEPS 1

typedef struct msg {
  long type;
  int  val;
} MSG;

int main(int argc, char **argv)
{
  int id, msgSize, i, step, rcvType;
  MSG m1, m2;

  /* ARGS */

  if ((argc != 2) ||
      ((strcmp(argv[1], "1")) &&
       (strcmp(argv[1], "2")))) {
    printf("Usage: %s 1|2"); exit(1);
  }

  /* INIT MSGQ */

  if (!strcmp(argv[1], "1")) {
    id = msgget(10000, IPC_CREAT | 0600);
    m1.type = TYPE1; rcvType = TYPE2;
  }

  else {
    id = msgget(10000, 0);
    m1.type = TYPE2; rcvType = TYPE1;
  }

  if (id < 0) {
    perror("The message queue cannot be accessed");
    exit(2);
  }

  /* ECHANGE */

  msgSize = sizeof(MSG) - sizeof(long);

  for (step=1; step<=STEPS; step++) {
    for (i=1; i<=N; i++) {
      m1.val = i + (atoi(argv[1]) - 1) * N;
      msgsnd(id, &m1, msgSize, 0);
      printf("Msg. sent: type=%d, val=%d\n",
	     m1.type, m1.val);
    }

    for (i=1; i<=N + 9; i++) {
      sleep(1);
      msgrcv(id, &m2, msgSize, rcvType, 0);
      printf("Msg. received: type=%d, val=%d\n",
	     m2.type, m2.val);
    }
    sleep(2);
  }

  if (!strcmp(argv[1], "1"))
    msgctl(id, IPC_RMID, 0);
}
