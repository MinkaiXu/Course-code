//Encoding GBK
//�����������

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
        cur->next = head->next; //��ǰ�����뵽ͷ���ĺ���
        head->next = cur;
        cur = cur_next; //��ǰ������
    }
}