#include <iostream>
#include <math.h> //������ѧ��ʽͷ�ļ�
using namespace std;
int main()
{
    int x;
    bool flag = true;
    cout << "������һ��10000���ڵ�����x��" << endl;
    cin >> x;
    if (x != 1 && x != 0)
    {
        if (x < 0)
            x = x * (-1);
        int y = sqrt(x);
        for (int i = 2; i < y; i++)
        {
            if (x - i * (x / i) == 0)
            {
                cout << "x�Ǻ�����" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "x��������" << endl;
    }
    else
        cout << "x�Ȳ�������Ҳ���Ǻ�����" << endl;
    system("pause");
    return 0;
}