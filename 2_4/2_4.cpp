//Encoding GB2312

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

template <class T>
class List
{
  private:
    struct node //˫ѭ������Ľڵ���
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
    List() : head(NULL) {} //����һ��ͷ�ڵ����Գ�ʼ��˫����
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