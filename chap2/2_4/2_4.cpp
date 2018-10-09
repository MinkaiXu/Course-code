//Encoding GBK
//约瑟夫环问题

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int josephus(int n);

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

        do //删除所有结点
        {
            q = p->next;
            delete p;
            p = q;
        } while (p != head);
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
                new node(a, p.cur, p.cur->next);
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
            q->prev->next = q->next;
            p.cur = q->next;
            if (q == head) //删除的是head指向的结点
                head = q->next;
            delete q;
        }
    }

    MyItr search(const T &a) //查找元素a
    {
        node *p = head;

        if (p == NULL) //空表，无法删除
            return NULL;
        do //找到，返回相应迭代器
        {
            if (a == p->data)
                return p;
            p = p->next;
        } while (p != head);
        return NULL; //没找到，返回空迭代器
    }
};

int josephus(int n)
{
    int k;
    List<int> josephus;
    List<int>::MyItr itr;

    //创建约瑟夫环
    for (k = 0, itr = josephus.begin(); k < n; ++k)
        josephus.insert(itr, k);

    //模拟报数过程
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
    fout.open("C:/Users/84566/Desktop/data structure/Data-structure/2_4/output.txt"); //创建一个.txt的文件
    for (int i = 0; i < datalen; i++)                                                 //将变量的值写入文件
        fout << "The last person left for N=" << num[i] << " is person " << jose[i]+1 << endl;
    fout.close(); //关闭文件

    cout << endl
         << "The result of the sum has been saved in file 'output.txt'." << endl;

    system("pause");
    return 0;
}