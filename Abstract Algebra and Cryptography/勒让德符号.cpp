#include <iostream>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "我们将要计算勒让德符号(a/p)，请依次输入输入a和p的值(p为奇素数)：" << endl;
    int a, p;
    cin >> a >> p;
    cout << "(a/p)=";
    if (a % p == 0)
        cout << 0;
    else
        cout << fastmi(a, (p - 1) / 2, p);
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
    while (c > 1)
        c -= m;
    while (c < -1)
        c += m;
    return c;
}