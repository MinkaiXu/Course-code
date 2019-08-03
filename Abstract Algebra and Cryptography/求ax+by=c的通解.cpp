#include <iostream>

using namespace std;

int biggest(int a, int b);

int s[3] = {1, 0, 0};
int t[3] = {0, 1, 1};
int q = 0;

int main()
{
    int a, b, c, x[2];
    cout << "请输入不定方程ax+by=c中的系数a,b,c:";
    cin >> a >> b >> c;
    int r = biggest(a, b);
    if (c % r)
    {
        cout << "无解";
        return 0;
    }
    else
    {
        cout << "x=" << s[2] * c / r << "-t*" << b / r << ",y=" << t[2] * c / r << "+t*" << a / r;
    }
    system("pause");
    return 0;
}

int biggest(int a, int b)
{
    if (a < 0)
        a = a * (-1);
    if (b < 0)
        b = b * (-1);
    q = (a / b);
    int r = -q * b + a;
    if (r == 0)
        return b;
    else
    {
        s[2] = s[0] - q * s[1];
        s[0] = s[1];
        s[1] = s[2];
        t[2] = t[0] - q * t[1];
        t[0] = t[1];
        t[1] = t[2];
        r = biggest(b, r);
    }
}
