#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);

int main()
{
    cout << "�������� {��k = a^k mod m} ����С���� p(��),������a,m��ֵ��";
    int a, m;
    cin >> a >> m;
    for (int i = 1;; i++)
    {
        if (fastmi(a, i, m) == 1)
        {
            cout << "p(��) = " << i << endl;
            break;
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