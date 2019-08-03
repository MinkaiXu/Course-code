#include <iostream>
#include <math.h> //包括数学公式头文件
using namespace std;
int main()
{
    int x;
    bool flag = true;
    cout << "请输入一个10000以内的整数x：" << endl;
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
                cout << "x是合数。" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "x是素数。" << endl;
    }
    else
        cout << "x既不是素数也不是合数。" << endl;
    system("pause");
    return 0;
}