#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "�������� {��k = a^k mod p} ����С���� p(��),������a,p(pΪ������)��ֵ��";
    int a, p;
    cin >> a >> p;
    for (int i = 1;; i++)
    {
        if ((p - 1) % i != 0)
            continue;
        else
        {
            if (fastmi(a, i, p) == 1)
            {
                cout << "p(��) = " << i << endl;
                break;
            }
        }
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
    return c;
}