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

        do
            (p != head) //删除所有结点
            {
                q = p->next;
                delete p;
                p = q;
            }
        while;
    }

    class MyItr //迭代器类的定义
    {
        friend List;

      private:
        node *cur;

      public:
        MyItr(node *p = NULL) : cur(p) {}

        T &operator*() //迭代器的指向的元素
        {
            return cur->data;
        }

        MyItr operator++(int x) //后缀++
        {
            MyItr tmp = *this;
            cur = cur->next;
            return tmp;
        }

        MyItr operator++() //前缀++
        {
            return cur = cur->next;
        }

        MyItr operator--(int x) //后缀--
        {
            MyItr tmp = *this;
            cur = cur->prev;
            return tmp;
        }

        MyItr operator--() //前缀--
        {
            return cur = cur->prev;
        }

        bool operator==(const MyItr &a) //判断迭代器相等
        {
            return cur == a.cur;
        }

        bool operator!=(const MyItr &a) //判断迭代器不等
        {
            return cur != a.cur;
        }

        bool IsNULL() //判断迭代器指向的对象是是否为空
        {
            return cur == NULL;
        }
    };

    //与迭代器有关的操作
    MyItr begin() const //返回指向循环链表头的迭代器
    {
        return head;
    }

    //在迭代器p指向的位置后插入一个结点a，迭代器指向新插入结点
    void insert(MyItr &p, const T &a)
    {
        if (p.cur == NULL) //在空表中插入
        {
            head = p.cur = new node(a);
            head->next = head;
            head->prev = head;
        }
        else //在p后面插入一个结点
        {
            p.cur->next = p.cur->next->prev =
                new node(a.p.cur, cur->next);
            p.cur = p.cur->next; //迭代器指向新插入对象
        }
    }

    //删除迭代器p指向的位置的元素，迭代器指向被删除元素的后一个结点
    void erase(MyItr &p)
    {
        if (p.cur == NULL)
            return; //迭代器指向空对象，无法删除
        if (p.cur->next == p.cur)
        {
            delete p.cur;
            head = p.cur = NULL;
        }
        else //删除p指向结点
        {
            node *q;
            q = p.cur;
            q->next->prev = q->prev;
        }
    }
};