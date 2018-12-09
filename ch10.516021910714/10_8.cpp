#include <iostream>
using namespace std;

template <class T>
inline int getMid(T a[], int x, int y, int z)
//在三个元素中找到中值并返回下标
{
    if (a[x] >= a[y])
        if (a[x] >= a[z])
            return a[y] >= a[z] ? y : z;
        else
            return x;
    else if (a[y] >= a[z])
        return a[x] >= a[z] ? x : z;
    else
        return y;
}

template <class T>
int divide(T a[], int low, int high)
{
    int kk = getMid(a, low, (low + high) / 2, high);
    T k = a[kk];
    a[kk] = a[low];
    a[low] = k;
    //将找到的中值元素和a[low]交换，使得后面代码不用更改
    do
    {
        while (low < high && a[high] >= k)
            high--;
        if (low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while (low < high && a[low] <= k)
            low++;
        if (low < high)
        {
            a[high] = a[low];
            --high;
        }
    } while (low != high);
    a[low] = k;
    return low;
}

template <class T>
void QuickSort(T a[], int low, int high)
{
    if (low >= high)
        return;
    int mid = divide(a, low, high);
    QuickSort(a, low, mid - 1);
    QuickSort(a, mid + 1, high);
}

template <class T>
void QuickSort(T a[], int size)
{
    QuickSort(a, 0, size - 1);
}

int main()
{
    int N;
    cout << "Please input the number of data as well as each data." << endl
         << "For example, the default data is as follows:" << endl
         << "N=12" << endl
         << "data[12] = 16 87 12 54 33 93 45 88 34 66 11 27" << endl
         << "Please input:" << endl
         << "N=";
    cin >> N;
    int a[N];
    cout << "data[" << N << "]=";
    for (int i = 0; i < N; i++)
        cin >> a[i];

    QuickSort<int>(a, N);
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    system("pause");
    return 0;
}