#include <iostream>

using namespace std;

int main()
{
    int m;
    cout << "请输入模m：" << endl;
    cin >> m;
    cout << "请输入两个整数x，y：" << endl;
    int x, y;
    if (x < 0)
        x = x * (-1);
    if (y < 0)
        y = y * (-1);
    cin >> x >> y;
    if ((x - x / m * m) == (y - y / m * m))
        cout << "整数" << x << "和" << y << "同余。" << endl;
    else
        cout << "整数" << x << "和" << y << "不同余。" << endl;
    system("pause");
    return 0;
}