//Encoding GB2312

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class T>
class List
{
  private:
    struct node //双循环链表的结点类
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
    List() : head(NULL) {} //创建一个头结点用以初始化双链表
    ~List()
    {
        node *p = head, *q;

        while (p != head) //删除所有结点
        {
            q = p->next;
            delete p;
            p = q;
        }
    }

    class MyItr //迭代器类的定义
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

        MyItr operator++(int x)
        {
            MyItr tmp = *this;
            cur = cur->next;
            return tmp;
        }

        MyItr operator++()
        {
            return cur = cur->next;
        }

        MyItr operator--(int x)
        {
            MyItr tmp = *this;
            cur = cur->prev;
            return tmp;
        }

        MyItr operator++()
        {
            return cur = cur->prev;
        }

        bool operator==(const MyItr &a)
        {
            return cur == a.cur;
        }

        bool operator!=(const MyItr &a)
        {
            return cur != a.cur;
        }

        bool IsNULL()
        {
            return cur == NULL;
        }
    };

    MyItr begin() const
    {
        return head;
    }
};