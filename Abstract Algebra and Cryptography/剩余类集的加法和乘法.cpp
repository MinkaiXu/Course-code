#include <iostream>

using namespace std;

int main()
{
    int m;
    cout << "������ģm��" << endl;
    cin >> m;
    cout << "���ڣ�����Խ���ģ" << m << "��ͬ���ʣ���༯Z/" << m << "Z�ļӷ��ͳ˷����㣡" << endl;
    int f;
    int x, y, z;
    while (1)
    {
        cout << "������1��2����ѡ��������е����㣺" << endl
             << "1.ģ" << m << "��ͬ���ʣ���༯Z/" << m << "Z�ļӷ����㣻2.ģ" << m << "��ͬ���ʣ���༯Z/" << m << "Z�ĳ˷����㡣" << endl;
        cin >> f;
        if (f > 2 && f < 1)
        {
            cout << "�������󣬳��������" << endl;
            break;
        }
        cout << "��������������ʣ����x��y��" << endl;
        cin >> x >> y;
        if (x < 0)
            x = x * (-1);
        if (y < 0)
            y = y * (-1);
        if (f == 1)
        {
            z = x + y;
            z = z - z / m * m;
        }
        else
        {
            z = x * y;
            z = z - z / m * m;
        }
        cout << "������Ϊʣ����" << z << endl;
        cout << "������1��2����ѡ��������еĲ�����" << endl
             << "1.������һ�����㣻2.���������˳�����" << endl;
        cin >> f;
        if (f == 1)
            continue;
        else
            break;
    }
    system("pause");
    return 0;
}