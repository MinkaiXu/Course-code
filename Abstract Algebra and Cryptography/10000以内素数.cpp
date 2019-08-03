#include <iostream>
using namespace std;
int main()
{
    cout << "10000以内的全部素数为：" << endl;
    bool ifp[10000];
    for (int i = 2; i < 10001; i++)
        ifp[i] = 1;
    for (int i = 2; i < 100; i++)
    {
        if(ifp[i] == 0)
        continue;
        for (int j = 2; j * i < 10001; j++)
            ifp[i * j] = 0;
    }
    for (int i = 2; i < 10000; i++)
        if (ifp[i])
            cout << i << endl;
    system("pause");
    return 0;
}