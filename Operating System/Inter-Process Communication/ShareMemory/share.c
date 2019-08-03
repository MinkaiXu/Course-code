#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ipc.h"

#define SHMKEY 18001  // key for shared memory
#define SIZE 1024     // length of shared mematy
#define SEMKEY1 19001 // key for signal 1
#define SEMKEY2 19002 // key for signal 2

extern int creatsem();
extern void semWait(), semSignal();

int main()
{
    char *segaddr;
    int segid, sid1, sid2;
    pid_t pid;
    FILE *fb;
    int status;
    // create shared memory spcae
    if ((segid = shmget(SHMKEY, SIZE, IPC_CREAT | 0666)) == -1)
        perror("shmget");
    segaddr = shmat(segid, 0, 0); // reflect momory space to process space
    // generate two signals with initial value = 1
    sid1 = creatsem(SEMKEY1);
    sid2 = creatsem(SEMKEY2);
    semWait(sid2); // set sid2 to 0

    if (pid = fork())
    {
        fb = fopen("message", "rb"); // read the file
        while (!feof(fb))
        { 
            // father process
            semWait(sid1); // set sid1 to 0
            memset(segaddr, 0, 1020); // set memory
            fgets(segaddr, 1020, fb); // read
            printf("Parent Send: %s", segaddr); // send a new line
            semSignal(sid2);
            if ((strcmp(segaddr, "That's all. Thank you!\n")) == 0)
            {
                wait(&status); // wait for son process to exit first
                printf("Parent process quited.\n");
                break;
            }
        }
    }
    else
    {
        while (1)
        {
            // son process
            semWait(sid2);
            printf("Son received: %s\n", segaddr); // print the content received
            semSignal(sid1);
            if ((strcmp(segaddr, "That's all. Thank you!\n")) == 0)
            {
                printf("Son process quited.\n");
                break;
            }
        }
    }
}
