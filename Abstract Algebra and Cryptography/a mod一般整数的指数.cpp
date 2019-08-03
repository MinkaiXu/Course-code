#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "计算序列 {μk = a^k mod m} 的最小周期 p(μ),请输入a,m的值：";
    int a, m;
    cin >> a >> m;
    for (int i = 1;; i++)
    {
        if (fastmi(a, i, m) == 1)
        {
            cout << "p(μ) = " << i << endl;
            break;
        }
    }
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