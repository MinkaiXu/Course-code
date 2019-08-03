#include <iostream>

using namespace std;

int biggest(int a, int b);

int main()
{
    int a = 0;
    cout << "请输入正整数n：" << endl;
    cin >> a;
    int c = 1;
    for (int i = 2; i < a; i++)
    {
        if (biggest(a, i)==1)
            c += 1;
    }
    cout << "φ(" << a << ")=" << c << endl;
    system("pause");
    return 0;
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