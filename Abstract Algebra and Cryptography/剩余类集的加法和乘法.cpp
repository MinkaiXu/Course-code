#include <iostream>

using namespace std;

int main()
{
    int m;
    cout << "请输入模m：" << endl;
    cin >> m;
    cout << "现在，你可以进行模" << m << "的同余的剩余类集Z/" << m << "Z的加法和乘法运算！" << endl;
    int f;
    int x, y, z;
    while (1)
    {
        cout << "请输入1或2，以选择你想进行的运算：" << endl
             << "1.模" << m << "的同余的剩余类集Z/" << m << "Z的加法运算；2.模" << m << "的同余的剩余类集Z/" << m << "Z的乘法运算。" << endl;
        cin >> f;
        if (f > 2 && f < 1)
        {
            cout << "输入有误，程序结束。" << endl;
            break;
        }
        cout << "请输入两个两个剩余类x，y：" << endl;
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
        cout << "计算结果为剩余类" << z << endl;
        cout << "请输入1或2，以选择你想进行的操作：" << endl
             << "1.进行下一次运算；2.结束运算退出程序。" << endl;
        cin >> f;
        if (f == 1)
            continue;
        else
            break;
    }
    system("pause");
    return 0;
}