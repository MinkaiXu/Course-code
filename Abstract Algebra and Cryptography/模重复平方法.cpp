#include <iostream>

using namespace std;

int main()
{
    cout << "我们将计算b^n%m的值，" << endl
         << "请你依次输入b，n，m的值：" << endl;
    int b, n, m;
    cin >> b >> n >> m;
    int i = n, c = 1, b_2 = b;
    while (i) //对2取余并除2，直到商为0时为止
    {
        if (i % 2)
            c = ((c * b_2) % m);
        b_2 = ((b_2 * b_2) % m);
        i /= 2;
    }
    cout << b << '^' << n << '%' << m << '=' << c << endl;
    system("pause");
    return 0;
}