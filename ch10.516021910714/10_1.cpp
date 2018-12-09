#include <iostream>
using namespace std;

template <class T>
int divide(T a[], int low, int high)
{
    T k = a[low];
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

template <class T>
int removeDuplication(T a[], int size)
{
    QuickSort(a, size);
    T *tmp = new T[size];
    tmp[0] = a[0];
    int k = 0;
    for (int i = 1; i < size; i++)
        if (a[i] != a[i - 1])
            tmp[++k] = a[i];
    for (int i = 0; i < k; i++)
        a[i] = tmp[i];
    delete[] tmp;
    return k + 1;
}

int main()
{
    int N;
    cout << "Please input the number of data as well as each data." << endl
         << "For example, the default data is as follows:" << endl
         << "N=14" << endl
         << "data[14] = 16 87 12 54 33 93 45 88 34 66 11 54 54 27" << endl
         << "Please input:" << endl
         << "N=";
    cin >> N;
    int a[N];
    cout << "data[" << N << "]=";
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int newSize = removeDuplication<int>(a, N);
    cout << "After remove-duplication, the rest of data is:" << endl;
    for (int i = 0; i < newSize; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    system("pause");
    return 0;
}