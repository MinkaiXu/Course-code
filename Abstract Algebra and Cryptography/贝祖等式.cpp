#include <iostream>

using namespace std;

int s[3] = {1, 0, 0};
int t[3] = {0, 1, 1};
int q = 0;

int biggest(int a, int b);

int main()
{
    int a, b;
    cout << "请输入两个正整数a，b：" << endl;
    cin >> a >> b;
    if (a < 0)
        a = a * (-1);
    if (b < 0)
        b = b * (-1);
    int r = biggest(a, b);
    cout << "s·a + t·b = " << s[2] << "·" << a << " + " << t[2] << "·" << b << " = "
         << "(a,b)"
         << " = " << r << endl;
    system("pause");
    return 0;
}

int biggest(int a, int b)
{
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