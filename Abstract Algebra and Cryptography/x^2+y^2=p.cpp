#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "��������x,yʹ��x^2+y^2=p��������p��ֵ��";
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
    cout << "��������x=" << x << ",y=" << y << "ʹ��x^2+y^2=p��";
    system("pause");
    return 0;
}

int fastmi(int b, int n, int m) //����b^n%m��ֵ
{
    int i = n;
    long long c = 1, b_2 = b;
    while (i) //��2ȡ�ಢ��2��ֱ����Ϊ0ʱΪֹ
    {
        if (i % 2)
            c = ((c * b_2) % m);
        b_2 = ((b_2 * b_2) % m);
        i /= 2;
    }
    return c;
}