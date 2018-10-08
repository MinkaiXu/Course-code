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

        do
            (p != head) //ɾ�����н��
            {
                q = p->next;
                delete p;
                p = q;
            }
        while;
    }

    class MyItr //��������Ķ���
    {
        friend List;

      private:
        node *cur;

      public:
        MyItr(node *p = NULL) : cur(p) {}

        T &operator*() //��������ָ���Ԫ��
        {
            return cur->data;
        }

        MyItr operator++(int x) //��׺++
        {
            MyItr tmp = *this;
            cur = cur->next;
            return tmp;
        }

        MyItr operator++() //ǰ׺++
        {
            return cur = cur->next;
        }

        MyItr operator--(int x) //��׺--
        {
            MyItr tmp = *this;
            cur = cur->prev;
            return tmp;
        }

        MyItr operator--() //ǰ׺--
        {
            return cur = cur->prev;
        }

        bool operator==(const MyItr &a) //�жϵ��������
        {
            return cur == a.cur;
        }

        bool operator!=(const MyItr &a) //�жϵ���������
        {
            return cur != a.cur;
        }

        bool IsNULL() //�жϵ�����ָ��Ķ������Ƿ�Ϊ��
        {
            return cur == NULL;
        }
    };

    //��������йصĲ���
    MyItr begin() const //����ָ��ѭ������ͷ�ĵ�����
    {
        return head;
    }

    //�ڵ�����pָ���λ�ú����һ�����a��������ָ���²�����
    void insert(MyItr &p, const T &a)
    {
        if (p.cur == NULL) //�ڿձ��в���
        {
            head = p.cur = new node(a);
            head->next = head;
            head->prev = head;
        }
        else //��p�������һ�����
        {
            p.cur->next = p.cur->next->prev =
                new node(a.p.cur, cur->next);
            p.cur = p.cur->next; //������ָ���²������
        }
    }

    //ɾ��������pָ���λ�õ�Ԫ�أ�������ָ��ɾ��Ԫ�صĺ�һ�����
    void erase(MyItr &p)
    {
        if (p.cur == NULL)
            return; //������ָ��ն����޷�ɾ��
        if (p.cur->next == p.cur)
        {
            delete p.cur;
            head = p.cur = NULL;
        }
        else //ɾ��pָ����
        {
            node *q;
            q = p.cur;
            q->next->prev = q->prev;
        }
    }
};