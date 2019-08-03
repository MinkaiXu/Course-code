#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);
int order(int a, int p);
bool ifsu(int x); //判断是否是素数，是则返回true

int main()
{
    cout << "求模m的所有整数的指数表,请输入m(m为奇素数)的值:";
    int m;
    cin >> m;
    if (ifsu(m) != 1 && m % 2 == 0)
    {
        cout << "m不是奇素数。" << endl
             << endl;
        system("pause");
        return 0;
    }
    for (int i = 1; i < m; i++)
    {
        cout << i << '\t' << order(i, m) << '\t' << '\t';
    }
    system("pause");
    return 0;
}

int order(int a, int p) //计算序列 {μk = a^k mod p} 的最小周期 p(μ) (p为奇素数)
{
    for (int i = 1;; i++)
    {
        if ((p - 1) % i != 0)
            continue;
        else
        {
            if (fastmi(a, i, p) == 1)
            {
                return i;
            }
        }
    }
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