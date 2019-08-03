#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);
int order(int a, int p);
bool ifsu(int x); //�ж��Ƿ������������򷵻�true

int main()
{
    cout << "��ģm������������ָ����,������m(mΪ������)��ֵ:";
    int m;
    cin >> m;
    if (ifsu(m) != 1 && m % 2 == 0)
    {
        cout << "m������������" << endl
             << endl;
        system("pause");
        return 0;
    }
    for (int i = 1; i < m; i++)
    {
        cout << i << '\t' << order(i, m) << '\t' << '\t';
    }
    system("pause");
    return 0;
}

int order(int a, int p) //�������� {��k = a^k mod p} ����С���� p(��) (pΪ������)
{
    for (int i = 1;; i++)
    {
        if ((p - 1) % i != 0)
            continue;
        else
        {
            if (fastmi(a, i, p) == 1)
            {
                return i;
            }
        }
    }
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

bool ifsu(int x) //�ж��Ƿ������������򷵻�true
{
    bool flag = true;
    int y = sqrt(x);
    for (int i = 2; i < y; i++)
    {
        if (x - i * (x / i) == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}