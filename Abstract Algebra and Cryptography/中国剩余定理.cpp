#include <iostream>
#include <cmath>

using namespace std;

int s[3] = {1, 0, 0};
int t[3] = {0, 1, 1};
int qq = 0;

int created(int a, int b); //����ed=1(mod phi_n)�Ľ�d

int main()
{
    cout << "��������Ҫ�����ͬ��ʽ����ͬ��ʽ�ĸ���" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "x=b" << (i + 1) << " (mod m" << (i + 1) << ")" << endl;
    }
    cout << "������";
    for (int i = 0; i < n; i++)
    {
        cout << 'm' << (i + 1);
        if (i != (n - 1))
            cout << ',';
    }
    cout << "��ֵ��";
    int m[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    int mm = 1;
    for (int i = 0; i < n; i++)
    {
        mm *= m[i];
    }
    int M[n], MM[n];
    cout << "x = ";
    for (int i = 0; i < n; i++)
    {
        s[0] = 1;
        s[1] = 0;
        s[2] = 0;
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        qq = 0;
        M[i] = mm / m[i];
        MM[i] = created(M[i], m[i]);
        while (MM[i] < 0)
            MM[i] += m[i];
        while (MM[i] > m[i])
            MM[i] -= m[i];
        cout << M[i] * MM[i] << 'b' << (i + 1);
        if (i == (n-1))
            cout << " (mod " << mm << ')';
        else
            cout << " + ";
    }
    system("pause");
    return 0;
}

int created(int a, int b) //����ax=1(mod b)�Ľ�d
{
    qq = (a / b);
    int r = -qq * b + a;
    if (r == 0)
        return s[2];
    else
    {
        s[2] = s[0] - qq * s[1];
        s[0] = s[1];
        s[1] = s[2];
        t[2] = t[0] - qq * t[1];
        t[0] = t[1];
        t[1] = t[2];
        r = created(b, r);
    }
}