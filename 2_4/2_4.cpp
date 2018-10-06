//Encoding GB2312

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class T>
class List
{
  private:
    struct node //˫ѭ������Ľ����
    {
        T data;            //�������Ԫ��
        node *prev, *next; //���ֱ��ǰ����ֱ�Ӻ�̵ĵ�ַ

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

    node *head; //ͷָ��

  public:
    List() : head(NULL) {} //����һ��ͷ������Գ�ʼ��˫����
    ~List()
    {
        node *p = head, *q;

        while (p != head) //ɾ�����н��
        {
            q = p->next;
            delete p;
            p = q;
        }
    }

    class MyItr //��������Ķ���
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