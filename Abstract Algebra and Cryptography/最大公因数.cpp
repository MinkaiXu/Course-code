#include <iostream>

using namespace std;

int biggest(int a, int b);

int main()
{
    int a, b;
    cout << "����������10000���ڵ�����x��y��" << endl;
    cin >> a >> b;
    if (a < 0)
        a = a * (-1);
    if (b < 0)
        b = b * (-1);
    int r = biggest(a, b);
    cout << "x��y����������ǣ�" << r << endl;
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