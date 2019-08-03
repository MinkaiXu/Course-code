#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);
int devide(int x, int *p, int j = 0);
int biggest(int a, int b);
bool ifsu(int x); //判断是否是素数，是则返回true

int main()
{
    cout << "计算模p的所有原根,请输入p的值(p为奇素数):";
    int p;
    cin >> p;
    cout << endl;
    if (ifsu(p) != 1 && p % 2 == 0)
    {
        cout << "p不是奇素数。" << endl
             << endl;
        system("pause");
        return 0;
    }
    int q[100];
    int j = devide((p - 1), q); //计算(p-1)的因数分解
    int p_q[100];
    for (int i = 0; i < j; i++)
    {
        p_q[i] = (p - 1) / q[i]; //计算需要计算的g的幂次方
        cout << 'q' << (i + 1) << '=' << q[i] << '\t'
             << "(p-1)/q" << (i + 1) << '=' << p_q[i] << endl;
    }
    cout << endl; //输出空一行
    int g;
    for (int i = 2; i < (p - 1); i++) //尝试每个数是否是元根
    {
        if (i == pow(sqrt(i), 2))
            continue;
        bool flag = true;
        for (int k = 0; k < j; k++) //尝试i的各个指数幂是否符合条件
        {
            cout << i << '^' << p_q[k] << '=' << fastmi(i, p_q[k], p) << '\t';
            if (fastmi(i, p_q[k], p) == 1)
                flag = false;
        }
        if (flag == true)
        {
            cout << "(mod " << p << ')' << endl
                 << endl
                 << "g=" << i << "是模p=" << p << "的原根。" << endl
                 << endl;
            g = i;
            break;
        }
        else
            cout << endl;
    }
    cout << "d遍历模p-1=" << (p - 1) << "的简化剩余系:" << endl;
    int d[100], d_n = 0;
    for (int i = 1; i < (p - 1); i++)
    {
        if (biggest(i, (p - 1)) == 1)
        {
            cout << i << ' ';
            d[d_n] = i;
            d_n++;
        }
    }
    cout << endl
         << "共φ(p-1)=" << d_n << "个数时,g^d遍历模" << p << "的所有原根." << endl
         << endl;
    for (int i = 0; i < d_n; i++)
        cout << 'g' << '^' << d[i] << '=' << fastmi(g, d[i], p) << '\t';
    cout << "(mod " << p << ')' << endl
         << endl;
    system("pause");
    return 0;
}

int fastmi(int b, int n, int m) //计算b^n%m的值
{
    int i = n;
    long long c = 1, b_2 = b;
    while (i) //对2取余并除2，直到商为0时为止
    {
        if (i % 2)
            c = ((c * b_2) % m);
        b_2 = ((b_2 * b_2) % m);
        i /= 2;
    }
    return c;
}

int devide(int x, int *p, int j)
{
    bool flag = true;
    int y = sqrt(x);
    for (int i = 2; i <= y; i++)
    {
        if (x % i == 0)
        {
            if (p[j - 1] != i)
            {
                p[j] = i;
                j++;
            }
            flag = false;
            return devide(x / i, p, j);
        }
    }
    if (flag)
    {
        p[j] = x;
        return (j + 1);
    }
}

int biggest(int a, int b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    int r = a - (a / b) * b;
    if (r == 0)
        return b;
    else
    {
        r = biggest(r, b);
    }
}

bool ifsu(int x) //判断是否是素数，是则返回true
{
    bool flag = true;
    int y = sqrt(x);
    for (int i = 2; i < y; i++)
    {
        if (x - i * (x / i) == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}