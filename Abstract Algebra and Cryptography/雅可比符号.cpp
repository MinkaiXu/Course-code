#include <iostream>
#include <cmath>

using namespace std;

int fastmi(int b, int n, int m);
int devide(int x, int *p, int j);

int main()
{
    cout << "���ǽ�Ҫ�����ſ˱ȷ���(a/m)����������������a��m��ֵ��" << endl;
    int a, m;
    cin >> a >> m;
    cout << "(a/m)=";
    if (a % m == 0)
        cout << 0;
    else
    {
        int p[100] = {0};
        int p_n = devide(m, p, 0);
        int cont = 1;
        for (int i = 0; i < p_n; i++)
            cont *= fastmi(a, (p[i] - 1) / 2, p[i]);
        cout << cont;
    }
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
    while (c > 1)
        c -= m;
    while (c < -1)
        c += m;
    return c;
}

int devide(int x, int *p, int j)
{
    bool flag = true;
    int y = sqrt(x);
    for (int i = 2; i <= y; i++)
    {
        if (x % i == 0)
        {
            p[j] = i;
            j++;
            flag = false;
            return devide(x / i, p, j);
            break;
        }
    }
    if (flag)
    {
        p[j] = x;
        return (j + 1);
    }
}