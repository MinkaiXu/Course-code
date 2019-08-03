#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int creatsem(key)
    key_t key;
{
     int sid;
     union semun { /* 如sem.h中已定义，则省略 */
          int val;
          struct semid_ds *buf;
          ushort *array;
     } arg;
     if ((sid = semget(key, 1, 0666 | IPC_CREAT)) == -1)
          perror("semget");
     arg.val = 1;
     if (semctl(sid, 0, SETVAL, arg) == -1)
          perror("semctl");
     return (sid);
}

void semcall(sid, op)
     int sid, op;
{
     struct sembuf sb;
     sb.sem_num = 0;
     sb.sem_op = op;
     sb.sem_flg = 0;
     if (semop(sid, &sb, 1) == -1)
          perror("semop");
};

void semWait(sid)
int sid;
{
     // static void semcall();
     semcall(sid, -1);
}

void semSignal(sid)
     int sid;
{
     // static void semcall();
     semcall(sid, 1);
}
