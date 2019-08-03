#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGKEY 2333
struct msgtype
{
    long mtype;
    int text;
};
