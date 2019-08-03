#include <iostream>
#include <math.h>

using namespace std;

int fastmi(int b, int n, int m);
int devide(int x, int *p, int j = 0);
int biggest(int a, int b);
bool ifsu(int x); //�ж��Ƿ������������򷵻�true
int phi(int a);   //����ŷ������ֵ

int main()
{
    cout << "����ģp^����ԭ��,������p��ֵ(pΪ������):";
    int p;
    cin >> p;
    cout << endl;
    if (ifsu(p) != 1 && p % 2 == 0)
    {
        cout << "p������������" << endl
             << endl;
        system("pause");
        return 0;
    }
    int q[100];
    int j = devide((p - 1), q); //����(p-1)�������ֽ�
    int p_q[100];
    int u[2];
    for (int i = 0; i < j; i++)
    {
        p_q[i] = (p - 1) / q[i]; //������Ҫ�����g���ݴη�
        cout << 'q' << (i + 1) << '=' << q[i] << '\t'
             << "(p-1)/q" << (i + 1) << '=' << p_q[i] << endl;
    }
    cout << endl; //�����һ��
    int g;
    for (int i = 2; i < (p - 1); i++) //����ÿ�����Ƿ���Ԫ��
    {
        if (i == pow(sqrt(i), 2))
            continue;
        bool flag = true;
        for (int k = 0; k < j; k++) //����i�ĸ���ָ�����Ƿ��������
        {
            cout << i << '^' << p_q[k] << '=' << fastmi(i, p_q[k], p) << '\t';
            if (fastmi(i, p_q[k], p) == 1)
                flag = false;
        }
        if (flag == true)
        {
            cout << "(mod " << p << ')' << endl
                 << endl
                 << "g=" << i << "��ģp=" << p << "��ԭ����" << endl
                 << endl;
            g = i;
            break;
        }
        else
            cout << endl;
    }
    u[0] = (fastmi(g, p - 1, pow(p, 2)) - 1) / p;
    u[1] = (fastmi(g + p, p - 1, pow(p, 2)) - 1) / p;
    cout << "g^(p+1)=1+" << u[0] << '*' << p << endl
         << "(g+p)^(p+1)=1+" << u[1] << '*' << p << '\t' << "(mod " << p << "^2)" << endl
         << endl;
    if (biggest(u[0], p) == 1 && biggest(u[1], p) == 1)
        cout << "��ˣ�g=" << g << "��g+p=" << g + p << "����ģm=" << p << "^2=" << pow(p, 2)
             << "��ԭ����" << endl
             << endl
             << "��ˣ���d����ģ��(" << p << "^2)=" << phi(pow(p, 2)) << "�ļ�ʣ��ϵʱ,"
             << g << "^d����ģ" << p << "^2������ԭ��." << endl
             << endl;
    /*
    cout << "d����ģp-1=" << (p - 1) << "�ļ�ʣ��ϵ:" << endl;
    int d[100], d_n = 0;
    for (int i = 1; i < (p - 1); i++)
    {
        if (biggest(i, (p - 1)) == 1)
        {
            cout << i << ' ';
            d[d_n] = i;
            d_n++;
        }
    }
    cout << endl
         << "����(p-1)=" << d_n << "����ʱ,g^d����ģ" << p << "������Ԫ��." << endl
         << endl;
    for (int i = 0; i < d_n; i++)
        cout << 'g' << '^' << d[i] << '=' << fastmi(g, d[i], p) << '\t';
    cout << "(mod " << p << ')' << endl
         << endl;
    */
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

int devide(int x, int *p, int j)
{
    bool flag = true;
    int y = sqrt(x);
    for (int i = 2; i <= y; i++)
    {
        if (x % i == 0)
        {
            if (p[j - 1] != i)
            {
                p[j] = i;
                j++;
            }
            flag = false;
            return devide(x / i, p, j);
        }
    }
    if (flag)
    {
        p[j] = x;
        return (j + 1);
    }
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

int phi(int a)
{
    int b = 0, c = 1;
    for (int i = 2; i < a; i++)
    {
        if (biggest(a, i) == 1)
            c += 1;
    }
    return c;
}