//Encoding GB2312

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class T>
class List
{
  private:
    struct node //双循环链表的节点类
    {
        T data;            //存放数据元素
        node *prev, *next; //存放直接前驱和直接后继的地址

        node(const T &x, node *p = NULL, node *n = NULL)
        {
            data = x;
            prev = p;
            next = n;
        }
        node()
        {
            prev = NULL;
            next = NULL;
        }
        ~node(){};
    };

    node *head; //头指针

  public:
    List() : head(NULL) {} //创建一个头节点用以初始化双链表
    ~List()
    {
        node *p = head, *q;

        while (p != head)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }

    class MyItr
    {
        friend List;

      private:
        node *cur;

      public:
        MyItr(node *p = NULL) : cur(p) {}

        T &operator*()
        {
            return cur->data;
        }
    }
}