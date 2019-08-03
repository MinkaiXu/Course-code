#include <iostream>

#include <math.h> // 包括数学公式头文件

using namespace std;

void devide(int a);

int main()
{
    int x;
    cout << "请输入一个10000以内的整数x：" << endl;
    cin >> x;
    cout << x << '=';
    devide(x);
    system("pause");
    return 0;
}

void devide(int x)
{
    if (x != 1 && x != 0)
    {
        bool flag = true;
        int y = sqrt(x);
        for (int i = 2; i <= y; i++)
        {
            if (x - i * (x / i) == 0)
            {
                cout << i << '*';
                flag = false;
                devide(x / i);
                break;
            }
        }
        if (flag)
        {
            cout << x << endl;
        }
    }
    else
        cout << x << endl;
}