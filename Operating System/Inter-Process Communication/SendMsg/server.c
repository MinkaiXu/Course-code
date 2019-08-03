#include <stdio.h>
#include "msgcom.h"
int main()
{
    struct msgtype buf;
    int qid;
    if ((qid = msgget(MSGKEY, IPC_CREAT | 0666)) == -1) // return existed message queue
        return (-1);
    while (1)
    {
        msgrcv(qid, &buf, 512, 1, MSG_NOERROR); // receive message
        printf("Server receive a request from process %d\n", buf.text);
        buf.mtype = buf.text;
        msgsnd(qid, &buf, sizeof(int), 0); // send response to client
    }
}
