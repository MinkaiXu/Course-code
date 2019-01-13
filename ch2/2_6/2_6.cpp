//Encoding GBK
//单链表的逆置

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

void inverse()
{
    if (head->next == NULL)
        return;

    node *cur = head->next->next;
    node *cur_next;

    head->next->next = NULL;
    while (cur != NULL)
    {
        cur_next = cur->next;
        cur->next = head->next; //当前结点插入到头结点的后面
        head->next = cur;
        cur = cur_next; //当前结点后移
    }
}