//Encoding GBK
//Լɪ������

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int josephus(int n);

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

        do //ɾ�����н��
        {
            q = p->next;
            delete p;
            p = q;
        } while (p != head);
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
                new node(a, p.cur, p.cur->next);
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
            q->prev->next = q->next;
            p.cur = q->next;
            if (q == head) //ɾ������headָ��Ľ��
                head = q->next;
            delete q;
        }
    }

    MyItr search(const T &a) //����Ԫ��a
    {
        node *p = head;

        if (p == NULL) //�ձ��޷�ɾ��
            return NULL;
        do //�ҵ���������Ӧ������
        {
            if (a == p->data)
                return p;
            p = p->next;
        } while (p != head);
        return NULL; //û�ҵ������ؿյ�����
    }
};

int josephus(int n)
{
    int k;
    List<int> josephus;
    List<int>::MyItr itr;

    //����Լɪ��
    for (k = 0, itr = josephus.begin(); k < n; ++k)
        josephus.insert(itr, k);

    //ģ�ⱨ������
    for (itr = josephus.begin(), k = 1; k < n; ++k)
    {
        ++itr;
        ++itr;
        josephus.erase(itr);
    }

    return *itr;
}

int main()
{
    cout << "Note that: The file storage location in the code needs to be modified!! due to running on different computers."
         << endl
         << "The data set of N is in file 'input.txt'." << endl;

    int datalen = 0;
    int num[100], jose[100];

    ifstream infile;
    infile.open("C:/Users/84566/Desktop/data structure/Data-structure/2_4/input.txt");
    while (!infile.eof())
        infile >> num[datalen++];
    infile.close();

    for (int i = 0; i < datalen; i++)
    {
        jose[i] = josephus(num[i]);
        cout << ". ";
    }

    ofstream fout;
    fout.open("C:/Users/84566/Desktop/data structure/Data-structure/2_4/output.txt"); //����һ��.txt���ļ�
    for (int i = 0; i < datalen; i++)                                                 //��������ֵд���ļ�
        fout << "The last person left for N=" << num[i] << " is person " << jose[i]+1 << endl;
    fout.close(); //�ر��ļ�

    cout << endl
         << "The result of the sum has been saved in file 'output.txt'." << endl;

    system("pause");
    return 0;
}