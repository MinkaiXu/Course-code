#include <iostream>
using namespace std;
int main()
{
    int a, b, q, r;
    cout << "��������������a��b��" << endl;
    cin >> a >> b;
    q = a / b;
    r = a - q * b;
   cout << "����ȫ��q=" << q << "������r=" << r << endl;
    if (r == 0)
        cout << "b��������a��" << endl;
    else
        cout << "b����������a��" << endl;
    system("pause");
    return 0;
}