#include <iostream>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "���ǽ�Ҫ�������õ·���(a/p)����������������a��p��ֵ(pΪ������)��" << endl;
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