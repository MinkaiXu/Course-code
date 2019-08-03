#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "求正整数x,y使得x^2+y^2=p，请输入p的值：";
    int p, x, y, m, u, v, xx, yy, i = 0;
    cin >> p;
    x = xx = fastmi(2, (p - 1) / 4, p);
    y = yy = 1;
    m = (pow(x, 2) + pow(y, 2)) / p;
    cout << 'x' << i << '=' << x << ",y" << i << '=' << y << ",m" << i << '=' << m << endl;
    while (m != 1)
    {
        i++;
        u = x % m;
        v = y % m;
        x = (u * xx + v * yy) / m;
        y = (u * yy - v * xx) / m;
        xx = x;
        yy = y;
        m = (pow(x, 2) + pow(y, 2)) / p;
        cout << 'x' << i << '=' << x << ",y" << i << '=' << y << ",m" << i << '=' << m << endl;
    }
    cout << "故正整数x=" << x << ",y=" << y << "使得x^2+y^2=p。";
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