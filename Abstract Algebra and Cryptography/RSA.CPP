#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;

int s[3] = {1, 0, 0};
int t[3] = {0, 1, 1};
int qq = 0;

int random14();                  //生成14-bit的大数
bool real14(int x);              //判断是否为素数，是素数则返回true
int createmin(int n);            //生成一个与整数n互质的小奇数
int biggest(int a, int b);       //判断两个数的最大公因数
int created(int e, int phi_n);   //生成ed=1(mod phi_n)的解d
int fastmi(int b, int n, int m); //计算b^n%m的值

int main()
{
    srand((unsigned)time(NULL));
    int p, q, n, phi_n, e, d;
    do
    {
        p = random14();
        q = random14();
        n = p * q;
        phi_n = (p - 1) * (q - 1);
        e = createmin(phi_n);
        d = created(e, phi_n);
        s[0] = 1;
        s[1] = 0;
        s[2] = 0;
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        qq = 0;
    } while ((e * d % phi_n) != 1);
    cout << "公钥P = (" << e << ',' << n << ')' << endl
         << "密钥S = (" << d << ',' << n << ')' << endl
         << endl;
    char m[] = "Mathematical Fundation of Information security + 201405001 + 516021910714";
    cout << "明文m =" << ' ' << m << endl
         << endl;
    int l;
    for (int i = 0;; i++)
    {
        if (m[i] == '\0')
        {
            l = i;
            break;
        }
    }
    int p_m[l + 1];
    cout << "密文P(m) =" << endl;
    for (int i = 0; i <= l; i++)
    {
        p_m[i] = fastmi(m[i], e, n);
        cout << p_m[i] << ' ';
    }
    cout << endl
         << endl;
    char s_p_m[l + 1];
    cout << "解密S(c)= ";
    for (int i = 0; i <= l; i++)
    {
        s_p_m[i] = fastmi(p_m[i], d, n);
        cout << s_p_m[i];
    }
    cout << endl
         << endl;
    system("pause");
    return 0;
}

int random14() //生成14-bit的大数
{
    int c = 1 + pow(2, 14);
    for (int i = 2; i <= 13; i++)
        c += ((rand() % 2) * pow(2, i));
    if (real14(c))
        return c;
    else
        return c = random14();
}

bool real14(int x) //判断是否为素数，是素数则返回true
{
    int flag = true;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if ((x % i) == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int createmin(int n)
{
    for (int i = 3;; i += 2)
        if (biggest(i, n) == 1)
        {
            return i;
            break;
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

int created(int a, int b) //生成ed=1(mod n)的解d
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

int fastmi(int b, int n, int m) //计算b^n%m的值
{
    int i = n;
    long long c = 1, b_2 = b;
    while (i) //对2取余并除2，直到商为0时为止
    {
        if (i % 2)
            c = ((c * b_2) % m);
        b_2 = ((b_2 * b_2) % m);
        i /= 2;
    }
    return c;
}