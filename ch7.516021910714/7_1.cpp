#include <iostream>

using namespace std;

template <class T>
int binarySearch(T *data, int low, int high, T x)
{
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    if (data[mid] == x)
        return mid;
    if (data[mid] > x)
        return binarySearch(data, low, mid - 1, x);
    else
        return binarySearch(data, mid + 1, high, x);
}

int main()
{
    int data[19] = {0, 1, 5, 9, 89, 102, 109, 156, 256, 451, 566, 622, 635, 768, 854, 862, 997, 998, 999};
    int low = 1, high = 18;
    cout << "The array is: 1, 5, 9, 89, 102, 109, 156, 256, 451, 566, 622, 635, 768, 854, 862, 997, 998, 999" << endl
         << "Please enter the data you are looking for in the array:";
    int num;
    cin >> num;
    cout << "Through BinarySearch, the index for " << num << " is: " << binarySearch(data, low, high, num) << endl;
    if (binarySearch(data, low, high, num) == 0)
        cout << "Displayed as 0 means not found" << endl;
    system("pause");
    return 0;
}