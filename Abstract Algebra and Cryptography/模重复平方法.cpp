#include <iostream>

using namespace std;

int main()
{
    cout << "���ǽ�����b^n%m��ֵ��" << endl
         << "������������b��n��m��ֵ��" << endl;
    int b, n, m;
    cin >> b >> n >> m;
    int i = n, c = 1, b_2 = b;
    while (i) //��2ȡ�ಢ��2��ֱ����Ϊ0ʱΪֹ
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