//Encoding GBK
//计算后缀表达式的函数

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

bool isOperator(char ch);
int calculate(const string &postfix);

int main()
{
    cout << "Note that: The file storage location in the code needs to be modified!! due to running on different computers."
         << endl
         << "The suffix is in file 'input.txt'." << endl;

    int datalen = 0;
    string s;

    ifstream infile;
    infile.open("C:/Users/84566/Desktop/data structure/Data-structure/chap3/3_4/input.txt");
    getline(infile, s);
    infile.close();

    ofstream fout;
    fout.open("C:/Users/84566/Desktop/data structure/Data-structure/chap3/3_4/output.txt");
    fout << "The result of the suffix: (" << s
         << ") is " << calculate(s) << '.' << endl;
    fout.close(); //关闭文件

    cout << endl
         << "The result of the suffix: (" << s
         << ") has been saved in file 'output.txt'." << endl;

    system("pause");
    return 0;
}

template <class elemType>
class stack
{
  public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual ~stack() {}
};

template <class elemType>
class seqStack : public stack<elemType>
{
  private:
    elemType *data;
    int top_p;
    int maxSize;

    void doubleSpace();

  public:
    seqStack(int initSize = 10)
    {
        data = new elemType[initSize];
        maxSize = initSize;
        top_p = -1;
    }

    ~seqStack() { delete[] data; }

    bool isEmpty() const { return top_p == -1; }

    void push(const elemType &x)
    {
        if (top_p == maxSize - 1)
            doubleSpace();
        data[++top_p] = x;
    }

    elemType pop() { return data[top_p--]; }

    elemType top() const { return data[top_p]; }
};

template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *tmp = data;

    data = new elemType[2 * maxSize];
    for (int i = 0; i < maxSize; ++i)
        data[i] = tmp[i];
    maxSize *= 2;
    delete[] tmp;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')')
        return true;
    else
        return false;
}

int calculate(const string &postfix)
{
    seqStack<int> dataStack;
    int n1, n2, r;

    for (int i = 0; i < postfix.size(); ++i)
    {
        if (postfix[i] == ' ')
            continue;

        if (!isOperator(postfix[i]))
        {
            r = 0;
            while (i < postfix.size() && postfix[i] != ' ')
            {
                r = r * 10 + postfix[i] - '0';
                ++i;
            }
            dataStack.push(r);
            continue;
        }

        n2 = dataStack.pop();
        n1 = dataStack.pop();

        switch (postfix[i])
        {
        case '^':
            r = pow(n1, n2);
            break;
        case '*':
            r = n1 * n2;
            break;
        case '/':
            r = n1 / n2;
            break;
        case '+':
            r = n1 + n2;
            break;
        case '-':
            r = n1 - n2;
            break;
        }

        dataStack.push(r);
    }
    return dataStack.pop();
}
