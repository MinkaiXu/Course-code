#include <iostream>

using namespace std;

int main()
{
    int m;
    cout << "������ģm��" << endl;
    cin >> m;
    cout << "��������������x��y��" << endl;
    int x, y;
    if (x < 0)
        x = x * (-1);
    if (y < 0)
        y = y * (-1);
    cin >> x >> y;
    if ((x - x / m * m) == (y - y / m * m))
        cout << "����" << x << "��" << y << "ͬ�ࡣ" << endl;
    else
        cout << "����" << x << "��" << y << "��ͬ�ࡣ" << endl;
    system("pause");
    return 0;
}