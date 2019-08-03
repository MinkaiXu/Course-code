#include <stdio.h>
#include <unistd.h>
#include "msgcom.h"
int main()
{
    struct msgtype buf;
    int qid, pid;
    qid = msgget(MSGKEY, IPC_CREAT | 0666); // create a message queue
    buf.mtype = 1;
    buf.text = pid = getpid();                // buf's content
    msgsnd(qid, &buf, sizeof(buf.text), 0);   // send message to server
    // client get blocked when the queue is full
    msgrcv(qid, &buf, 512, pid, MSG_NOERROR); // receive response from server
    printf("Request received a message from server, type is:%ld\n", buf.mtype);
}
