#include <iostream>

using namespace std;

int sum(int n);

int main()
{
    cout << "Please input n(n>=1): ";
    int n;
    cin >> n;
    cout << "The sum (1-2+3-4+...+/-n) is: " << sum(n) << endl;
    system("pause");
    return 0;
}

int sum(int n)
{
    if ((n % 2) == 0)
        return -n / 2;
    else
        return (n + 1) / 2;
}