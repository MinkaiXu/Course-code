#include <iostream>
using namespace std;
int main()
{
    int a, b, q, r;
    cout << "请输入两个整数a，b：" << endl;
    cin >> a >> b;
    q = a / b;
    r = a - q * b;
   cout << "不完全商q=" << q << "，余数r=" << r << endl;
    if (r == 0)
        cout << "b可以整除a。" << endl;
    else
        cout << "b不可以整除a。" << endl;
    system("pause");
    return 0;
}